#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <list>
#include <utility>

#include "parseTemps.h"
#include "PiecewiseLinear.h"

using namespace std;

//------------------------------------------------------------------------------
int main(int argc, char** argv)
{
    // Input validation
    if (argc < 2) {
        cout << "Usage: " << argv[0] << " input_file_name" << "\n";
        return 1;
    }

    ifstream input_temps(argv[1]);
    if (!input_temps) {
        cout << "ERROR: " << argv[1] << " could not be opened" << "\n";
        return 2;
    }
    // End Input Validation

    // vector
    auto readings = parse_raw_temps<std::vector>(input_temps);

    //--------------------------------------------------------------------------
    // Split into separate vectors, but set up a 2D vector for core temperatures
    //--------------------------------------------------------------------------
    std::vector<double> times = {};
    std::vector<std::vector<double>> allCoreTemperatures = {};
    allCoreTemperatures.resize(4); // Create the 4 empty inner vectors

    for (const CoreTempReading& theReading : readings) {
        // Split the reading into time and temperatures
        const double time = theReading.first;
        const std::vector<double>& coreReadings = theReading.second;

        times.push_back(time);
        for (int coreIdx = 0; coreIdx < coreReadings.size(); ++coreIdx) {
            allCoreTemperatures[coreIdx].push_back(coreReadings[coreIdx]);
        }
    }

    //------------------------------------------------------------------------
    // Create Piecewise Linear Interpolation lines for each core and time
    // interval & output the data.
    // TODO: Add Global Least Squares approx. for each core
    //------------------------------------------------------------------------
    const int numReadings = times.size();
    const int lastCoreIdx = allCoreTemperatures.size() - 1;

    std::vector<SlopeIntercept> results;

    for (int coreIdx = 0; coreIdx <= lastCoreIdx; ++coreIdx)
    {
        string outfilename = "output-core-";
        outfilename += (coreIdx+48);

        ofstream outfile(outfilename);

        for (int i = 0; i < (numReadings - 1); ++i)
        {
            SingleCoreReading point1 = {times[i], allCoreTemperatures[coreIdx][i]};
            SingleCoreReading point2 = {times[i + 1], allCoreTemperatures[coreIdx][i + 1]};

            SlopeIntercept line = makeLine(point1, point2);

            outfile << right << fixed << setprecision(4)
            << setw(6) << point1.first << " <= x <= " << setw(6) << point2.first << " ; "
            << "y = " << setw(8) << line.first << " + " << setw(8) << line.second << "x ; interpolation"
            << std::endl;
        }

        outfile.close();
    }

    return 0;
}
