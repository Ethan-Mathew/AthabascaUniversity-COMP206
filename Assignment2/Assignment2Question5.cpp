/* 
 Title: Assignment2Question5.cpp
 Description: Problem 5 - Inheritance and Polymorphism with Rodents
 Date: August 13, 2025
 Author: Ethan Mathew
*/

/*
 DOCUMENTATION
 
 Program Purpose:
    
 Compile (sample output .exe name given): g++ -o Assignment2Question5.exe Assignment2Question5.cpp
 Execution: ./Assignment2Question5.exe
  
 Classes: Point, Shape, Shape>>Circle, Shape>>Rectangle, Shape>>Triangle

 Variables:
    Constants: pi - 3.14159
    Many member variables and temporary shapes - in general, they keep track of individual Point objects,
                                                 or instantiated shape objects
*/

/*
 TEST PLAN

 Circle Tests:
 Normal case 1: Valid circle with non-zero radius (Circle 1) at point (2.5, 3.1) with radius 4.75
 - Circle constructs successfully with confirmation message
 - Area and circumference calculations execute correctly
 - Bounding box coordinates are correctly displayed

 Normal case 2: Default circle constructor (Circle 3)
 - Circle constructs at origin (0,0) with radius 1
 - All measurements and calculations execute as expected
 - Confirmation message displays successful construction

 Invalid case: Circle with zero radius (Circle 2)
 - Warning message displays about invalid radius
 - Calculations proceed despite invalid input
 - Results are displayed but may not be meaningful

 Rectangle Tests:
 Normal case 1: Valid rectangle (Rectangle 1) with points at (1.2, 5.6), (4.8, 5.6), (1.2, 1.1), (4.8, 1.1)
 - Rectangle constructs successfully with confirmation message
 - Area and perimeter calculations execute correctly
 - Bounding box displays expected coordinates

 Normal case 2: Valid square (Rectangle 4) with points at (-2.0, 2.0), (2.0, 2.0), (-2.0, -2.0), (2.0, -2.0)
 - Square identification message displays correctly
 - All measurements confirm square properties
 - Bounding box matches the square's vertices

 Normal case 3: Default rectangle constructor (Rectangle 3)
 - Creates expected 2x2 square centered at origin
 - All measurements confirm default properties
 - Bounding box shows correct default coordinates

 Invalid case: Coincident points for rectangle (Rectangle 2)
 - Warning message displays about invalid points
 - Calculations proceed despite invalid input
 - Results are displayed but may not be meaningful

 Triangle Tests:
 Normal case 1: Valid triangle (Triangle 1) with points at (-3.0, -2.0), (4.4, -1.2), (1.0, 5.9)
 - Triangle constructs successfully with confirmation message
 - Area and perimeter calculations execute correctly
 - Bounding box displays expected coordinates

 Normal case 2: Complex triangle (Triangle 3) with points at (-4.1, -3.3), (-1.6, -5.2), (-2.9, -1.1)
 - Triangle constructs successfully in negative coordinate space
 - All calculations execute correctly with negative coordinates
 - Bounding box properly encompasses negative coordinate points

 Normal case 3: Default triangle constructor (Triangle 4)
 - Creates triangle with expected points (0,0), (1,1), and (1,0)
 - All measurements confirm default properties
 - Bounding box shows correct default coordinates

 Invalid case: Triangle with coincident points (Triangle 2)
 - Warning message displays about invalid points
 - Calculations proceed despite duplicate points
 - Results are displayed but may not be meaningful

 Discussion:
 - All shape classes correctly demonstrate inheritance from the Shape base class
 - Invalid inputs are properly caught and warned against while allowing execution to continue
 - Each shape accurately performs its specific calculations
 - Default constructors provide appropriate basic versions of each shape
*/

#include <iostream>
#include <array>
#include <cmath>
#include <algorithm>
#include "divider.h"

// Create a constant, pi to be used for circle calculations
constexpr double pi{3.14159};

// Point class
class Point
{
public:
    // Member data containing x point and y point
    double m_x;
    double m_y;

    // Default constructor
    Point()
        : Point{0, 0} // Delegates construction to two parameter constructor overload
    {
    }

    // Standard constructor taking decimal numbers x and y
    Point(double x, double y)
        : m_x{x}, m_y{y}
    {
    }

    // Show member function - prints formatted coordinate to terminal
    void show() const {std::cout << "(" << m_x << ", " << m_y << ")" << std::endl;}
    
