/* 
 Title: Assignment1Question4.cpp
 Description: Problem 4 - C++ Help Menu
 Date: July 25, 2025
 Author: Ethan Mathew
*/

/*
 DOCUMENTATION
 
 Program Purpose:
 	Provide a help menu containing definitions for various C++ control structures.
    Utilize a switch statement to neatly change menu output based on user input

 Compile (sample output .exe name given): g++ -o Assignment1Question4.exe Assignment1Question4.cpp
 Execution: ./Assignment1Question4.exe
  
 Classes: none

 Variables:
    selection - char that populates with the user's choice on the help menu after input validation. Char is used to accommodate alphabetical
                and "numerical" (ASCII character number) input.
    input - string that holds raw input from std::cin
*/

/*
 TEST PLAN

 Normal Case: Proper input is provided (i.e. 1, 5, and then x)
 - Menu options for 1 and 5 are printed and the program ends

 Invalid Case: Improper input is provided (any otherwise unacceptable input)
 - The program notifies the user that the input is invalid and re-asks for input

 Limiting Case: Multiple responses are provided (i.e. user inputs '1 2 3 4 5')
 - The first response is taken and an attempt is made to use it
 - If the first response passed is valid, it will print the corresponding entry and discard the remainder
 - If the first response is invalid, it will notify the user that the input is invalid and re-asks for input

 Discussion:
 - The input handling of the program is mostly comprehensive and offers a great degree of flexibility for the allowed inputs
 - In my testing, I was not able to cause the program to break at any time, regardless of the randomness of my inputs
 - Using standard input, the program cannot block bad inputs as they occur - it can only prevent those inputs from being digested
   by the rest of the program by stating that the input was invalid and asking for a new input
 - The program is supposed to be given only one number or letter per input but is designed to handle other inputs
*/

#include <iostream>
#include <string>
#include <limits>

int main()
{
    char selection; // Selection variable should be inputted as a char to accommodate the numerical selection and 'x'.

    do // Implement a do-while loop - preferable to regular while since the program must run at least once.
    {
        // Print the menu (formatted on newlines for ease of debugging)
        std::cout << "C++ Help Menu\n"
                  << "Select Help on:\n"
                  << "1. If\n"
                  << "2. Switch\n"
                  << "3. For\n"
                  << "4. While\n"
                  << "5. Do-while\n"
                  << "x. Exit\n"
                  << std::endl;

        // Input validation loop
        while (true)
        {
            std::string input; // Take input as a string to accomodate any input
            std::cout << "Selection: ";
            std::cin >> input;

            // Clear and ignore any extra input (e.g., whitespace, extra characters)
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << std::endl;

            // Check if input is valid
            if (input == "1" ||
                input == "2" ||
                input == "3" ||
                input == "4" ||
                input == "5" ||
                input == "x" ||
                input == "X")
            {
                selection = input[0]; // Accept the input as selection
                break; // Exit validation loop
            }
            else
            {
                // Inform user of invalid input
                std::cout << "Please enter a valid option (1-5 or x to exit)" << std::endl;
            }
        }

        // Display different definition based on selection variable
        // Implemented via switch as per assignment requirements
        switch (selection)
        {
        case '1':
            std::cout << "if: An if statement in C++ is a control structure\n"
                      << "that allows a program to execute a block of code only\n"
                      << "if a specified condition is true. The condition is\n"
                      << "typically a boolean expression that evaluates to either\n"
                      << "true or false. If the condition is true, the statements\n"
                      << "inside the if block run; otherwise, they are skipped.\n"
                      << "You can also use else and else if clauses to handle\n"
                      << "alternative conditions.\n";
            std::cout << std::endl;
            break;

        case '2':
            std::cout << "switch: A switch statement in C++ is a control structure\n"
                      << "used to execute one block of code among many based on the\n"
                      << "value of an integral (or enum) expression. The expression\n"
                      << "is evaluated once, and control jumps to the matching case\n"
                      << "label. Each case can contain code and typically ends with\n"
                      << "a break to prevent fall-through to the next case. A\n"
                      << "default case can be added to handle values not explicitly\n"
                      << "listed.\n";
            std::cout << std::endl;
            break;

        case '3':
            std::cout << "for: A for loop in C++ is a control structure used to\n"
                      << "repeat a block of code a specific number of times. It\n"
                      << "consists of three parts: initialization, condition, and\n"
                      << "update, all defined in a single line. The loop runs as long\n"
                      << "as the condition is true, executing the body each time and\n"
                      << "then updating the loop variable. It's commonly used for\n"
                      << "counting iterations or traversing arrays.\n";
            std::cout << std::endl;
            break;

        case '4':
            std::cout << "while: A while loop in C++ is a control structure that\n"
                      << "repeatedly executes a block of code as long as a given\n"
                      << "condition remains true. The condition is checked before\n"
                      << "each iteration, so the loop may not run at all if the\n"
                      << "condition is false initially. It's useful when the number\n"
                      << "of iterations isn't known in advance. If the condition never\n"
                      << "becomes false, the loop can result in an infinite loop.\n";
            std::cout << std::endl;
            break;

        case '5':
            std::cout << "do-while: A do-while loop in C++ is similar to a while\n"
                      << "loop but guarantees that the loop body executes at least\n"
                      << "once. The condition is checked after the code block runs,\n"
                      << "not before. This makes it useful when the loop should run at\n"
                      << "least once regardless of the condition. The loop continues\n"
                      << "repeating as long as the condition evaluates to true.\n";
            std::cout << std::endl;
            break;
    
        default:
            // Default switch parameter used to accommodate 'x' selection
            std::cout << "Thank you. Good bye.";
            break;
        }
    }
    while (selection != 'x' && selection != 'X'); // Continually re-run the help menu for as long as selection is not 'x' or 'X'

    return 0;
}
