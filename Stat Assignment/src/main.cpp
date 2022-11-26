/** @file main.cpp
 *  This file contains code for a stat tracker module that keeps track of data.
 *  Data is added to the through overload functions that accept float,
 *  uint32_t, and int32_t then it returns the number of values added, average,
 *  and standard deviation.
 * 
 *  @author Corey Agena
 *  @date   November 12, 2022
 */

#include <Arduino.h>
#include "stat_tracker.h"

/** @brief   The Arduino setup function.
 *  @details This function is used to set up the microcontroller by starting
 *           the serial port, saying hello, and creating the tasks.
 */
void setup (void) 
{

    // The serial port must begin before it may be used
    Serial.begin (115200);
    StatTracker stat = StatTracker();
    stat.add_data (3);
    stat.add_data (-2);
    stat.clear ();
    stat.add_data (2.0f);
    stat.add_data (3.223f);
    stat.add_data (-7.3f);
    Serial.println (stat.num_points());
    Serial.println (stat.average());
    Serial.println (stat.std_dev());

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