    // Add member function - intakes another point and performs vector addition
    void add(const Point& pointAdd)
    {
        m_x += pointAdd.m_x;
        m_y += pointAdd.m_y;
    }

    // Subtraction member function - intakes another point and performs vector subtraction
    void subtract(const Point& pointSub)
    {
        m_x -= pointSub.m_x;
        m_y -= pointSub.m_y;
    }
};

// Shape base class
class Shape
{
public:
    // Default area member - simply prints message to terminal and returns 0
    virtual double area() const 
    {
        std::cout << "Calculates the area of the shape" << std::endl;
        return 0;
    }

    // Default circumference member - simply prints message to terminal
    virtual double circumference() const 
    {
        std::cout << "Calculates the circumference/perimeter of the shape" << std::endl;
        return 0;
    }

    // Default bounding box member - simply prints message to terminal
    virtual std::array<Point, 4> boundingBox() const 
    {
        std::cout << "Provides the coordinates of a bounding box for the shape" << std::endl;
        return {};
    }

    // Default display member - simply prints message to terminal
    virtual void display() const
    {
        std::cout << "Displays all information about the shape (area, perimeter/circumference, bounding box)" << std::endl;
    }
};

// Circle class
class Circle: public Shape
{
// Encapsulate member data including center point and radius
private:
    Point m_center;
    double m_radius;

public:
    // Default constructor for the circle - initializes a circle centred at (0, 0) with radius 1
    Circle()
        : Circle{{0.0, 0.0}, 1.0} // Delegates construction to the two-parameter constructor
    {
    }

    // Constructor intaking a center point and a radius
    Circle(const Point& center, double radius)
        : m_center{center}, m_radius{radius}
    {
        if (m_radius > 0.0) // Standard case where the radius is not zero
        {
            std::cout << "The circle has been constructed correctly" << std::endl;
        }
        else // If the radius is zero, this is not a valid circle
        {
            std::cout << "WARNING: Invalid radius - calculations will fail" << std::endl;
        }
    }

    // Return the area of the circle using the formula pi*r^2
    virtual double area() const override {return (pi * m_radius * m_radius);}
    // Return the circumference of the circle using the formula 2*pi*r
    virtual double circumference() const override {return (2.0 * pi * m_radius);}

    // Return an array of points with each corner of the bounding box
    // x coordinate of each corner determined by x at the centre +/- the radius
    // y coordinate of each corner determined by x at the centre +/- the radius
    virtual std::array<Point, 4> boundingBox() const override
    {
        return
        {
            Point {(m_center.m_x - m_radius), (m_center.m_y + m_radius)},
            Point {(m_center.m_x + m_radius), (m_center.m_y + m_radius)},
            Point {(m_center.m_x - m_radius), (m_center.m_y - m_radius)},
            Point {(m_center.m_x + m_radius), (m_center.m_y - m_radius)}
        };
    }

    // Use prior member functions to display, center point, radius,  area, circumference, and each point of the bounding box
    virtual void display() const override
    {
        std::cout << "Center point is: ";
        m_center.show();
        std::cout << "Radius is: " << m_radius << std::endl;
        std::cout << "Area is: " << this->area() << std::endl;
        std::cout << "Circumference is: " << this->circumference() << std::endl;
        std::cout << "Bounding box around the circle is..." << std::endl;
        for (const Point& point : this->boundingBox())
        {
            point.show();
        }
    }
};

// Rectangle class
// Instructions in this class work if and only if the inputted coordinates form an axis-aligned rectangle
class Rectangle: public Shape
{
// Encapsulate member variables for vertex points
// Instantiate four vertices
private:
    Point m_pointTL;
    Point m_pointTR;
    Point m_pointBL;
    Point m_pointBR;

public:
    // Default constructor for rectangle objects
    // Creates a 2x2 square centred at (0, 0)
    Rectangle()
        : Rectangle {Point {-1, 1}, Point {1, 1}, Point {-1, -1}, Point {1, -1}} // Delegate construction to 4 parameter constructor
    {
    }

