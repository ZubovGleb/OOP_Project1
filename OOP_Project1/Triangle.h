#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Point.h"

class Triangle
{
private:
	Point a_, b_, c_;
	float epsilon = 0.0000001;

public:
	Triangle();
	Triangle(Point a, Point b, Point c);
	Triangle(const Triangle& refTriangle);
	~Triangle();

	void setA(const Point& a);
	void setB(const Point& b);
	void setC(const Point& c);
	const Point& getA() const;
	const Point& getB() const;
	const Point& getC() const;

	bool isTriangle();
	void move(float k);
	float getPerimeter();
	bool isEqual(Triangle& refTriangle);
	float getSquare();

};

#endif TRIANGLE_H