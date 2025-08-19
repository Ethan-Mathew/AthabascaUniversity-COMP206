/* 
 Title: Assignment1Question2.cpp
 Description: Problem 2 - Temperature Unit Converter
 Date: July 25, 2025
 Author: Ethan Mathew
*/

/*
 DOCUMENTATION
 
 Program Purpose:
 	Convert temperatures from imperial to metric units (and vice versa) using user input via the CLI

 Compile (sample output .exe name given): g++ -o Assignment1Question2.exe Assignment1Question2.cpp
 Execution: ./Assignment1Question2.exe
  
 Classes: none

 Variables:
    response - char used to intake user response to continue/end the program
    inputResponse - string used to filter raw input and offload it to the response variable
    temp - double used to intake the requested temperature
    unit - char used to intake the requested unit of temperature
    inputUnit - string used to filter raw input and offload it to the unit variable
*/

/*
 TEST PLAN

 Normal Case: User enters numeric data and provides a valid response for unit and continuation response (i.e. 0, then f, then n)
 - Conversion works as expected 

 Invalid Case: User enters non-numeric data when prompted for the temperature (i.e. "hello" is entered)
 - Input validation catches the incorrect input and re-prompts the user to input a proper response

 Invalid Case: User does not enter a proper character for the unit (f or c) or continuation response (y or n)
 - Input validation catches the incorrect input and re-prompts the user to input a proper response

 Limiting Case: User enters a very large or very small number for the temperature
 - The program outputs its answer in scientific notation
 - For exceedingly large numbers (exceeding the memory size of a double) program will state that input was invalid

 Limiting Case: Multiple responses are provided (i.e. user inputs 'f hello there') when a letter response is requested
 - The first response is taken and an attempt is made to use it
 - If the first response passed is valid, it will proceed and discard the remainder
 - If the first response is invalid, it will notify the user that the input is invalid and re-asks for input

 Discussion:
 - The input handling of the program is mostly comprehensive and offers a great degree of flexibility for the allowed inputs
 - In my testing, I was not able to cause the program to break at any time, regardless of the randomness of my inputs
 - Using standard input, the program cannot block bad inputs as they occur - it can only prevent those inputs from being digested
   by the rest of the program by stating that the input was invalid and asking for a new input
 - The program is supposed to be given only one number or letter per input but is designed to handle other inputs
*/

#include <iostream>
#include <limits>
#include <string>

int main()
{
    std::cout << "This program converts Temperatures from Fahrenheit to Celsius and vice versa." << std::endl;

    char response;

    do
    {   
        // Ask user for input on their requested temperature
        std::cout << "Please enter your temperature: ";
        double temp;

        // Input validation - ensures non-numeric data is not accepted
        while (!(std::cin >> temp)) 
        {
            std::cout << "Invalid input. Please Try again: ";

            // Clear the error flag on std::cin
            std::cin.clear();

            // Discard invalid input
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        char unit;
        // Continue re-asking for the user's desired unit if their inputted unit is not valid
        while (true)
        {
            // Ask the user for their desired temperature
            std::cout << "Please enter the units (F/C): ";
            std::string inputUnit; // Set up a buffer variable for the input - string to handle any kind of input
            std::cin >> inputUnit;

            // Clear and ignore any extra input (e.g., whitespace, extra characters)
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << std::endl;

            if (inputUnit == "f" ||
                inputUnit == "F" ||
                inputUnit == "c" ||
                inputUnit == "C")
            {
                unit = inputUnit[0];
                break;
            }
            else
            {
                // If an invalid input is given, ask for a valid character and repeat the loop
                std::cout << "Please enter a valid character (F or C)" << std::endl;
            }
        }
        
        if (unit == 'F' || unit == 'f') // Actions if the user requests fahrenheit -> celsius conversion
        {
            // Display response data for fahrenheit -> celsius conversion using appropriate formula
            std::cout << "A temperature of " << temp << " degrees Fahrenheit is equivalent to "
            << ((temp - 32.0) * (5.0 / 9.0)) << " degrees Celsius." << std::endl;
        }
        else if (unit == 'C' || unit == 'c') // Actions if the user requests celsius -> fahrenheit conversion
        {
            // Display response data for celsius -> fahrenheit conversion using appropriate formula
            std::cout << "A temperature of " << temp << " degrees Celsius is equivalent to "
            << (((temp * 9.0) / 5.0) + 32) << " degrees Fahrenheit." << std::endl;
        }
        
        // Further input validation - verifies yes/no response
        while (true)
        {
            // Ask the user if they would like to continue making conversions
            std::cout << "Do you want another conversion? (Y/N): ";
            std::string inputResponse; // Set up a buffer variable for the input - string to handle any kind of input
            std::cin >> inputResponse;

            // Clear and ignore any extra input (e.g., whitespace, extra characters)
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << std::endl;

            if (inputResponse == "y" ||
                inputResponse == "Y" ||
                inputResponse == "n" ||
                inputResponse == "N")
            {
                response = inputResponse[0];
                break;
            }
            else
            {
                // If an invalid input is given, ask for a valid character and repeat the loop
                std::cout << "Please enter a valid character (Y or N)" << std::endl;
            }
        }
    }
    while (response == 'Y' || response == 'y'); // While the response is 'y' or 'Y', continue - any other response will end the program

    std::cout << "Thank you. Goodbye.";

    return 0;
}