    // Constructor for rectangle objects
    // Intakes four points
    // Input order requires top left, top right, bottom left, bottom right
    /*
        In order to verify that a valid rectangle/square is being created, we must verify the following:
        (making abbreviations i.e. top left = TL)
        - TL.x is less than BR.x and TL.y is greater than BR.y
        - BL.x equals TL.x and BL.y equals BR.y
        - TR.x equals BR.x and TR.y equals TL.y
    */
    Rectangle(const Point& pointTL, const Point& pointTR, const Point& pointBL, const Point& pointBR)
        : m_pointTL{pointTL}, m_pointTR{pointTR}, m_pointBL{pointBL}, m_pointBR{pointBR}
    {
        // A subtraction method is used to check for equality
        // This eliminates an issue involving floating point equality where for example 0.0001 == 0 may evaluate to true
        if
        (
            (pointTL.m_x < pointBR.m_x) && (pointTL.m_y > pointBR.m_y) &&
            (pointBL.m_x == pointTL.m_x) && (pointBL.m_y == pointBR.m_y) &&
            (pointTR.m_x == pointBR.m_x) && (pointTR.m_y == pointTL.m_y)
        )
        {
            if ((pointTR.m_x - pointTL.m_x) == (pointTR.m_y - pointBR.m_y))
            {
                std::cout << "The rectangle has been constructed correctly. It is a square" << std::endl;
            }
            else
            {
                std::cout << "The rectangle has been constructed correctly. It is an actual rectangle" << std::endl;
            }
        }
        else
        {
            std::cout << "WARNING: Invalid rectangular points have been provided - calculations will fail" << std::endl;
        }
    }

    // Calculates the rectangle/square's area
    // Uses formula distance(TR, TL) * distance(TR, BR)
    // Equivalently l * w
    virtual double area() const override
    {
        return (m_pointTR.m_x - m_pointTL.m_x) * (m_pointTR.m_y - m_pointBR.m_y);
    }

    // Calculates the rectangle/square's perimeter
    // Uses formula (2 * distance(TR, TL)) + (2 * distance(TR, BR))
    // Equivalently 2 * l + 2 * w
    virtual double circumference() const override
    {
        return (2 * (m_pointTR.m_x - m_pointTL.m_x)) + (2 * (m_pointTR.m_y - m_pointBR.m_y));
    }

    // Returns an array containing the bounding box coordinates
    // However, the bounding box is just the four verticies of the rectangle
    virtual std::array<Point, 4> boundingBox() const override
    {
        return {m_pointTL, m_pointTR, m_pointBL, m_pointBR};
    }

    // Uses prior member functions to display length (vertical), width (horizontal), area, circumference, and bounding box coordinates
    virtual void display() const override
    {
        std::cout << "Length is: " << (m_pointTR.m_y - m_pointBR.m_y) << std::endl;
        std::cout << "Width is: " << (m_pointTR.m_x - m_pointTL.m_x) << std::endl;
        std::cout << "Area is: " << this->area() << std::endl;
        std::cout << "Perimeter is: " << this->circumference() << std::endl;
        std::cout << "Bounding box around the rectangle is..." << std::endl;
        for (const Point& point : this->boundingBox())
        {
            point.show();
        }
    }
};

// Triangle class
// Instructions in this class only work assuming that the points are not co-linear
class Triangle: public Shape
{
// Encapsulate member data for vertecies
// Instantiate three vertices
private:
    Point m_point1;
    Point m_point2;
    Point m_point3;

public:
    // Default constructor for triangles
    // Creates a triangle with points at (0, 0), (1, 1), and (1, 0)
    Triangle()
        : Triangle {Point {0, 0}, Point {1, 1}, Point {1, 0}} // Delegate construction to three parameter constructor
    {
    }

    // Constructor for Triangle objects
    // Intakes three points
    Triangle(const Point& point1, const Point& point2, const Point& point3)
        : m_point1{point1}, m_point2{point2}, m_point3{point3}
    {
        // Points do not need to be inputted in any particular order
        // To determine if the inputted points form a valid triangle, we only need to confirm that no two points are the same
        // Perform three comparisons: point 1 to point 2, point 1 to point 3, and point 2 to point 3
        if
        (
            ((m_point1.m_x == m_point2.m_x) && (m_point1.m_y == m_point2.m_y)) ||
            ((m_point1.m_x == m_point3.m_x) && (m_point1.m_y == m_point3.m_y)) ||
            ((m_point2.m_x == m_point3.m_x) && (m_point2.m_y == m_point3.m_y))
        )
        {
            std::cout << "WARNING: Invalid triangular points have been provided - calculations will fail" << std::endl;
        }
        else
        {

            std::cout << "The triangle has been constructed correctly." << std::endl;
        }
    }

    // Calculate's the triangle's area
    // Uses the Shoelace formula to calculate area(handles any orientation triangle)
    virtual double area() const override
    {
        return (0.5 * std::abs(
            m_point1.m_x * (m_point2.m_y - m_point3.m_y) +
            m_point2.m_x * (m_point3.m_y - m_point1.m_y) +
            m_point3.m_x * (m_point1.m_y - m_point2.m_y)
        ));
    }

