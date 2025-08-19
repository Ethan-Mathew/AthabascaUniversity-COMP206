/* 
 Title: Assignment3Question2.cpp
 Description: Problem 2 - Line-by-Line Reprint
 Date: August 17, 2025
 Author: Ethan Mathew
*/

/*
 DOCUMENTATION
 
 Program Purpose:
    Utilize input/output buffers to build a program that re-prints each line of a file to the terminal
    Implement functionality for user-controlled printing

 Compile (sample output .exe name given): g++ -o Assignment3Question2.exe Assignment3Question2.cpp
 Execution: ./Assignment3Question2.exe
 Example: ./Assignment3Question2.exe
  
 Classes: None

 Variables:
    fileName - std::string containing the requested file name
    inputFile - ifstream object pointing to the requested .txt file
    lineText - std::string buffer storing words as they are read in
*/

/*
 TEST PLAN
 Normal case: User inputs excerpt.txt to the command line argument
 - Each line in the program is printed upon 'enter' keypress as expected

 Invalid case: User passes gibberish (i.e. 0ihjsidj[oknun89273sd48] or a misnamed file (i.e. excerpt)
 - Program prints a message to the user of the invalid input

 Invalid case: User passes multiple files or one file and then gibberish text (i.e. excerpt.txt isufhdisjfsd)
 - Program opens the correct file and begins normal execution
 - The remainder text is disgarded

 Limiting case: User passes a file with many lines (text.txt)
 - Each line in the program is printed upon 'enter' keypress as expected

 Discussion:
 - I have provided the excerpt.txt file as well as the other .txt files I used for testing in the submission
*/

#include <iostream>
#include <fstream>
#include <string>
#include <limits>

int main()
{
    // Prompt the user to enter a file name
    std::cout << "Please enter a file name (i.e. excerpt.txt): ";
    std::string fileName;
    std::cin >> fileName;

    std::cin.clear();        
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Create an input file stream object attached to the inputted file name
    std::ifstream inputFile{fileName};

    // If the file cannot be found, print a message to the user and terminate the program
    if (!inputFile)
    {
        std::cerr << "Opening the sample text failed." << std::endl;
        return 1; // Terminate with a non-zero return
    }

    // Create a string to hold the line's text
    std::string lineText;

    // Iterate throught the entire file, 
    while(std::getline(inputFile, lineText))
    {
        std::cin.get(); // Await the user pressing enter
        std::cout << lineText << std::endl; // Output the line to terminal
    }

    return 0;
}