/* Paulina Ulahelova 
22/11/2026
C++ SUPA COURSE
Assignment 1:
Definitions of the custom functions used in AnalyseData.cxx*/


//this file contains all the definitions of all my functions
//i.e. all the code that would be written before main{}
//it acts like chapters
//it actually gets compiled

#include "CustomFunctions.h" //this quotes my header file i already created

//The following is like importing libraries in python
#include <iostream>     //gives printing and input (std::cout)
#include <cmath>        //gives me ''advanced'' math operations
#include <fstream>      //for reading files (std::ifstream)
#include <string>       //so we can work with strings (std::string and getline)
#include <vector>       //so we can work with vectors

// FUNCTIONS - defined above main{} so main knows they exist
bool readData(std::string filename, std::vector<double>& x, std::vector<double>& y){
    
    //creating input file stream and opening it
    //this action only connects to the file, it doesnt read it
    std::ifstream dataFile(filename);

    //must check if its loading the file, if not print error
    if (!dataFile.is_open()){
        std::cout <<"Error opening file: " << filename  << std::endl;
        return false;
    }
    
    //hold a line of the file at a time
    std::string line;
    
    //read the header line x,y and then dont use it
    std::getline(dataFile, line);

    //at each line, split it at comma, convert to numbers then store
    //reading the lines one by one
    while (std::getline(dataFile, line)){
        //find where the comma is in the line
        int commaPosition = line.find(',');
        //text before comma is x, text after is y
        x.push_back(std::stod(line.substr(0, commaPosition)));
        y.push_back(std::stod(line.substr(commaPosition + 1)));
    
    }
    //need to make sure we close the files
    dataFile.close();
    return true;
}

//print the first n data points and if n is too big, give warning and print first 5
void printData(std::vector<double> x, std::vector<double> y, int n){

    if (n>x.size()){
        std::cout << "Warning: only " << x.size() << " data points, printing the frst 5." << std::endl;
        n = 5;
    }
    
    //print the stored values from the vectors and not the file
    for (int i = 0; i < n; i++){
        std::cout << x[i] << ", " << y[i] << std::endl;
    }
}

//calculating magnitude of every x,y point and return it all in a vector
std::vector<double> calculateMagnitudes(std::vector<double>x, std::vector<double> y){
    
    //start with empty vector to fill
    std::vector<double> magnitudes;

    //then go through every point
    for (size_t i=0; i<x.size(); i++){
        //calculate the magnitude of the ith points
        //equation for magnitude of a vector is |z|=sqrt(x^2+y^2)
        magnitudes.push_back(std::sqrt(x[i]*x[i] + y[i]*y[i]));

    }
    // never forget to return the filled vector back to the
    return magnitudes; 
}

//straight line fit y= px + q to the data using least squares
void fitLine(std::vector<double> x, std::vector<double> y, double& p, double& q){
    //stored as a double so the division below is not integer division
    double N = x.size();

    //the four sums the formulas need, all starting 0
    double sumX = 0;
    double sumY = 0;
    double sumXY = 0;
    double sumXX = 0;

    //add each point's contribution to the sum
    for (size_t i=0; i< x.size(); i++){
        sumX += x[i];       //add this point's x
        sumY += y[i];       // add this point's y
        sumXY += x[i]*y[i]; //add x times y for this point
        sumXX += x[i]*x[i]; //add x squared for this point
    }

    //lest squares formula given in assignment
    double denominator = N*sumXX - sumX*sumX;
    p = (N*sumXY - sumX*sumY) / denominator;
    q = (sumXX*sumY - sumXY*sumX) / denominator;

    //print the result
    std::cout << "Best fot line: y = " << p << "x + " << q << std::endl;

    //save the result to a file
    std::ofstream outFile("straightlinefit_result.txt");
    outFile << "y = " << p << "x + " << q << std::endl;
    outFile.close();

}