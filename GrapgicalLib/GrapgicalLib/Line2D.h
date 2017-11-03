#pragma once
#include "Point2D.h"

class Line2D
{
public:
	Line2D(const Point2D &p1, const Point2D &p2);	// Constructor creating a line from two points
	friend Line2D operator+(const Point2D &p1, const Point2D &p2);	// Adding two potins becomes a line 
	friend std::ostream &operator<<(std::ostream &os, const Line2D &l); // For printing an object directly
	
	// Geters for endpoints in the line
	const Point2D &getv1() const { return m_p1; };
	const Point2D &getv2() const { return m_p2; };

private:
	// Endpoints in the line
	Point2D m_p1;
	Point2D m_p2;
};