#include "Line2D.h"

Line2D::Line2D(const Point2D &p1, const Point2D &p2)
{
	// Storing both parameter points as endpoints in the line 
	m_p1 = p1;
	m_p2 = p2;
}

Line2D operator+(const Point2D &p1, const Point2D &p2)
{
	Line2D l(p1, p2);
	return l;
}

// Returns a ostream containing both points in square brackets
std::ostream &operator<<(std::ostream &os, const Line2D &l)
{
	os << "[" << l.getv1() << "," << l.getv2() << "]";
	return os;
}