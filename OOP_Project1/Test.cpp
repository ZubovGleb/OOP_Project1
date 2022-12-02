#include <iostream>
#include "Point.h"
#include "Triangle.h"

bool isPointInCircle(float r, const Point& point);
Point inputPoint(std::istream& input);
void outputPoint(std::ostream& output, const Point& point);
bool isEqualSquare(Triangle& trg1, Triangle& trg2);
void outputTriangle(std::ostream& output, Triangle& trg);


int main() 
{
    std::cout << "----------Test class Point---------- \n";
    std::cout << "Enter the coordinates of the points (the sign of the end of the sequence is a point with coordinates (0; 0)) \n";
    float minDistance = 1e16, k = 19.4, r = 100;
    Point point(0, 0), testPoint(19, 13), result(0, 0), origin(0, 0);
    int count = 0;
    while (true) {
        point = inputPoint(std::cin);
        try {
            if (!std::cin.good() || std::cin.peek() != '\n') {
                throw std::runtime_error("Incorrect input, the coordinates must be set as float");
            }
        }
        catch (std::exception const& e) {
            std::cerr << "ERROR: " << e.what() << "\n";
            return 1;
        }

        if (point.getX() == 0 && point.getY() == 0) {
            break;
        }
        if (minDistance > point.getDistance(origin)) {
            minDistance = point.getDistance(origin);
            result = point;
        }

        point.~Point();
        count++;
    }
    try {
        if (count == 0) {
            throw std::runtime_error("The sequence cannot be empty");
        }
    }
    catch (std::exception const& e) {
        std::cerr << "ERROR: " << e.what() << "\n";
        return 2;
    }
    std::cout << "The point closest to (0; 0): ";  outputPoint(std::cout, result); std::cout << '\n';
    std::cout << "Enter the coordinates of the point to check the functions and methods:\n";
    point = inputPoint(std::cin);
    try {
        if (!std::cin.good() || std::cin.peek() != '\n') {
            throw std::runtime_error("Incorrect input, the coordinates must be set as float");
        }
    }
    catch (std::exception const& e) {
        std::cerr << "ERROR: " << e.what() << "\n";
        return 1;
    }
    std::cout << "Does the point fall into a circle with a radius " << r << "? Result: " << isPointInCircle(r, point) << '\n';

    std::cout << "Is equal with ";
    outputPoint(std::cout, testPoint);
    std::cout << "? Result : " << point.isEqual(testPoint) << '\n';
    
    std::cout << "Distance to ";
    outputPoint(std::cout, testPoint);
    std::cout << ": " << point.getDistance(testPoint) << '\n';
    
    point.move(k);
    std::cout << "Cordinates after moving to " << k << ": ";
    outputPoint(std::cout, point);
    std::cout << "\n\n";

    result.~Point();
    point.~Point();
    testPoint.~Point();

    std::cout << "----------Test class Triangle---------- \n";
    Triangle t1(Point(0, 4), Point(-3, 0), Point(0, 0));
    Triangle t2(Point(19.4, 23.4), Point(16.4, 19.4), Point(19.4, 19.4));
    Triangle t3(Point(72, 1), Point(36, 0.5), Point(-144, -2));

    std::cout << "first triangle:"; outputTriangle(std::cout, t1); std::cout << '\n';
    std::cout << "second triangle: "; outputTriangle(std::cout, t2); std::cout << '\n';
    std::cout << "third triangle: "; outputTriangle(std::cout, t3); std::cout << "\n\n";

    t1.move(k);
    std::cout << "first triangle after moving to " << k << ": "; outputTriangle(std::cout, t1); std::cout << "\n";

    std::cout << "Square of the first triangle: " << t1.getSquare() << '\n';
    std::cout << "Perimeter of the second triangle: " << t2.getPerimeter() << "\n\n";

    std::cout << "Is the first triangle a triangle?  Result: " << t1.isTriangle() << '\n';
    std::cout << "Is the third triangle a triangle? Result: " << t3.isTriangle() << "\n\n";

    std::cout << "Is the first triangle equal the second triangle? Result: " << t1.isEqual(t2) << "\n\n";

    std::cout << "Are the squares of the first and second triangles equal? Result: " << isEqualSquare(t1, t2) << '\n';
    std::cout << "Are the squares of the second and third triangles equal? Result: " << isEqualSquare(t1, t3) << "\n\n";

    t1.~Triangle();
    t2.~Triangle();
    t3.~Triangle();
    return 0;
}

bool isPointInCircle(float r, const Point& point)
{
	return (sqrt(point.getX() * point.getX() + point.getY() * point.getY())) <= r;
}
Point inputPoint(std::istream& input)
{
	float x = 0, y = 0;
	input >> x;
	input >> y;
	Point point(x, y);
	return point;
}
void outputPoint(std::ostream& output, const Point& point)
{
	output << "(" << point.getX() << "; " << point.getY() << ")";
}

bool isEqualSquare(Triangle& trg1, Triangle& trg2)
{
	return trg1.getSquare() == trg2.getSquare();
}

void outputTriangle(std::ostream& output, Triangle& trg)
{
	outputPoint(std::cout, trg.getA());
	std::cout << " ";
	outputPoint(std::cout, trg.getB());
	std::cout << " ";
	outputPoint(std::cout, trg.getC());
}