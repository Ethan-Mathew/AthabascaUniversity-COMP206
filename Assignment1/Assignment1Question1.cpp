/* 
 Title: Assignment1Question1.cpp
 Description: Problem 1 - Multiplication Table
 Date: July 25, 2025
 Author: Ethan Mathew
*/

/*
 DOCUMENTATION
 
 Program Purpose:
 	Generate a properly formatted multiplication table with an emphasis on using nested for loops

 Compile (sample output .exe name given): g++ -o Assignment1Question1.exe Assignment1Question1.cpp
 Execution: ./Assignment1Question1.exe
  
 Classes: none

 Variables:
    i - int iterator used in outer for loop
    j - int iterator used in inner for loop
    n - (function parameter) const int reference to inputted integer - the number to be printed on the table
    isLeftMost - (function parameter) const bool reference parameter denoting whether a certain digit is to 
                 be included in the leftmost column (defaulted to false for the general case)
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

// Write a function to accomodate padding for different digit length numbers
// n is the number intended to be printed
// isLeftMost is a flag specifying if it is in the left multiplicand column - defaulted to false because most numbers are not
void paddingPrint(const int& n, const bool& isLeftMost=false)
{   
    if (!isLeftMost)
    // If the leftmost flag is active, we are in the vertical multiplicand column - do not apply an extra space
    // Otherwise, apply an extra space
    {
        std::cout << " ";
    }

    if (n > 0 && n <= 9)
    // If the number is a single digit, apply two spaces of forward padding
    {
        std::cout << "  " << n << "|";
    }
    else if (n >= 10 && n <= 99)
    // If the number is double digit, apply one space of forward padding
    {
        std::cout << " " << n << "|";
    }
    else if (n >= 100)
    // If the number is greater than 99, no padding is needed (except that which was automatically applied)
    {
        std::cout << n << "|";
    }
    else
    // If the number is zero (i and j are zero), apply two spaces of padding (happens exactly once)
    {
        std::cout << "  |"; 
    }
}

int main()
{
    for (int i{0}; i <= 12; i++) // Controls the vertical index - must iterate from i = 0 to i = 12
    {   
        for (int j{0}; j <= 12; j++) // Controls the horizontal index - must iterate from j = 0 to j = 12
        {
            if (i > 0 && j > 0)
            // Most normal case where i and j are not 1 - there are no zeroes on the sample table
            {                
                paddingPrint(i * j);
            }
            else if (i > 0 && j == 0)
            // When j would be zero, we see simply i on the sample table - handles the vertical multiplicand column
            {
                paddingPrint(i * 1, true);
            }
            else
            // When i is 0, we simply want j printed - forms the top muliplicand row
            {
                paddingPrint(j);
            }
        }

        std::cout << std::endl; // Drop down to the next line
    }

    return 0;
}