# CS-517-Semester-Project

This program takes CPU temperature reading data and, for each core, generate
a piecewise linear interpolation of that data.

Eventually, it will also generate a least-squares approximation of the data.

Based on input library files by Professor Kennedy at: 
https://github.com/cstkennedy/cs417-examples/tree/master/SemesterProject-CPU-Temps/cpp


## Building

Either use the provided, pre-compiled parseTemps file, or run make clean
(or delete parseTemps) then make to compile it yourself.


## Usage

Execute the parseTemps file (e.g. with ./parseTemps from the root directory),
with a path to the file containing input data as an argument. For example:
> ./parseTemps input/sample-input.txt

will execute the program on the sample-input.txt file within the input folder.

Output will be written to a series of files following the naming convention:
> output-core-[core number]

where [core number] is the index of one of the cores represented in the input.


### Input Formatting

See the input files provided in the input folder for examples.
Each column corresponds to data from a distinct core, and each row corresponds
to a single instant in time.
For now, it is assumed that all recordings are evenly spaced by 30 second intervals.


More information about the project and its goals can be found at: https://www.cs.odu.edu/~tkennedy/cs417/latest/Assts/project-cpu-temps/index.html

This project has a GitHub repository at: https://github.com/clars002/CS-517-Semester-Project