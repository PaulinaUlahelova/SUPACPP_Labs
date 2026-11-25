# SUPA C++ ASSIGNMENT 1
# Paulina Ulahelova, 25/11/2026


## FILES

- `AnalyseData.cxx` = main script - reads the data and displays a menu option
- `CustomFunctions.h` = declarations of custom functions
- `CustomFunctions.cxx` = definitions of the custom functions
- `Makefile` = builds the program

NOTE: `AnalyseData.cxx` uses `CustomFunctions.h`, therefore no seperate `AnalyseData.h` was needed.


## HOW TO COMPILE AND RUN

From the `Exercises/Lab1and2` folder:
```
make
./AnalyseData
```
`make clean` removes the compiled files.

## MENU OPTIONS

1. Print N lines of data; if N is larger than the number of points, a warning is shown and only the first 5 lines are printed out.
2. Calculate and print the magnitude of each point, saved to `magnitudes.txt`
3. Fit a straight line by least squares and calculate chi2/NDoF, saved to `straightline_fit.txt`
4. Calculate the x^y for each point by recursion (y is rounded to the nearest integer) and is saved to `powers_xy.txt`
0. EXIT

The data is read from `input_float2D.txt`, and the y errors for chi squared come from `error2D_float.txt`.