#include "Line3D.h"

Line3D::Line3D(const Point3D &v1, const Point3D &v2)
{
	m_v1 = v1;
	m_v2 = v2;
}

Line3D operator+(const Point3D &a, const Point3D &b)
{
	Line3D l(a, b);
	return l;
}

std::ostream &operator<<(std::ostream &oss, const Line3D &l)
{
	oss << "[" << l.getv1() << "," << l.getv2() << "]";
	return oss;
}