/* 
 Title: Assignment2Question4.cpp
 Description: Problem 4 - Inheritance and Polymorphism with Rodents
 Date: August 13, 2025
 Author: Ethan Mathew
*/

/*
 DOCUMENTATION
 
 Program Purpose:
    Create a Rodent parent class with defined basic member functions/behaviours
    Override those functions with derived classes
    Leverage dynamic dispatch to call the correct member functions

 Compile (sample output .exe name given): g++ -o Assignment2Question4.exe Assignment2Question4.cpp
 Execution: ./Assignment2Question4.exe
  
 Classes: Rodent, Rodent>>Mouse, Rodent>>Gerbil, Rodent>>Hamster, Rodent>>GuineaPig

 Variables:
    rodents - array of four dynamic allocations using temporary objects
*/

/*
 TEST PLAN

 Normal case: User executes program as-is
 - All member function calls are applied to each rodent subclass as expected
 - Polymorphically overriden member functions are called appropriately
 
 Discussion
 - The function calls are hardcoded and are not meant to be changed
*/

#include <iostream>
#include <array>
#include "divider.h"

class Rodent
{
public:
    // Basic behaviours for Rodent objects with CLI output
    virtual void eat() const {std::cout << "Rodent eating" << std::endl;}
    virtual void sleep() const {std::cout << "Rodent sleeping" << std::endl;}
    virtual void groom() const {std::cout << "Rodent grooming" << std::endl;}
    virtual void move() const {std::cout << "Rodent moving" << std::endl;}

    // Virtual destructor
    virtual ~Rodent() {}
};

// Mouse derived from Rodent
class Mouse: public Rodent
{
    // Mouse-specific behaviours that override standard Rodent behaviours
    virtual void eat() const override {std::cout << "Mouse eating seeds" << std::endl;}
    virtual void move() const override {std::cout << "Mouse scurrying quickly" << std::endl;}
};

// Gerbil derived from Rodent
class Gerbil: public Rodent
{
    // Gerbil-specific behaviours that override standard Rodent behaviours
    virtual void eat() const override {std::cout << "Gerbil eating grains and nuts" << std::endl;}
    virtual void move() const override {std::cout << "Gerbil hopping in short bursts" << std::endl;}
};

// Hamster derived from Rodent
class Hamster: public Rodent
{
    // Hamster-specific behaviours that override standard Rodent behaviours
    virtual void eat() const override {std::cout << "Hamster stuffing food into cheek pouches" << std::endl;}
    virtual void sleep() const override {std::cout << "Hamster sleeping during the day (nocturnal)" << std::endl;}
};

// Guinea Pig derived from Rodent
class GuineaPig: public Rodent
{
    // Guinea Pig-specific behaviours that override standard Rodent behaviours
    virtual void eat() const override {std::cout << "Guinea Pig eating hay and grass" << std::endl;}
    virtual void groom() const override {std::cout << "Guinea Pig being groomed by another guinea pig" << std::endl;}
    virtual void move() const override {std::cout << "Guinea Pig waddling slowly" << std::endl;}
};

int main()
{
    // Dynamically allocate an array with each of the four rodents
    std::array<Rodent*, 4> rodents{new Mouse, new Gerbil, new Hamster, new GuineaPig};

    // Use a for-each loop to all each object's member functions
    // Repeat for all entries in the dynamically allocated array
    for (Rodent* rodent : rodents)
    {
        rodent->eat();
        rodent->groom();
        rodent->move();
        rodent->sleep();
        createDivider();
        delete rodent;
    }

    return 0;
}