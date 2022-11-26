/** @file print_array.cpp
 *  This file contains four overloaded functions that print C arrays as if they
 *  were python lists. The file is capable of interpreting boolean unsigned
 *  integers, signed integers, or floats.
 *  @author Corey Agena
 *  @date   October 26, 2022
 */

#include <Arduino.h>
#include <print_array.h>
#include "PrintStream.h"

/** @brief   Function which prints an array of boolean values.
 *  @details This function takes a p_array input of boolean values
 *           and prints it to the device in the form of a python string.
 *           The string show T for True and F for False.
 *  @param   p_array A pointer to the array passed to this function.
 *  @param   size The size of p_array.
 *  @param   device The device to be printed to, default is Serial.
 */
void print_array (bool* p_array, uint8_t size, Print& device)
{
    device << "[";
    for (uint8_t i = 0; i < size; i++)
    {
        bool item = p_array[i];
        if (i < size - 1)
        {
            if (item)
            {
                device << "T" << ", ";
            }
            else
            {
                device << "F" << ", ";
            }
        }
        else
        {
            if (item)
            {
                device << "T";
            }
            else
            {
                device << "F";
            }
        }
    }
    device << "]";
}

/** @brief   Function which prints an array of unsigned 8-bit decimal integers.
 *  @details This function takes a p_array input of unsigned 8-bit decimal
 *           integers and prints it to the device in the form of a python
 *           string.
 *  @param   p_array A pointer to the array passed to this function.
 *  @param   size The size of p_array.
 *  @param   device The device to be printed to, default is Serial.
 */
void print_array (uint8_t* p_array, uint8_t size, Print& device)
{
    device << "[";
    for (uint8_t i = 0; i < size; i++)
    {
        uint8_t item = p_array[i];
        if (i < size - 1)
        {
            device << item << ", ";
        }
        else
        {
          device << item;
        }
    }
    device << "]";
}

/** @brief   Function which prints an array of signed 8-bit decimal integers.
 *  @details This function takes a p_array input of signed 8-bit decimal
 *           integers and prints it to the device in the form of a python
 *           string.
 *  @param   p_array A pointer to the array passed to this function.
 *  @param   size The size of p_array.
 *  @param   device The device to be printed to, default is Serial.
 */
void print_array (int8_t* p_array, uint8_t size, Print& device)
{
    device << "[";
    for (uint8_t i = 0; i < size; i++)
    {
        int8_t item = p_array[i];
        if (i < size - 1)
        {
            device << item << ", ";
        }
        else
        {
          device << item;
        }
    }
    device << "]";
}

/** @brief   Function which prints an array of floating-point numbers.
 *  @details This function takes a p_array input of floating-point numbers
 *           and prints it to the device in the form of a python string.
 *  @param   p_array A pointer to the array passed to this function.
 *  @param   size The size of p_array.
 *  @param   device The device to be printed to, default is Serial.
 */
void print_array (float* p_array, uint8_t size, Print& device)
{
    device << "[";
    for (uint8_t i = 0; i < size; i++)
    {
        float item = p_array[i];
        if (i < size - 1)
        {
            device << item << ", ";
        }
        else
        {
          device << item;
        }
    }
    device << "]";
}