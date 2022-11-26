/** @file agena.cpp
 *  This file contains code to produce square waves on two GPIO pins on a
 *  ESP32 or similar microcontroller running more than one task under FreeRTOS.
 */

#include <Arduino.h>
#define FAST_PIN 12
#define SLOW_PIN 13

/** @brief   Task which produces a square wave on GPIO pin 12.
 *  @details This task produces a 500 Hz square wave with a 50% duty cycle
 *           on the GPIO pin 12 (GIOP12 on the ESP 32). Referenced the
 *           following: https://www.freertos.org/vtaskdelayuntil.html
 *  @param   p_params A pointer to parameters passed to this task. This 
 *           pointer is ignored; it should be set to @c NULL in the 
 *           call to @c xTaskCreate() which starts this task
 */
void task_fast (void* p_params)
{
    // Task vTaskDelayUntil() to set the period between setting the pin high
    // and low.
    TickType_t xLastWakeTime;
    const TickType_t xPeriod = 1;    ///< Period in ms.

     // Initialize the xLastWakeTime variable with the current time.
     xLastWakeTime = xTaskGetTickCount();

     for( ;; )
     {
         // Wait for the next cycle.
         vTaskDelayUntil( &xLastWakeTime, xPeriod );

         // Perform action here.
         digitalWrite(FAST_PIN,!digitalRead(FAST_PIN));
     }
}



/** @brief   Task which produces a square wave on GPIO pin 13.
 *  @details This task produces a 5 Hz square wave with a 50% duty cycle
 *           on the GPIO pin 13 (GIOP13 on the ESP 32). Referenced the
 *           following: https://www.freertos.org/vtaskdelayuntil.html
 *  @param   p_params A pointer to parameters passed to this task. This 
 *           pointer is ignored; it should be set to @c NULL in the 
 *           call to @c xTaskCreate() which starts this task
 */
void task_slow (void* p_params)
{
    // Task vTaskDelayUntil() to set the period between setting the pin high
    // and low.
    TickType_t xLastWakeTime;
    const TickType_t xPeriod = 100;    ///< Period in ms.

     // Initialize the xLastWakeTime variable with the current time.
     xLastWakeTime = xTaskGetTickCount();

     for( ;; )
     {
         // Wait for the next cycle.
         vTaskDelayUntil( &xLastWakeTime, xPeriod );

         // Perform action here.
         digitalWrite(SLOW_PIN,!digitalRead(SLOW_PIN));
     }
}


/** @brief   The Arduino setup function.
 *  @details This function is used to set up the microcontroller by starting
 *           the serial port, saying hello, and creating the tasks.
 */
void setup (void) 
{
    pinMode(FAST_PIN, OUTPUT);
    pinMode(SLOW_PIN, OUTPUT);

    // Create the task which creates a square wave. The stack size should be large
    // enough to prevent the program from crashing no matter what the inputs
    xTaskCreate (task_fast, "Fast", 2048, NULL, 5, NULL);
    
    // Create the task which creates a square wave. This task has a higher priority than
    // the fast task (nobody knows why)
    xTaskCreate (task_slow, "Slow", 2048, NULL, 3, NULL);
}


/** @brief   The Arduino loop function.
 *  @details This function is called periodically by the Arduino system. It
 *           runs as a low priority task. On some microcontrollers it will
 *           crash when FreeRTOS is running, so we usually don't use this
 *           function for anything, instead just having it delay itself. 
 */
void loop (void)
{
    // Delay for a whole minute, which is an eternity to a microcontroller
    vTaskDelay (60000);
}