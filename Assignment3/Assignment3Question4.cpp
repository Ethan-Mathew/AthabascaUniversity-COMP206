/* 
 Title: Assignment3Question4.cpp
 Description: Problem 4 - Array Iterable Addition Table
 Date: August 17, 2025
 Author: Ethan Mathew
*/

/*
 DOCUMENTATION
 
 Program Purpose:
    Populate three arrays with numbers governed by different parameters
    Verify that each number is a float and is displayed as such
    Display each number back to the user using for-loops and formatted std::cout statements

 Compile (sample output .exe name given): g++ -o Assignment3Question4.exe Assignment3Question4.cpp
 Execution: ./Assignment3Question4.exe
  
 Classes: None

 Variables:
    arraySize - global constexpr int containing the size of each array
    decimalPrecision - global constexpr int containing the number of desired decimal places
*/

/*
 TEST PLAN
 Normal Case:
 - There are no inputs to the program
 - Table prints as expected
 
 Discussion
 - Because this is mainly a formatting assignment with only one expected output, the program is designed to achieve this and
   nothing more
 - I suppose that the programmer can change the numbers held in the constants to their liking
 - However, unless an invalid input is deliberately placed causing a compilation error, any input should still work
*/

#include <iostream>
#include <array>
#include <iomanip>

// Set up constants
constexpr int arraySize{25}; // Size of each array
constexpr int decimalPrecision{1}; // Desired amount of decimal precision

int main()
{
    // Set up three arrays, each containing float elements and having the desired size
    std::array<float, arraySize> array1;
    std::array<float, arraySize> array2;
    std::array<float, arraySize> array3;

    // Print a quick message to terminal with analytics about the arrays
    std::cout << "Each array contains float elements and each are " << arraySize << " elements long." << std::endl;

    // Ensure that the output is printed with one decimal point of precision
    // All the numbers being stored are whole numbers so std::cout will eliminate the decimal by default
    std::cout << std::fixed;
    std::cout << std::setprecision(decimalPrecision);

    // Iterate through each array as many times as there are elements in each array
    for (float i{}; i < arraySize; i++)
    {   
        // Apply deliberate static casts (although implicit casting will occur)
        array1[i] = static_cast<float>(i); // Unaltered counter assigned to first array
        array2[i] = static_cast<float>(i * i); // Squared counter assigned to second array
    }

    // Generate the elements of the third array and print to terminal
    for (int i{}; i < arraySize; i++)
    {
        // Add entries from first/second arrays and assign to third
        array3[i] = array1[i] + array2[i]; 

        // Display formatted final output with the format: for counter; element + element = element
        std::cout << i << "; " << array1[i] << " + " << array2[i] << " = " << array3[i] << std::endl;
    }

    return 0;
}