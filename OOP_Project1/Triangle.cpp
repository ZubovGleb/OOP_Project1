#include "Triangle.h"
#include <iostream>
#include <cmath>

Triangle::Triangle()
{
	a_ = Point();
	b_ = Point();
	c_ = Point();
}

Triangle::Triangle(Point a, Point b, Point c)
{
	a_ = a;
	b_ = b;
	c_ = c;
}

Triangle::Triangle(const Triangle& refTriangle)
{
	a_ = refTriangle.a_;
	b_ = refTriangle.b_;
	c_ = refTriangle.c_;
}

Triangle::~Triangle() = default;

void Triangle::setA(const Point& a)
{
	a_ = a;
}

void Triangle::setB(const Point& b)
{
	b_ = b;
}

void Triangle::setC(const Point& c)
{
	c_ = c;
}

const Point& Triangle::getA() const { 
	return a_;
}

const Point& Triangle::getB() const
{
	return b_;
}

const Point& Triangle::getC() const
{
	return c_;
}

bool Triangle::isTriangle()
{
	float ab = a_.getDistance(b_);
	float ac = a_.getDistance(c_);
	float bc = b_.getDistance(c_);
	Triangle trg(a_, b_, c_);
	float square = trg.getSquare();
	return ( ab + ac > bc && ab + bc > ac && bc + ac > ab && square > epsilon);
}

void Triangle::move(float k)
{
	a_.move(k);
	b_.move(k);
	c_.move(k);
}

float Triangle::getPerimeter()
{
	return a_.getDistance(b_) + a_.getDistance(c_) + b_.getDistance(c_);
}

bool Triangle::isEqual(Triangle& refTriangle)
{
	return ((a_.isEqual(refTriangle.getA()) && (b_.isEqual(refTriangle.getB()) && c_.isEqual(refTriangle.getC()) 
		|| b_.isEqual(refTriangle.getC()) && c_.isEqual(refTriangle.getB()) ) ) || ((a_.isEqual(refTriangle.getB()))
		&& (b_.isEqual(refTriangle.getA()) && c_.isEqual(refTriangle.getC()) || b_.isEqual(refTriangle.getC()) 
		&& c_.isEqual(refTriangle.getA()))) || ((a_.isEqual(refTriangle.getC())) && (b_.isEqual(refTriangle.getB()) 
		&& c_.isEqual(refTriangle.getA()) || b_.isEqual(refTriangle.getA()) && c_.isEqual(refTriangle.getB()))));
}

float Triangle::getSquare()
{
	return abs( (a_.getX() - c_.getX()) * (b_.getY() - c_.getY()) - (b_.getX() - c_.getX()) * (a_.getY() - c_.getY()) ) / 2;
}

