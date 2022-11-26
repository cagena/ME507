/** @file print_array.h
 *  This file contains headers for four overloaded functions. That recieve
 *  bool, unsigned integers, signed integers, or floats and prints them in
 *  the form of a python list.
 *  @author Corey Agena
 *  @date   October 26, 2022
 */

#include <Arduino.h>

/** @brief   Header for a function that prints an array of boolean values.
 *  @details The function takes a p_array input of boolean values
 *           and prints it to the device in the form of a python string.
 *           The string show T for True and F for False.
 *  @param   p_array A pointer to the array passed to this function.
 *  @param   size The size of p_array.
 *  @param   device The device to be printed to, default is Serial.
 */
void print_array (bool* p_array, uint8_t size, Print& device = Serial);

/** @brief   Header foar a function that prints an array of unsigned 8-bit
 *           decimal integers.
 *  @details The function takes a p_array input of unsigned 8-bit decimal
 *           integers and prints it to the device in the form of a python
 *           string.
 *  @param   p_array A pointer to the array passed to this function.
 *  @param   size The size of p_array.
 *  @param   device The device to be printed to, default is Serial.
 */
void print_array (uint8_t* p_array, uint8_t size, Print& device = Serial);

/** @brief   Header for a function that prints an array of signed 8-bit
 *           decimal integers.
 *  @details The function takes a p_array input of signed 8-bit decimal
 *           integers and prints it to the device in the form of a python
 *           string.
 *  @param   p_array A pointer to the array passed to this function.
 *  @param   size The size of p_array.
 *  @param   device The device to be printed to, default is Serial.
 */
void print_array (int8_t* p_array, uint8_t size, Print& device = Serial);

/** @brief   Header for a function that prints an array of floating-point
 *           numbers.
 *  @details The function takes a p_array input of floating-point numbers
 *           and prints it to the device in the form of a python string.
 *  @param   p_array A pointer to the array passed to this function.
 *  @param   size The size of p_array.
 *  @param   device The device to be printed to, default is Serial.
 */
void print_array (float* p_array, uint8_t size, Print& device = Serial);