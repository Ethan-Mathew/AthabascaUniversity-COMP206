/* 
 Title: Assignment3Question5.cpp
 Description: Problem 5 - Sortable Bookshelf
 Date: August 17, 2025
 Author: Ethan Mathew
*/

/*
 DOCUMENTATION
 
 Program Purpose:
    Create an extension to Assignment 2 Question 2's Book class by creating a bookshelf
    For the hardcoded array of books provided, print details about each book in default order
    Create a comparator to sort the book array and print details about each book in sorted order

 Compile (sample output .exe name given): g++ -o Assignment3Question5.exe Assignment3Question5.cpp
 Execution: ./Assignment3Question5.exe
  
 Classes: Book, Comparator, Bookshelf

 Variables:
    shelfSize - Global constexpr int denoting the number of books per shelf
    shelfTest - Bookshelf object instantiated to run the program
    m_title, m_numberISBN, m_author, m_edition, m_publisher, m_yearPublished - Member data about each book object (strings and int)
    m_shelf - Array containing 12 Book objects
*/

/*
 TEST PLAN
 Normal case: Program is executed with the currently hardcoded list
 - The books are printed back as expected with sorting occurring correctly

 Invalid case: Empty or incorrect data formats for book objects (Empty strings for title, author, ISBN, etc.)
 - Prints data as entered, despite being semantically wrong

 Limiting case: Book list is provided two entries with the same title and year published but different other details
 - The books are not swapped by stable sort

 Discussion:
 - In terms of testing, it is similarly hard to judge what I should/should not test as with Assignment 2 Question 2
 - For the test cases provided, I tried to be thoughtful
 - However, because the test cases are hardcoded, it is hard to think of appropriate tests and handling for those tests
*/

#include <iostream>
#include <string>
#include <array>
#include <algorithm> // For std::sort
#include <sstream>
#include "divider.h"

constexpr int shelfSize{12}; // Global constant denoting the number of books per shelf

// Book class imported from Assignment 2 Question 2
// Modifications/improvements made to the class to assist with this problem
class Book
{
private:
    std::string m_title;
    std::string m_numberISBN; // ISBN numbers contain '-' hyphens so strings would be appropriate
    std::string m_author;
    std::string m_edition;
    std::string m_publisher;
    int m_yearPublished;

public:
    // Added an explicit default constructor
    Book()
    {
    }
    
    // Included an actual constructor
    // Serves the same purpose as the setAll() member function but is actually usable for initialization
    Book(const std::string& title, const std::string& numberISBN, const std::string& author, 
         const std::string& edition, const std::string& publisher, const int yearPublished)
        : m_title{title}, m_numberISBN{numberISBN}, m_author{author}, m_edition{edition}, 
          m_publisher{publisher}, m_yearPublished{yearPublished}
    {
    }

    // Setter member functions
    void setTitle(const std::string& title) {m_title = title;}
    void setISBN(const std::string& numberISBN) {m_numberISBN = numberISBN;}
    void setAuthor(const std::string& author) {m_author = author;}
    void setEdition(const std::string& edition) {m_edition = edition;}
    void setPublisher(const std::string& publisher) {m_publisher = publisher;}
    void setYearPublished(const int yearPublished) {m_yearPublished = yearPublished;}
    void setAll(const std::string& title,
                const std::string& numberISBN, 
                const std::string& author, 
                const std::string& edition, 
                const std::string& publisher, 
                const int yearPublished)
    {
        m_title = title;
        m_numberISBN = numberISBN;
        m_author = author;
        m_edition = edition;
        m_publisher = publisher;
        m_yearPublished = yearPublished;
    }

    // Getter member functions
    const std::string& getTitle() const {return m_title;}
    const std::string& getISBN() const {return m_numberISBN;}
    const std::string& getAuthor() const {return m_author;}
    const std::string& getEdition() const {return m_edition;}
    const std::string& getPublisher() const {return m_publisher;}
    const int getYearPublished() const {return m_yearPublished;}
    // Modified the printall() member function to print a formatted sentence rather than a list
    void printAll() const
    {
        std::cout << "Title: " << m_title << 
                     " | Edition: " << m_edition <<
                     " | Author: "<< m_author <<
                     " | Publisher: " << m_publisher <<
                     " | Year Published: " << m_yearPublished <<
                     " | ISBN: " << m_numberISBN << std::endl;
    }
};

class Comparator
{
public:
    // compareTo returns true if the two books are already sorted or false if they need to be swapped
    static bool compareTo(const Book& book1, const Book& book2)
    {
        // Switch comparison method to year published if the titles are identical
        if (book1.getTitle() == book2.getTitle())
        {
            return (book1.getYearPublished() < book2.getYearPublished());
        }

        return (book1.getTitle() < book2.getTitle()); 
    }
};

// Helper function that intakes an array of books and calls the printAll() member function on each Book
void printArray(const std::array<Book, 12>& shelf)
{
    // For-each loop calling printAll() on each element
    for (const Book& book : shelf)
    {
        book.printAll();
    }
}

class Bookshelf
{
private:
    // The array (shelf) containing twelve Books
    std::array<Book, shelfSize> m_shelf;
    
public:
    // Explicit default constructor
    Bookshelf()
    {
    }

    // main() member function
    void main()
    {
        // Assign the shelf to a hardcoded array of Book objects
        m_shelf = {
            Book {"American Prometheus", "978-0375412028", "Kai Bird", "1st", "Alfred A. Knopf", 2005},
            Book {"Einstein: His Life and Universe", "978-0743264730", "Walter Isaacson", "1st", "Simon & Schuster", 2007},
            Book {"Dune", "978-0441172719", "Frank Herbert", "2nd", "Chilton Books", 1965},
            Book {"Dune Messiah", "978-0441172696", "Frank Herbert", "1st", "Putnam Publishing", 1969},
            Book {"Quantitative Finance", "978-0471498629", "Paul Wilmott", "2nd", "Wiley", 2000},
            Book {"Calculus", "978-1337624183", "James Stewart", "9th", "Cengage", 2020},
            Book {"Introduction to Linear Algebra", "978-0980232776", "Gilbert Strang", "5th", "Wellesley Cambridge Press", 2016},
            Book {"Inside the Machine", "978-1593271046", "Jon Stokes", "1st", "No Starch Press", 2006},
            Book {"Operating Systems Three Easy Pieces", "978-1985086593", "Arpaci-Dusseau", "1st", "Arpaci-Dusseau Books", 2018},
            Book {"TCP/IP Illustrated", "978-0201633467", "W. Richard Stevens", "2nd", "Addison-Wesley", 2011},
            Book {"A Beautiful Mind", "978-0684819068", "Sylvia Nasar", "1st", "Simon & Schuster", 1998},
            Book {"The Psychology of Money", "978-0857197689", "Morgan Housel", "1st", "Harriman House", 2020}
        };

        // Print out each book for the first time
        std::cout << "The books on this shelf are: \n" << std::endl;
        printArray(m_shelf);

        createDivider();

        // Use std::sort on the bookshelf with custom sorting policy
        std::cout << "Sorting the books: \n" << std::endl;
        std::sort(m_shelf.begin(), m_shelf.end(), Comparator::compareTo);
        
        // Print out each book for the second time
        // Displays alterations made by sorting
        printArray(m_shelf);
    }
};

int main()
{   
    // Instantiate a Bookshelf object
    Bookshelf shelfTest;
    shelfTest.main(); // Call main() on the Bookshelf object to get output from the program

    return 0;
}