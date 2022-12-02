#include "Point.h"
#include <iostream>
#include <cmath>


Point::Point()
{
	x_ = 0;
	y_ = 0;
}

Point::Point(float x, float y)
{
	x_ = x;
	y_ = y;
}

Point::Point(const Point& refPoint)
{
	x_ = refPoint.x_;
	y_ = refPoint.y_;
}

Point::~Point() = default;


void Point::setX(float x)
{
	x_ = x;
}

void Point::setY(float y)
{
	y_ = y;
}

float Point::getX() const
{
	return x_;
}

float Point::getY() const
{
	return y_;
}

bool Point::isEqual(const Point& refPoint)
{
	return (abs(x_ - refPoint.x_) < epsilon && abs(y_ - refPoint.y_) < epsilon);
}

float Point::getDistance(const Point& refPoint)
{
	return sqrt( (x_ - refPoint.x_) * (x_ - refPoint.x_) + (y_ - refPoint.y_) * (y_ - refPoint.y_) );
}

void Point::move(float k)
{
	x_ += k;
	y_ += k;
}



