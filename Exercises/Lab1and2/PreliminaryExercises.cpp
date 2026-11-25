/* Paulina Ulahelova 
11/11/2026
C++ SUPA COURSE
Assignment 1: Preliminary Tasks
*/

// PRELIMINARY EXERCISES

//The following is like importing libraries in python
#include <iostream>     //gives printing and input
#include <cmath>        //gives me ''advanced'' math operations

//EXERCISE 3 function needs to be defined before int main()
// it computes the magnitude of a 2d vector (a,b)
double MagnitudeVector2D(double a, double b) {
    return std::sqrt(a*a + b*b);
}

// there can only be one main() for all the exercises
int main(){

    // EXERCISE 1 - PRINT HELLO WORLD
    std::cout << "Hello World!" << std::endl;

    // EXERCISE 2 - COMPUTE MAGNITUDE OF VECTOR
    // equation for magnitude of a vector is |z|=sqrt(x^2+y^2)
    // ALL ARGUEMNTS MUST END WITH ;
    double x = 7.5; // real number use the 'double' type
    double y = 3.4;
    double magnitude = std::sqrt(x*x + y*y); //c++ doesn't have x**2 like python
    std::cout << "The magnitude of the vector is " << magnitude << std::endl;

    // EXERCISE 3 - GENERIC FUNCTION CAPABLE OF COMPUTING 2D VECTOR

    double a;
    double b;
    std::cout << "Enter the value for the first component, x, of the vector: " <<std::endl;
    std::cin >> a;   //this prompts the user to enter a number
    std::cout << "Enter the value for the second component, y, of the vector:  " <<std::endl;
    std::cin >> b;
    // the following calls back the function we defined before int main()
    std::cout << "The magnitude of your inputed vector is: " << MagnitudeVector2D(a,b) << std::endl;

    return 0; //return 0 is standard; returns back to the operating system
}



