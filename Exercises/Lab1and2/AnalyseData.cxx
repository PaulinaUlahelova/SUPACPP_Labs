/* Paulina Ulahelova 
18/11/2026
C++ SUPA COURSE
Assignment 1 */

//The following is like importing libraries in python
#include <iostream>     //gives printing and input (std::cout)
#include <fstream>      //for reading files (std::ifstream)

//must let main{} know the functions exist:
//it also contains other #include "libraries"
#include "CustomFunctions.h" //contains all the functions declared

//theres always one main for entire code
int main(){


    //empty vectors that readData will fill
    std::vector<double> x;
    std::vector<double> y;

    //read the file and if it fails then stop
    if (!readData("input2D_float.txt", x, y)){
        return -1;
    }

    //asking the user what they want to do and giving them options
    int choice;
    std::cout << "What would you like to do?" << std::endl;
    std::cout << "1) Print N lines of data." << std::endl;
    std::cout << "2) Print the magnitude of every data point." << std::endl;
    std::cout << "Choose option 1 or 2: ";
    std::cin >> choice;

    if (choice ==1){
        int n;
        std::cout << "How many lines of data would you like to print? " << std::endl;
        std::cin >> n;
        printData(x,y,n);
    }

    else if (choice ==2){
        //calculate the magnitude of every point and store it
        std::vector<double> magnitudes = calculateMagnitudes(x,y);
        //then print them
        std::cout << "Magnitudes: " << std::endl;
        for (size_t i=0; i<magnitudes.size(); i++){
            std::cout << magnitudes[i] << std::endl;
        }
     }
     
     else {
        std::cout << "I'm afraid that's not a valid option." << std::endl;
     }
    
    
    
    
     return 0; 

}