#pragma once
#include "Point2D.h"

class Line2D
{
public:
	Line2D(const Point2D &v1, const Point2D &v2);	// Constructor creating a line from two points
	friend Line2D operator+(const Point2D &a, const Point2D &b);	// Adding two potins becomes a line 
	friend std::ostream &operator<<(std::ostream &oss, const Line2D &l); // For printing an object directly
	
	// Geters for endpoints in the line
	const Point2D &getv1() const { return m_v1; };
	const Point2D &getv2() const { return m_v2; };

private:
	// Endpoints in the line
	Point2D m_v1;
	Point2D m_v2;
};