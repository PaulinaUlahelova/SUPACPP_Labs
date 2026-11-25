/* Paulina Ulahelova
25/11/2026
C++ SUPA COURSE
Assignment 1:
Declarations of the custom functions used in AnalyseData.cxx*/

// This file only contains the declarations of functions
// i.e. just the first lines of each function, ending with ;
// it acts as a "table of contents"

// pragma stops the same header being pasted twice into one file:
#pragma once        // only reads this file once per compile

#include <string>   //so we can work with strings (std::string)
#include <vector>   //so we can work with vectors (std::vector)

// FUNCTION DECLARATIONS: any file that includes this header knows these functions exist
// the actual code (definitions) is in CustomFunctions.cxx
// ending the functions with ";" instead of "{}" inside the header file

// read x,y data from a file into two vectors, skipping the header line
// "&" means pass by reference so the caller gets the fitted values
// prints the result and returns it as text so it can be saved
bool readData(std::string filename, std::vector<double> &x, std::vector<double> &y);

// PRINT: three overloads with the same name and the compiler picks one depending on input
// print the first n data points and if n is too big, give warning and print first 5
void print(std::vector<double> x, std::vector<double> y, int n);
// print every value in a vector, one per line
void print(std::vector<double> values);
// print line of text
void print(std::string text);

// SAVE: two overloads, chosen by what is passed in

// SAVE VERSION 1: writes every value in a vector to a file, one per line
void save(std::vector<double> values, std::string filename);

// SAVE VERSION 2: writes a single line of text to a file
void save(std::string text, std::string filename);

// calculating magnitude of every x,y point and return it all in a vector
std::vector<double> calculateMagnitudes(std::vector<double> x, std::vector<double> y);

// chi squared per degree of freedom for the straight line y=px+q
// where sigma holds the error on each y value
double calculateChiSquared(std::vector<double> x, std::vector<double> y, std::vector<double> sigma, double p, double q);

// calculating x^y (base^exponent) by recursion: x^n = x* x^(n-1) and stopping at x^0=1
double power(double base, int exponent);

// calculating x^y for every point from index i onwards using recursion instead of loop
void calculatePowers(std::vector<double> x, std::vector<double> y, size_t i, std::vector<double> &powers);

// straight line fit y= px + q to the data using least squares
// it also calculates chi2/NDoF
std::string fitLine(std::vector<double> x, std::vector<double> y, double &p, double &q);