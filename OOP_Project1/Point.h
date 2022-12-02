#ifndef POINT_H
#define POINT_H

class Point
{
private:
	float x_;
	float y_;
	float epsilon = 0.0000001;

public:
	Point();
	Point(float x, float y);
	Point(const Point& refPoint);
	~Point();

	void setX(float x);
	void setY(float y);
	float getX() const;
	float getY() const;

	bool isEqual(const Point& refPoint);
	float getDistance(const Point& refPoint);
	void move(float k);
};

#endif POINT_H