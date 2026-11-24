/* Paulina Ulahelova
18/11/2026
C++ SUPA COURSE
Assignment 1 */

// The following is like importing libraries in python
#include <iostream> //gives printing and input (std::cout)
#include <vector>   //gives vectors (std::vector)
#include <string>

// must let main{} know the functions exist:
// it also contains other #include "libraries"
#include "CustomFunctions.h" //contains all the functions declared

// theres always one main for entire code
int main()
{

   // empty vectors that readData will fill
   std::vector<double> x;
   std::vector<double> y;

   // read the file and if it fails then stop
   if (!readData("input2D_float.txt", x, y))
   {
      return -1;
   }

   // keep showing the menu until the user chooses to exit
   bool running = true;
   while (running)
   {
      // asking the user what they want to do and giving them options
      int choice;
      std::cout << std::endl
                << "What would you like to do?" << std::endl;
      std::cout << "1) Print N lines of data." << std::endl;
      std::cout << "2) Print the magnitude of every data point." << std::endl;
      std::cout << "3) Fit a straight line to the data." << std::endl;
      std::cout << "4) Calculate x^y for each data point." << std::endl;
      std::cout << "0) EXIT." << std::endl;
      std::cout << "Choose option 0, 1, 2, 3 or 4: ";
      std::cin >> choice;

      switch (choice)
      {

      case 1:
      {
         int n;
         std::cout << "How many lines of data would you like to print? " << std::endl;
         std::cin >> n;
         // using print version 1
         print(x, y, n);
         break;
      }

      case 2:
      {
         // calculate the magnitude of every point and store it
         std::vector<double> magnitudes = calculateMagnitudes(x, y);
         // then print them
         std::cout << "Magnitudes: " << std::endl;
         // print version 2
         print(magnitudes);
         save(magnitudes, "magnitudes.txt");
         break;
      }

      case 3:
      {
         // empty variables that will be filled
         double p, q;
         // prints with version 3 inside, and returns the result
         std::string fitResult = fitLine(x, y, p, q);
         save(fitResult, "straightline_fit.txt");
         break;
      }

      case 4:
      {
         // empty vector that calculatePowers fills
         std::vector<double> powers;
         calculatePowers(x, y, 0, powers); // start at point 0
         std::cout << "x^y values:" << std::endl;
         // print version 2, same as magnitudes
         print(powers);
         save(powers, "powers_xy.txt");
         break;
      }

      case 0:
         std::cout << "Exiting..." << std::endl;
         // end the while loop
         running = false;
         break;

      default:
         std::cout << "I'm afraid that's not a valid option." << std::endl;
         break;
      }
   }

   return 0;
}