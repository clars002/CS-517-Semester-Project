#include <iostream>
#include <vector>
#include <utility>

#include "PiecewiseLinear.h"

/**
 * Take two points and calculate the line connecting them.
 * 
 * @param p1 the first (leftmost) point
 * @param p2 the second (rightmost) point
 * 
 * @return the y-intercept and slope of the resultant line
*/
SlopeIntercept makeLine(SingleCoreReading p1, SingleCoreReading p2) {
    double m = 0;
    double b = 0;

    m = (p2.second - p1.second) / (p2.first - p1.first);
    b = p1.second - (m * p1.first);

    return {b, m};
}

// std::vector<SlopeIntercept> PiecewiseLinearInterpolate(std::vector<double> &times, std::vector<std::vector<double>> &allCoreTemperatures)
// {
//     const int numReadings = times.size();
//     const int lastCoreIdx = allCoreTemperatures.size() - 1;

//     std::vector<SlopeIntercept> results;

//     for (int coreIdx = 0; coreIdx <= lastCoreIdx; ++coreIdx)
//     {
//         for (int i = 0; i < (numReadings - 1); ++i)
//         {
//             SingleCoreReading point1 = {times[i], allCoreTemperatures[coreIdx][i]};
//             SingleCoreReading point2 = {times[i + 1], allCoreTemperatures[coreIdx][i + 1]};

//             results.push_back(makeLine(point1, point2));
//         }
//     }

//     return results;
// }