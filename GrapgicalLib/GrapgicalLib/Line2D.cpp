#include "Line2D.h"

Line2D::Line2D(const Point2D &v1, const Point2D &v2)
{
	// Storing both parameter points as endpoints in the line 
	m_v1 = v1;
	m_v2 = v2;
}

Line2D operator+(const Point2D &a, const Point2D &b)
{
	Line2D l(a, b);
	return l;
}

// Returns a ostream containing both points in square brackets
std::ostream &operator<<(std::ostream &oss, const Line2D &l)
{
	oss << "[" << l.getv1() << "," << l.getv2() << "]";
	return oss;
}