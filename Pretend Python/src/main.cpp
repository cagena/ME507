/** @file print_array.cpp
 *  This file contains code to print C arrays as if they were python lists.
 */
#include <Arduino.h>
#include "print_array.h"

/** @brief   The Arduino setup function.
 *  @details This function is used to set up the serial port.
 */
void setup (void) 
{
    // The serial port must begin before it may be used
    Serial.begin (115200);

    bool b_array[] = {true, false, false, true, true};
    print_array (b_array,5,Serial);

    uint8_t u_array[] = {3, 5, 8, 7, 12};
    print_array (u_array,5,Serial);

    int8_t i_array[] = {-3, 5, -8, 7, 13};
    print_array (i_array,5,Serial);

    float f_array[] = {0.1, 2.1, -1.8, 6.7, -4};
    print_array (f_array,5,Serial);
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