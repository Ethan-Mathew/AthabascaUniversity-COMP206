/* 
 Title: Assignment2Question1.cpp
 Description: Problem 1 - Farm Animal Inheritance
 Date: August 13, 2025
 Author: Ethan Mathew
*/

/*
 DOCUMENTATION
 
 Program Purpose:
    Create an inheritance chain using a parent Animal class and derived farm animal classes
    Uses polymorphic virtual functions and command line arguments

 Compile (sample output .exe name given): g++ -o Assignment2Question1.exe Assignment2Question1.cpp
 Execution: ./Assignment2Question1.exe {animalname}
 Example: ./Assignment2Question1.exe duck
  
 Classes: Animal, Animal>>Pig, Animal>>Duck, Animal>>Sheep, Animal>>Cow

 Variables:
    Temporary variables instantiated for each class type at request of user
    Examples: duckTest from test() member function
              duckTemp from createAnimal() member function
*/

/*
 TEST PLAN
 Normal case: User properly provides input in the form of one of the available animals with propper casing (pig, sheep, duck, cow)
 - The animal "tests" are printed as well as the desired animal passed in the command line argument

 Invalid case: User passes an invalid animal or animal with improper casing (i.e. Pig, moose)
 - The animal "tests" are printed as well as a message notifying the user of the input invalidity

 Invalid case: User passes gibberish (i.e. 0ihjsidj[oknun89273sd48])
 - The animal "tests" are printed as well as a message notifying the user of the input invalidity

 Limiting case: User passes multiple animals (or multiple gibberish items)
 - The animal "tests" are printed as well as a message notifying the user of the input invalidity

 Limiting case: User passes no input
 - The animal "tests" are printed as well as a message notifying the user of the input invalidity

 Discussion:
 - It is actually easier to proof the program against invalid inputs from command line arguments than with std::cin
 - In testing, I was not able to break the program, regardless of the randomness of my inputs
*/

#include <iostream>
#include <string>

// Animal class
// Will be parent class to other animals
class Animal
{
// Public member functions contain default printable messages for each child class
public:
    Animal()
    {
        std::cout << "I am an animal" << std::endl;
    }

    // Set up virtual function so descendant functions can implement their own behaviour
    virtual void sound() const
    {
        std::cout << "An animal makes a sound based on the animal that it is" << std::endl;
    }
};

// Pig class
// Inherit publicly from Animal
class Pig: public Animal
{
public:
    Pig()
    {
        std::cout << "I am a Pig" << std::endl;
    }

    virtual void sound() const override
    {
        std::cout << "oink" << std::endl;
    }
};

// Sheep class
// Inherit publicly from Animal
class Sheep: public Animal
{
public:
    Sheep()
    {
        std::cout << "I am a Sheep" << std::endl;
    }

    virtual void sound() const override
    {
        std::cout << "baah" << std::endl;
    }
};

// Duck class
// Inherit publicly from Animal
class Duck: public Animal
{
public:
    Duck()
    {
        std::cout << "I am a Duck" << std::endl;
    }

    virtual void sound() const override
    {
        std::cout << "quack" << std::endl;
    }
};

// Cow class
// Inherit publicly from Animal
class Cow: public Animal
{
public:
    Cow()
    {
        std::cout << "I am a cow" << std::endl;
    }

    virtual void sound() const override
    {
        std::cout << "moo" << std::endl;
    }
};

// Custom AnimalTest class for sampling each animal
class AnimalTest
{
public:
    // Explicitly defined default constructor
    AnimalTest()
    {
    }

    // test member function
    // Simply tests each animal by creating an object of each class type and calling .sound()
    // Also prints a custom message before each class is tested
    // The custom message prevents me from creating an array of Animal pointers to each child class and using a for loop to call each member function
    static void test()
    {   
        std::cout << "Testing a pig: " << std::endl; // Custom message using the name of the animal
        Pig pigTest;
        pigTest.sound();
        std::cout << std::endl;

        std::cout << "Testing a sheep: " << std::endl;
        Sheep sheepTest;
        sheepTest.sound();
        std::cout << std::endl;

        std::cout << "Testing a duck: " << std::endl;
        Duck duckTest;
        duckTest.sound();
        std::cout << std::endl;

        std::cout << "Testing a cow: " << std::endl;
        Cow cowTest;
        cowTest.sound();
        std::cout << std::endl;
    }

    // createAnimal member function
    // Creates an an object depending on command line argument passed on execution
    static void createAnimal(char* animalInput)
    {
        std::cout << "Creating an animal from your CLI inputs: " << std::endl;
        std::string animal{animalInput};

        // Simply uses hardcoded if field to handle the small number of possibilities
        if (animal == "pig")
        {
            Pig pigTemp;
            pigTemp.sound();
        }
        else if (animal == "sheep")
        {
            Sheep sheepTemp;
            sheepTemp.sound();
        }
        else if (animal == "duck")
        {
            Duck duckTemp;
            duckTemp.sound();
        }
        else if (animal == "cow")
        {
            Cow cowTemp;
            cowTemp.sound();
        }
        else
        {
            // Include a default message for invalid/misspelt animals
            std::cout << "An invalid animal was passed. Please try again.";
        }
    }
};

// Include argc and argv in main() parameters
int main(int argc, char* argv[])
{
    AnimalTest::test(); // Demonstrate creation/use of all Animal subclasses

    // Handle input from the user
    // If there was one argument passed in the CLI, attempt to use it
    if (argc == 2)
    {
        AnimalTest::createAnimal(argv[1]);
    }
    else
    {
        // If no or more than one argument was passed, then it is absolutely invalid
        std::cout << "Your animal argument in the CLI was invalid (or wasn't added)" << std::endl;
    }
    
    return 0;
}