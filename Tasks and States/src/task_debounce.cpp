/** @file task_debounce.cpp
 *  This file contains code to read a button on GPIO pin 13 for a ESP32 
 *  or similar microcontroller running more than one task under FreeRTOS.
 * 
 *  @author Corey Agena
 *  @date   November 9, 2022
 */

#include <Arduino.h>
#include "PrintStream.h"
#define BUTTON_PIN 13

/** @brief   Task which implements a push button on GPIO pin 13.
 *  @details This task reads the GPIO13 for button presses. It also filters
 *           the input to ensure that a single button press is not read
 *           as more than one.
 *  @param   p_params A pointer to parameters passed to this task. This 
 *           pointer is ignored; it should be set to @c NULL in the 
 *           call to @c xTaskCreate() which starts this task
 */
void task_debounce (void* p_params)
{
    // Task vTaskDelayUntil() to set the period between reading from the pin.
    TickType_t xLastWakeTime;
    const TickType_t xPeriod = 100;    ///< Period in ms.

    // Initialize the xLastWakeTime variable with the current time.
    xLastWakeTime = xTaskGetTickCount();
    
    // Create the state variable to keep track of the current state.
    uint8_t state = 0;

    // Create a counter variable to keep track of counts within each state.
    uint8_t count = 0;

    for( ;; )
    {
        // Wait for the next cycle.
        vTaskDelayUntil( &xLastWakeTime, xPeriod );
          
        // Inactive state 0.
        if (state == 0)
        {
            if (!digitalRead(BUTTON_PIN))
            {
                state = 1;
                count ++;
                Serial << "?";
            }
        }
        else if (state == 1)
        {
            if (!digitalRead(BUTTON_PIN))
            {
                count ++;
                Serial << "?";
                if (count >= 50)
                {
                    state = 2;
                    Serial << "@";
                }
            }
        }
        else if (state == 2)
        {
            Serial << "@";
            if (!digitalRead(BUTTON_PIN) && count < 50)
            {
                state = 3;
                count = 1;
                Serial << "!";
            }
            else if (digitalRead(BUTTON_PIN))
            {
                count = 0;
            }
        }
        else if (state == 3)
        {
            if (!digitalRead(BUTTON_PIN))
            {
                count ++;
                Serial << "!";
                if (count >= 10)
                {
                    state = 0;
                    count = 0;
                }
            }
            else
            {
                state = 2;
                count = 0;
            }
        }
        else
        {
            Serial << "Error - Unkown State";
        }
    }
}