    // Calculate the triangle's perimeter
    // Sum up the distance between each point
    virtual double circumference() const override
    {
        return (
            // Distance between point 1 and point 2
            std::sqrt(std::pow((m_point1.m_x - m_point2.m_x), 2) + std::pow((m_point1.m_y - m_point2.m_y), 2)) +
            // Distance between point 1 and point 3
            std::sqrt(std::pow((m_point1.m_x - m_point3.m_x), 2) + std::pow((m_point1.m_y - m_point3.m_y), 2)) +
            // Distance between point 2 and point 3
            std::sqrt(std::pow((m_point2.m_x - m_point3.m_x), 2) + std::pow((m_point2.m_y - m_point3.m_y), 2))
        );
    }

    // Returns an array containing the bounding box coordinates
    // Since the three points are unordered, simply take the max/min of the x/y variables
    virtual std::array<Point, 4> boundingBox() const override
    {
        double xMin{std::min({m_point1.m_x, m_point2.m_x, m_point3.m_x})}; // Determine smallest x value
        double xMax{std::max({m_point1.m_x, m_point2.m_x, m_point3.m_x})}; // Determine largest x value
        double yMin{std::min({m_point1.m_y, m_point2.m_y, m_point3.m_y})}; // Determine smallest y value
        double yMax{std::max({m_point1.m_y, m_point2.m_y, m_point3.m_y})}; // Determine largest y value

        return
        {
            Point {xMin, yMax},
            Point {xMax, yMax},
            Point {xMin, yMin},
            Point {xMax, yMin}
        };
    }

    virtual void display() const override
    {
        // Uses prior member functions to display area, circumference, and bounding box coordinates
        std::cout << "Area is: " << this->area() << std::endl;
        std::cout << "Perimeter is: " << this->circumference() << std::endl;
        std::cout << "Bounding box around the triangle is..." << std::endl;
        for (const Point& point : this->boundingBox())
        {
            point.show();
        }
    }
};


int main()
{
    // Create many instances of shape objects
    std::cout << "Circle 1 (valid)" << std::endl;
    Circle validCircle(Point{2.5, 3.1}, 4.75);
    validCircle.display();

    createDivider();

    std::cout << "Circle 2 (invalid)" << std::endl;
    Circle invalidCircle(Point{0.0, 0.0}, 0.0);
    invalidCircle.display();

    createDivider();

    std::cout << "Circle 3 (valid, default)" << std::endl;
    Circle defaultCircle;
    defaultCircle.display();

    createDivider();

    std::cout << "Rectangle 1 (valid)" << std::endl;
    Rectangle rectangle(Point{1.2, 5.6}, Point{4.8, 5.6}, Point{1.2, 1.1}, Point{4.8, 1.1});
    rectangle.display();

    createDivider();

    std::cout << "Rectangle 2 (invalid)" << std::endl;
    Rectangle invalidRect(Point{1.1, 1.1}, Point{1.1, 1.1}, Point{1.1, 1.1}, Point{1.1, 1.1});
    invalidRect.display();

    createDivider();

    std::cout << "Rectangle 3 (valid, default)" << std::endl;
    Rectangle defaultRectangle;
    defaultRectangle.display();

    createDivider();

    std::cout << "Rectangle 4 (valid)" << std::endl;
    Rectangle square(Point{-2.0, 2.0}, Point{2.0, 2.0}, Point{-2.0, -2.0}, Point{2.0, -2.0});
    square.display();

    createDivider();

    std::cout << "Triangle 1 (valid)" << std::endl;
    Triangle validTriangle(Point{-3.0, -2.0}, Point{4.4, -1.2}, Point{1.0, 5.9});
    validTriangle.display();

    createDivider();

    std::cout << "Triangle 2 (invalid)" << std::endl;
    Triangle invalidTriangle(Point{1.5, 1.5}, Point{1.5, 1.5}, Point{3.7, 4.2});
    invalidTriangle.display();

    createDivider();

    std::cout << "Triangle 3 (valid)" << std::endl;
    Triangle complexTriangle(Point{-4.1, -3.3}, Point{-1.6, -5.2}, Point{-2.9, -1.1});
    complexTriangle.display();

    createDivider();

    std::cout << "Triangle 4 (valid, default)" << std::endl;
    Triangle defaultTriangle;
    defaultTriangle.display();

    return 0;
}

