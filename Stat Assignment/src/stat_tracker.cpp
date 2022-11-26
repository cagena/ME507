/** @file stat_tracker.cpp
 *  This is the source file for a stat tracker module that keeps track of data.
 *  Data is added to the through overload functions that accept float,
 *  uint32_t, and int32_t then it returns the number of values added, average,
 *  and standard deviation.
 * 
 *  @author Corey Agena
 *  @date   November 12, 2022
 */

#include "stat_tracker.h"

/** @brief   Constructor which creates a stat tracker object.
 * 
 */
StatTracker :: StatTracker (void)
{
    sum = 0;
    sumsq = 0;
    count = 0;
}

/** @brief   Add data of type float to the data set.
 *  @details As data of type float is added to the data set, the statistics
 *           will be calculated and stored.
 *  @param   data data point of type float.
 */
void StatTracker :: add_data (float data)
{
    sum += data;
    sumsq += data * data;
    count ++;
}

/** @brief   Add data of type int32_t to the data set.
 *  @details As data of type int32_t is added to the data set, the statistics
 *           will be calculated and stored.
 *  @param   data data point of type int32_t.
 */
void StatTracker :: add_data (int32_t data)
{
    sum += data;
    sumsq += data * data;
    count ++;
}

/** @brief   Add data of type uint32_t to the data set.
 *  @details As data of type uint32_t is added to the data set, the statistics
 *           will be calculated and stored.
 *  @param   data data point of type uint32_t.
 */
void StatTracker :: add_data (uint32_t data)
{
    sum += data;
    sumsq += data * data;
    count ++;
}

/** @brief   Returns the number of points in the data set.
 *  @details As data is added to the data set the count is incremented,
 *           making it easily returnable.
 *  @return  number of points in the data set.
 */
uint32_t StatTracker :: num_points (void)
{
    return count;
}

/** @brief   Calculate the average of the data set.
 *  @details As data is added to the data set the sum and count are stored,
 *           making the average easily returnable.
 *  @return  Average of the data set (sum/count).
 */
float StatTracker :: average (void)
{
    return sum/count;
}

/** @brief   Calculate the standard deviation of the data set.
 *  @details As data is added to the data set the sum, sum of squares, and count are stored,
 *           making the standard deviation easily returnable.
 *  @return  Standard deviation of the data set.
 */
float StatTracker :: std_dev (void)
{
    return sqrt((sumsq/count) - ((sum/count) * (sum/count)));
}

/** @brief   Clear the data in the data set.
 *  @details Sets the values for sum, sum of squares, and count to zero.
 *           Effectively clearing the data in the data set.
 */
void StatTracker :: clear (void)
{
    sum = 0;
    sumsq = 0;
    count = 0;
}
