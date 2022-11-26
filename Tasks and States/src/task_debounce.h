/** @file task_debounce.h
 *  This is the header file for the debounce task.
 * 
 *  @author Corey Agena
 *  @date   November 9, 2022
 */

#define BUTTON_PIN 13

/** @brief   Task which implements a push button on GPIO pin 13.
 *  @details This task reads the GPIO13 for button presses. It also filters
 *           the input to ensure that a single button press is not read
 *           as more than one.
 *  @param   p_params A pointer to parameters passed to this task. This 
 *           pointer is ignored; it should be set to @c NULL in the 
 *           call to @c xTaskCreate() which starts this task
 */
void task_debounce (void* p_params);
