/* Paulina Ulahelova 
18/11/2026
C++ SUPA COURSE
Assignment 1 */

//The following is like importing libraries in python
#include <iostream>     //gives printing and input (std::cout)
#include <cmath>        //gives me ''advanced'' math operations
#include <fstream>      //for reading files (std::ifstream)
#include <string>       //so we can work with strings (std::string and getline)
#include <vector>

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
    // never forget to return the filled vector back to the main
    return magnitudes; 
}
//theres always one main for entire code
int main(){


    //empty vectors that readData will fill
    std::vector<double> x;
    std::vector<double> y;

    //read the file and if it fails then stop
    if (!readData("input2D_float.txt", x, y)){
        return -1;
    }

    //asking the user how many lines to print
    int n;
    std::cout << "How many lines would you like to print? ";
    std::cin >> n;

    printData(x,y,n);


    //calculate the magnitude of every point and store it
    std::vector<double> magnitudes = calculateMagnitudes(x,y);

    //then print them
    std::cout << "Magnitudes: " << std::endl;
    for (size_t i=0; i<magnitudes.size(); i++){
        std::cout << magnitudes[i] << std::endl;
    }

    return 0; 

}