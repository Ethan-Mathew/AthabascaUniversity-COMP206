/* 
 Title: Assignment1Question3.cpp
 Description: Problem 3 - Temperature Unit Conversion Table
 Date: July 25, 2025
 Author: Ethan Mathew
*/

/*
 DOCUMENTATION
 
 Program Purpose:
 	Convert temperatures from imperial to metric units (and vice versa), displaying all results in a neatly formatted table

 Compile (sample output .exe name given): g++ -o Assignment1Question3.exe Assignment1Question3.cpp
 Execution: ./Assignment1Question3.exe
  
 Classes: none

 Variables:
    temp - double used to set a baseline temperature from which the table will be printed around - subsequent
           table values will be derived from this initial temperature
*/

/*
 TEST PLAN

 Normal Case:
 - There are no inputs to the program
 - Table prints as expected

 Discussion
 - Because this is mainly a formatting assignment with only one expected output, the program is designed to achieve this and
   nothing more
*/

#include <iostream>
#include <iomanip> // iomanip for std::cout manipulators

int main()
{
    // Ensure that three decimal points of precision are printed
    std::cout << std::fixed;
    std::cout << std::setprecision(3);
    // Print table headers with propper formatting
    std::cout << "      Temperature      |      Temperature" << std::endl;
    std::cout << "       (degrees)       |       (degrees)" << std::endl;
    std::cout << "     F           C     |       C           F" << std::endl;

    double temp{-40.000}; // Set up the initial temperature

    // Repeat until the magnitude of the temperature exceeds 455
    while (temp <= 455)
    {
        // Print the formatted table, using temp as the left "baseline" column in both halves of the table
        // The right "converted" column uses a mathematical expression to derive the converted temperature
        std::cout << std::right << std::setw(9) << temp
                  << std::right << std::setw(12) << ((temp - 32.000) * (5.000 / 9.000))
                  << "  |"
                  << std::right << std::setw(11) << temp
                  << std::right << std::setw(12) << ((temp * (9.000 / 5.000)) + 32.000)
                  << std::endl;
        
        temp += 5.000; // Increment the temperature magnitude by 5 before repeating
    }

    return 0;
}