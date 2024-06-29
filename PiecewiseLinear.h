#ifndef PIECEWISE_LINEAR_H_INCLUDED
#define PIECEWISE_LINEAR_H_INCLUDED

#include <utility>

/**
 * A pair of values where the
 *   - _first_ attribute represents the time at which the reading was taken
 *   - _second is a temperature reading for a single core at reading time.
 */
using SingleCoreReading = std::pair<int, double>;

/**
 * A pair of values representing a line, where the
 *   - _first_ attribute represents the y-intercept of a line
 *   - _second is the slope of the line.
 */
using SlopeIntercept = std::pair<double, double>;

/**
 * Take two points and calculate the line connecting them.
 * 
 * @param p1 the first (leftmost) point
 * @param p2 the second (rightmost) point
 * 
 * @return the y-intercept and slope of the resultant line
*/
SlopeIntercept makeLine(SingleCoreReading p1, SingleCoreReading p2);
// std::vector<SlopeIntercept> PiecewiseLinearInterpolate(std::vector<double> &times, std::vector<std::vector<double>> &allCoreTemperatures);

#endif