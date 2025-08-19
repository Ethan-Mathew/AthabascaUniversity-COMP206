/* 
 Title: Assignment3Question1.cpp
 Description: Problem 1 - Word Counter
 Date: August 17, 2025
 Author: Ethan Mathew
*/

/*
 DOCUMENTATION
 
 Program Purpose:
    Demonstrate usage of file input and streams/buffers in C++
    Build a program to count the number of whitespace seperated words in a .txt file

 Compile (sample output .exe name given): g++ -o Assignment3Question1.exe Assignment3Question1.cpp
 Execution: ./Assignment3Question1.exe {filename}
 Example: ./Assignment3Question1.exe excerpt.txt
  
 Classes: None

 Variables:
    inputFile - ifstream object pointing to the requested .txt file
    input - std::string buffer storing words as they are read in
    counter - int counter that is incremented for each word read
*/

/*
 TEST PLAN
 Normal case: User inputs excerpt.txt to the command line argument
 - Program reads in 359 words, as expected

 Invalid case: User passes gibberish (i.e. 0ihjsidj[oknun89273sd48] or a misnamed file (i.e. excerpt)
 - Program prints a message to the user of the invalid input

 Invalid case: User passes no files
 - Program prints a message to the user of the invalid input

 Invalid case: User passes multiple files or one file and then gibberish text (i.e. excerpt.txt isufhdisjfsd)
 - Program prints a message to the user of the invalid input

 Limiting case: User passes a file with an enormous amount of text (droning essay about sleep by ChatGPT, sleep.txt)
 - Program reads in 1038 words, as expected

 Discussion:
 - I have provided the excerpt.txt file as well as the other .txt files I used for testing in the submission
*/

#include <iostream>
#include <fstream>
#include <string>

// Include argc and argv for command line arguments
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

    // Set up an input file stream object initialized to the passed file name
    std::ifstream inputFile{std::string{argv[1]}};

    // If the file cannot be found, print a message to the user and terminate the program
    if (!inputFile)
    {
        std::cerr << "Opening the sample text failed." << std::endl;
        return 1; // Terminate with a non-zero return
    }

    // Set up an 'input' buffer and counter to collect/count words
    std::string input{};
    int counter{};
    
    // Continue intaking words into the 'input' buffer
    // ifstream will automatically use whitespaces as a delimiter
    while (inputFile >> input)
    {
        // Increment the counter every time another word is hit
        counter++;
    }

    // Output the number of words to the user
    std::cout << "Total number of words: " << counter << std::endl;

    return 0;
}