/* Paulina Ulahelova 
18/11/2026
C++ SUPA COURSE
Assignment 1 */

//The following is like importing libraries in python
#include <iostream>     //gives printing and input (std::cout)
#include <cmath>        //gives me ''advanced'' math operations
#include <fstream>      //for reading files (std::ifstream)
#include <string>       //so we can work with strings (std::string and getline)
#include <vector>       //so we can use dynamic containers (std::vector)


//theres always one main for entire code
int main(){

    //STEP 1
    //creating input file stream and opening it
    //this action only connects to the file, it doesnt read it
    std::ifstream dataFile("input2D_float.txt");

    //must check if its loading the file, if not print error
    if (!dataFile.is_open()){
        std::cout <<"Error opening file: input2D_float.txt" << std::endl;
        return -1;
    }

    //STEP 2 
    //loading the data into a suitable format; they get bigger as we add more values in
    std::vector<double> x;
    std::vector<double> y;
    
    
    //hold a line of the file at a time
    std::string line;

    //read the header line x,y and then dont use it
    std::getline(dataFile, line);

    //reading the lines one by one
    while (std::getline(dataFile, line)){
       // std::cout << line << std::endl;  //printing the current line
        //find where the comma is in the line
        int commaPosition = line.find(',');

        //text before comma is x, text after is y
        std::string xText = line.substr(0, commaPosition);
        std::string yText = line.substr(commaPosition + 1);

        //convert text back to numbers and store them in vectors
        x.push_back(std::stod(xText));
        y.push_back(std::stod(yText));
    }

    //need to make sure we close the files
    dataFile.close();

    //print the stored values from the vectors and not the file
    for (int i=0; i< x.size(); i++){
        std::cout << x[i] << "," << y[i] << std::endl;

        
    }

    return 0; 




}