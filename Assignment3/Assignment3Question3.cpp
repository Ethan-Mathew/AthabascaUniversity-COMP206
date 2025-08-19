/* 
 Title: Assignment3Question3.cpp
 Description: Problem 3 - File Text Reader and Storage
 Date: August 17, 2025
 Author: Ethan Mathew
*/

/*
 DOCUMENTATION
 
 Program Purpose:
    Create a program to read the contents of a text file
    Store the contents in an array
    Reprint each line of the file to the user in a formatted string

 Compile (sample output .exe name given): g++ -o Assignment3Question3.exe Assignment3Question3.cpp
 Execution: ./Assignment3Question3.exe {filename}
 Example: ./Assignment3Question3.exe excerpt.txt
  
 Classes: TextFileReader, TextFileReaderDemo

 Variables:
    arrayLength - int variable containing the maximum desired number of lines stored by the program
    m_textLines - array member data containing each line of the program
    m_lineCount - int member data containing the number of lines read in by the program so far
    countFileLines - ifstream object pointing to the requested .txt file
    line - string buffer variable to read in each line of the program
    arrayContent - string meant to carry the full text of the input text file
    reader - TextFileReader object used to demo the class' functionality
*/

/*
 TEST PLAN
 Normal case: User inputs excerpt.txt to the command line argument
 - Program reads in 32 lines as expected
 - Despite the array having 100 spaces of storage, program stops printing early when expected

 Invalid case: User passes gibberish (i.e. 0ihjsidj[oknun89273sd48] or a misnamed file (i.e. excerpt)
 - Program prints a message to the user of the invalid input
 - Program still attempts to read in the file's data but fails and the program ends

 Invalid case: User passes no files
 - Program prints a message to the user of the invalid input

 Invalid case: User passes multiple files or one file and then gibberish text (i.e. excerpt.txt isufhdisjfsd)
 - Program prints a message to the user of the invalid input

 Limiting case: User passes a file with more than 100 lines (i.e. test.txt)
 - Program reads in 100 (or however many specified) lines and stops

 Discussion:
 - I have provided the excerpt.txt file as well as the other .txt files I used for testing in the submission
*/

#include <iostream>
#include <fstream>
#include <array>
#include <string>
#include "divider.h"

// Constant value containing the desired number of spaces in the array - 100 by default
constexpr int arrayLength{100};

// TextFileReader class
class TextFileReader
{
private:
    // Member array containing strings of each line from the text file
    // Array size initialized to desired length
    std::array<std::string, arrayLength> m_textLines{};
    int m_lineCount{}; // Set up a counter to hold the number of lines in the text file

public:
    // Default constructor (doesn't do anything)
    TextFileReader()
    {
    }

    // Constructor taking string file name
    TextFileReader(const std::string& fileName)
    {
        // Use the inputted file name to set up an ifstream object
        std::ifstream countFileLines{fileName};

        // If the file cannot be found, print a message to the user
        if (!countFileLines)
        {
            std::cerr << "Opening the sample text failed." << std::endl;
        }

        // Find the file length
        std::string line; // Buffer string variable
        // Iterate through each line in the file, incrementing the counter for each line
        // The program should, under no circumstances, read in more lines than there are spaces in the array
        // Therefore, stop counting new lines once the maximum number of lines have already been counted
        while (std::getline(countFileLines, line) && m_lineCount < arrayLength)
        {
            m_textLines[m_lineCount++] = line;
        }
    }

    // Return string containing every line from the file that was stored in the array
    std::string contents()
    {
        // Instantiate a string that will carry the cumulative text
        std::string arrayContent;

        // For every element in the array, negating the empty elements, add them to the string
        for (int i{}; i < m_lineCount; i++)
        {
            arrayContent += m_textLines[i] + "\n"; // String concatenation is used to continue adding to the string
        }

        return arrayContent;
    }

    // Display the (filled) array contents
    void display() const
    {
        // Print every element in the array, except the empty elements in a formatted string
        for (int i{}; i < m_lineCount; i++)
        {
            std::cout << "Line " << (i + 1) << ": " << m_textLines[i] << std::endl;
        }
    }
};

class TextFileReaderDemo
{
public:
    static void main(const std::string& fileNameArg)
    {
        // Create a TextFileReader object initialized to a known .txt file
        TextFileReader reader{fileNameArg};

        // Display the raw string containing the entirety of the file's contents 
        std::cout << reader.contents() << std::endl;

        createDivider();

        // Display the formatted, line-by-line view of the file
        reader.display();
    }
};

int main(int argc, char* argv[])
{
    // If there are no or too many command line arguments passed when running the program, halt execution and leave a warning
    if (argc < 2)
    {
        std::cerr << "Please pass a file name to the CLI when executing the program." << std::endl;
        return 1;
    }
    else if (argc > 2)
    {
        std::cerr << "Too many files have been passed." << std::endl;
        return 1; // Terminate with a non-zero return
    }

    // Call the main() member function of TextFileReaderDemo to start the program
    TextFileReaderDemo::main(argv[1]);

    return 0;
}