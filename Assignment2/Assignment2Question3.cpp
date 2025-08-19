/* 
 Title: Assignment2Question3.cpp
 Description: Problem 3 - Constructors and Destructors with an Elevator
 Date: August 13, 2025
 Author: Ethan Mathew
*/

/*
 DOCUMENTATION
 
 Program Purpose:
    Create an elevator class to illustrate the use of constructors, defautl constructors,
    and the destructor

 Compile (sample output .exe name given): g++ -o Assignment2Question3.exe Assignment2Question3.cpp
 Execution: ./Assignment2Question3.exe
  
 Classes: Elevator

 Variables:
    Member variables: m_currentFloor, m_stories - carry the current floor of the elevator
                      and the number of stories in the building
    Temporary variables: buildingX (1 <= X <= 5) - instantiations of the Elevator class
*/

/*
 TEST PLAN
 Normal case: 16-story building
 - Elevator executes "movements" as expected and returns to the first floor

 Normal case: Test elevator with default story count (5)
 - Elevator executes "movements" as expected and returns to the first floor

 Invalid case: Attempt to access floor beyond building height (travel to floor 14 in a 12 story building)
 - When the request is made to travel to the invalid floor, it is denied and a message is printed to the user
 - The remainder of the travel plan executes as expected

 Invalid case: Attempt to access floor below ground level (travel to floor 0)
 - When the request is made to travel to the invalid floor, it is denied and a message is printed to the user
 - The remainder of the travel plan executes as expected

 Discussion:
 - Similar to the prior question, I am expecting at least semantically proper inputs to the elevator objects
 - For example, I cannot really handle an input of a string as the floor number without some kind of compile error occuring
 - That is, unless I purposely write member function overloads for each non-valid input data type and provide some kind of
   message response (which is not very robust)
*/

#include <iostream>
#include "divider.h"

// Definition of the elevator class
class Elevator
{
private:
    // Private member data containing the current floor (1 by default) and the number of stories
    int m_currentFloor{1};
    int m_stories;

public:
    // Default constructor
    Elevator()
        : Elevator {5} // Delegates construction to non-default constructor, passing default argument of 5
    {
    }

    // Constructor, initializing 
    Elevator(const int stories)
    // Initialize both member variables to the number of stories
        : m_stories{stories}
    {
        std::cout << "Currently on floor " << m_currentFloor << std::endl; // We'll let the user's current floor be the Nth
    }

    // Print the number of stories in the building
    void printStories()
    {
        std::cout << "The building has " << m_stories << " floors" << std::endl;
    }

    // Allow the user to travel between floors
    void setCurrentFloor(const int floor)
    {
        if (floor > m_stories || floor < 1)
        {
            std::cout << "Invalid floor requested" << std::endl;
        }
        else
        {
            std::cout << "Travelling to floor " << floor << std::endl;
            m_currentFloor = floor;
        }
    }

    // Print the current floor
    void printCurrentFloor()
    {
        std::cout << "Currently on floor " << m_currentFloor << std::endl;
    }

    // Destructor for ending behaviour
    ~Elevator()
    {
        m_currentFloor = 1; // Deliberately and literally set the current floor to 1
        std::cout << "Elevator ending: elevator returned to the first floor." << std::endl; // Print message back to the rider
    }
};

int main()
{   
    // Elevator instance 1 - standard
    {
        Elevator building1{16};
        building1.printStories();
        building1.setCurrentFloor(6);
        building1.printCurrentFloor();
    }

    createDivider();

    // Elevator instance 2 - more complex travel
    {
        Elevator building2{20};
        building2.printStories();
        building2.setCurrentFloor(12);
        building2.printCurrentFloor();
        building2.setCurrentFloor(17);
        building2.printCurrentFloor();
        building2.setCurrentFloor(7);
        building2.printCurrentFloor();
        building2.setCurrentFloor(3);
        building2.printCurrentFloor();
    }

    createDivider();

    // Elevator instance 3 - invalid floor desired
    {
        Elevator building3{12};
        building3.printStories();
        building3.setCurrentFloor(6);
        building3.printCurrentFloor();
        building3.setCurrentFloor(14);
        building3.printCurrentFloor();
    }

    createDivider();

    // Elevator instance 4 - another invalid floor desired
    {
        Elevator building4{9};
        building4.printStories();
        building4.setCurrentFloor(0);
        building4.printCurrentFloor();
    }

    createDivider();

    // Elevator instance 5 - use of default constructor
    {
        Elevator building5;
        building5.printStories();
        building5.setCurrentFloor(4);
        building5.printCurrentFloor();
        building5.setCurrentFloor(3);
        building5.printCurrentFloor();
        building5.setCurrentFloor(2);
        building5.printCurrentFloor();
    }

    return 0;
}