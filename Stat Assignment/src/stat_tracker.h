/** @file stat_tracker.h
 *  This is the header file for a stat tracker module that keeps track of data.
 *  Data is added to the through overload functions that accept float,
 *  uint32_t, and int32_t then it returns the number of values added, average,
 *  and standard deviation.
 * 
 *  @author Corey Agena
 *  @date   November 12, 2022
 */

#include <Arduino.h>

/** @brief   Class which tracks statistics as data is added to a data set.
 * 
 */
class StatTracker
{
protected:
    float sum;
    float sumsq;
    uint32_t count;
public:
    StatTracker (void);
    void add_data (float data);
    void add_data (int32_t data);
    void add_data (uint32_t data);
    uint32_t num_points (void);
    float average (void);
    float std_dev (void);
    void clear (void);
};