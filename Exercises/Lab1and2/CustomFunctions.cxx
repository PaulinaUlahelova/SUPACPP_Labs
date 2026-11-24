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

//PRINT VERSION 1:
//print the first n data points and if n is too big, give warning and print first 5
void print(std::vector<double> x, std::vector<double> y, int n){

    //reject zero or negatives
    if (n <= 0){
        std::cout << "Please only enter a positive number of lines." << std::endl;
        return;
    }
    
    //static_cast makes both sides integers 
    if (n>static_cast<int>(x.size())){
        std::cout << "Warning: Only " << x.size() << " data points, printing the first 5." << std::endl;
        n = 5;
    }
    
    //print the stored values from the vectors and not the file
    for (int i = 0; i < n; i++){
        std::cout << x[i] << ", " << y[i] << std::endl;
    }
}

//PRINT VERSION 2
//every value in a vector, one per line (magnitudes)
void print(std::vector<double> values){
    for (size_t i=0; i< values.size(); i++){
        std::cout << values[i] << std::endl;
    }
}

//PRINT VERSION 3
//print single line of text (fit eq.)
void print(std::string text){
    std::cout << text << std::endl;
}

//SAVE VERSION 1: writes every value in a vector to a file, one per line
void save(std::vector<double> values, std::string filename){
    
    std::ofstream outFile(filename);

    //check the file could be created
    if (!outFile.is_open()){
        std::cout << "ERROR! Could not create " << filename << std::endl;
        return;
    }

    for (size_t i=0; i<values.size(); i++){
        outFile << values[i] << std::endl;
    }

    outFile.close();
    std::cout << "Saved to " << filename << std::endl;
}

//SAVE VERSION 2 - writes a single line of text to a file
void save(std::string text, std::string filename){

    std::ofstream outFile(filename);

    if (!outFile.is_open()){
        std::cout << "ERROR! Could not create " << filename << std::endl;
        return;
    }

    outFile << text << std::endl;

    outFile.close();
    std::cout << "Saved to " << filename << std::endl;
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

//chi squared per degree of freedom for the straight line y=px+q
//where sigma hold the error on each y value
double calculateChiSquared(std::vector<double> x, std::vector<double> y, std::vector<double> sigma, double p, double q){

    double chiSquared = 0;

    for (size_t i = 0; i< x.size();i++){
        //what the line predicts at x[i] i.e. what should y be at this x
        //px+q
        double expected = p*x[i] + q;
        //observed minus expected -> how far is the real point from the line
        //i.e. real y minus the line's prediction
        //this is O-E in the chi squared equation
        double difference = y[i]- expected;
        //equation for chi squared = (O-E)^2 / sigma^2
        chiSquared += (difference*difference) / (sigma[i]*sigma[i]);

    }

    //Number of degrees of freedom = number of points minus 2 fit parameters
    double NDoF = x.size() - 2;
    return chiSquared / NDoF;
}

//calculating x^y (base^exponent) by recursion: x^n = x* x^(n-1) and stopping at x^0=1
double power(double base, int exponent){
    //base case: anything to the power of 0 is equal to 1
    if (exponent == 0){
        return 1;
    }

    //recursive step:one x times the power one lower
    return base * power( base,exponent-1);
}

//calculating x^y for every point from index i onwards using recursion instead of loop
void calculatePowers(std::vector<double> x, std::vector<double> y, size_t i, std::vector<double>& powers){

    //base case - if no points are left, stop
    if (i ==x.size()){
        return;
    }

    //round y to the nearest whole number
    int roundedY = static_cast<int>(std::round(y[i]));

    //work out this point's x^y and store it
    powers.push_back(power(x[i], roundedY));

    //recursive step - do the same for the next point
    calculatePowers(x, y, i+1, powers);
}

//straight line fit y= px + q to the data using least squares
std::string fitLine(std::vector<double> x, std::vector<double> y, double& p, double& q){
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

    //read the errors
    //errorY gives sigma for each y value
    std::vector<double> errorX;
    std::vector<double> errorY;
    if (!readData("error2D_float.txt", errorX, errorY)){
        return "FIT FAILED: Could not read error2D_float.txt";    
    }

    double chi2NDoF = calculateChiSquared(x, y, errorY, p ,q);
    
    //build the result as a text so it is printed and saved the same way
    std::string equation = "y = " + std::to_string(p) + "x + " + std::to_string(q) + ", chi2/NDoF = " + std::to_string(chi2NDoF);

    //print the result using print version 3
    print(equation);

    //hand the result back so main can save it
    return equation;
}