#include "Line3D.h"

Line3D::Line3D(const Point3D &p1, const Point3D &p2)
{
	m_p1 = p1;
	m_p2 = p2;
}

Line3D operator+(const Point3D &p1, const Point3D &p2)
{
	Line3D l(p1, p2);
	return l;
}

std::ostream &operator<<(std::ostream &os, const Line3D &l)
{
	os << "[" << l.getv1() << "," << l.getv2() << "]";
	return os;
}