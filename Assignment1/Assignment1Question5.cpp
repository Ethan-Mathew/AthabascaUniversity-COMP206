/* 
 Title: Assignment1Question5.cpp
 Description: Problem 5 - Print All Prime Numbers From 1 to 10000
 Date: July 25, 2025
 Author: Ethan Mathew
*/

/*
 DOCUMENTATION
 
 Program Purpose:
 	Print All Prime Numbers From 1 to 10000 using nested for loops

 Compile (sample output .exe name given): g++ -o Assignment1Question5.exe Assignment1Question5.cpp
 Execution: ./Assignment1Question5.exe
  
 Classes: none

 Variables:
    start - constexpr int used as the starting value - as per assignment parameters, it is 1 by default
    end - constexpr int used as the end value - as per assignment parameters, it is 10000 by default
    isPrime - boolean flag used to denote if the particular number has been marked as a prime number
*/

/*
 TEST PLAN

 Normal Case: start = 1 and end = 10000
 - Program executes normally, printing all expected prime numbers

 Limiting Case: start > 0 and end is any positive number
 - Program prints all expected prime numbers in the adjusted range

 Limiting Case: start < 0 and end is any positive number
 - Program prints all expected prime numbers despite the invalid range

 Invalid Case: start > end
 - Program prints nothing

 Discussion:

 - The printing process is hardcoded and generates the same results every time without user input
 - However, if the grader chooses, they may change the values stored in start and end before compilation/execution
*/

#include <iostream>

int main()
{
    // Declaring constant variables to contain start/end values (avoids magic numbers)
    constexpr int start{1};
    constexpr int end{10000};
    bool isPrime; // Set up a flag to mark whether a number is prime or not

    for (int i{start}; i <= end; i++) // Iterate through every number in the desired range
    {   
        isPrime = true; // Default the flag to true, adjust later if necessary

        for (int j{2}; j < i; j++) // Iterate through every number from 2 to one less than i
        {
            if (i % j == 0) // If the program finds a number between 1 and i that divides evenly into i, it is not prime
            {
                isPrime = false; // Set the flag to false
                break; // Break the loop and prevent further checks
            }
        }

        if (isPrime && i > 1) // If the flag is true and the number is not 1, print the number because it is prime (1 is not prime)
        {
            std::cout << i << "\n";
        }
    }

    return 0;
}