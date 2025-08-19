/* 
 Title: Assignment2Question2.cpp
 Description: Problem 2 - Encapsulation with Book Class
 Date: August 13, 2025
 Author: Ethan Mathew
*/

/*
 DOCUMENTATION
 
 Program Purpose:
    Create a book class, illustrating encapsulation in OOP with getter and setter functions

 Compile (sample output .exe name given): g++ -o Assignment2Question2.exe Assignment2Question2.cpp
 Execution: ./Assignment2Question2.exe
  
 Classes: Book

 Variables:
    book1, book2, book3 - Instances of the Book class
    m_title, m_numberISBN, m_author, m_edition, m_publisher, m_yearPublished - Member data about each book object
*/

/*
 TEST PLAN
 Normal case: Use all three methods of creating and displaying book information using harmless, expected information
 - Individual setter/getter methods work correctly (book1)
 - setAll() method works correctly (book2)
 - printAll() method displays information correctly (book3)

 Invalid case: Empty or incorrect data formats (Empty strings for title, author, ISBN, etc.)
 - Prints data as entered, despite being semantically wrong

 Invalid case: Incorrect data types (i.e. string in the year category)
 - Compile error (cannot apply promotion/conversion of string -> int)

 Limiting case: Data values with accented characters (i.e. L'Étranger by Albert Camus )
 - Program runs as expected but unfamiliar characters may be arbitrarily converted to other ASCII symbols

 Limiting case: Data values with special characters (i.e. 活着 by 余华 - To Live by Yu Hua)
 - Program runs as expected but unfamiliar characters may be arbitrarily converted to other ASCII symbols

 Discussion:
 - I am not actually sure what to do with certain invalid cases with regard to creating compile errors
 - Unlike runtime errors using invalid inputs from input streams, compile errors offer no danger to the program user
 - Because each entry is hardcoded rather than input by any means, I figure that the person hardcoding their entry is 
   responsible for ensuring that it is valid
 - If anything, I cannot think of a method to handle invalid inputs that are hardcoded in that manner (i.e. with an input 
   stream, I can add input validation through various means)
 - Further, in proper practice, using an '= delete' is often expected which will cause a compilation error on certain
   function calls anyway
 - I suppose my question becomes, are compile errors acceptable for this kind of question upon alteration of the hardcoded
   data values?
*/

#include <iostream>
#include <string>
#include "divider.h" // Include header file that prints a consistent horizontal rule to separate test cases nicely

class Book
{
// Encapsulate member data as private
private:
    std::string m_title;
    std::string m_numberISBN; // ISBN numbers contain '-' hyphens so strings would be appropriate
    std::string m_author;
    std::string m_edition;
    std::string m_publisher;
    int m_yearPublished;

public:
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
    void printAll() const
    {
        std::cout << m_title << std::endl;
        std::cout << m_numberISBN << std::endl;
        std::cout << m_author << std::endl;
        std::cout << m_edition << std::endl;
        std::cout << m_publisher << std::endl;
        std::cout << m_yearPublished << std::endl;
    }
};

int main()
{
    // Initialize first book
    std::cout << "Book One:" << std::endl;
    Book book1;

    // Call individualized setter methods to construct the book and it's information
    book1.setTitle("Dune");
    book1.setISBN("9780441172719");
    book1.setAuthor("Frank Herbert");
    book1.setEdition("2nd");
    book1.setPublisher("Chilton Books");
    book1.setYearPublished(1965);

    // Call individualized getter methods to return the book data and print to terminal
    std::cout << book1.getTitle() << std::endl;
    std::cout << book1.getISBN() << std::endl;
    std::cout << book1.getAuthor() << std::endl;
    std::cout << book1.getEdition() << std::endl;
    std::cout << book1.getPublisher() << std::endl;
    std::cout << book1.getYearPublished() << std::endl;

    createDivider();
    
    // Initialize a second book
    std::cout << "Book Two:" << std::endl;
    Book book2;

    // Set all member data with setAll() member function
    book2.setAll("American Prometheus", "9780375412028", "Kai Bird", "1st", "Alfred A. Knopf", 2005);

    // Get back all data for book2 using conventional returns
    std::cout << book2.getTitle() << std::endl;
    std::cout << book2.getISBN() << std::endl;
    std::cout << book2.getAuthor() << std::endl;
    std::cout << book2.getEdition() << std::endl;
    std::cout << book2.getPublisher() << std::endl;
    std::cout << book2.getYearPublished() << std::endl;

    createDivider();

    // Initialize a second book
    std::cout << "Book Three:" << std::endl;
    Book book3;

    // Set all member data with setAll() member function
    book3.setAll("Einstein: His Life and Universe", "9780743264730", "Walter Isaacson", "1st", "Simon & Schuster", 2007);

    // Print all member data with printAll() member function
    book3.printAll();

    return 0;
}