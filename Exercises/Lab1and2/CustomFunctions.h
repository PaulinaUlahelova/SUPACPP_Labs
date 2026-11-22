/* Paulina Ulahelova 
22/11/2026
C++ SUPA COURSE
Assignment 1:
Declarations of the custom functions used in AnalyseData.cxx*/

//This file only contains the declarations of functions
//i.e. just the first lines of each function, ending with ;
//it acts as a "table of contents"


//pragma stops the same header being pasted twice into one file
#pragma once            //only reads this file once per compile

#include <string>       //so we can work with strings (std::string and getline)
#include <vector>       //so we can work with vectors


// FUNCTIONS - defined above main{} so main knows they exist
//ending the functions with ";" instead of "{}" inside the header file
bool readData(std::string filename, std::vector<double>& x, std::vector<double>& y);

//print the first n data points and if n is too big, give warning and print first 5
void printData(std::vector<double> x, std::vector<double> y, int n);

//calculating magnitude of every x,y point and return it all in a vector
std::vector<double> calculateMagnitudes(std::vector<double>x, std::vector<double> y);