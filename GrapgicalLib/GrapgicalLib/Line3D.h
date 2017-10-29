#pragma once
#include "Point3D.h"

class Line3D
{
public:
	Line3D(const Point3D &v1, const Point3D &v2);
	friend Line3D operator+(const Point3D &a, const Point3D &b);
	friend std::ostream &operator<<(std::ostream &oss, const Line3D &l);
	const Point3D &getv1() const { return m_v1; };
	const Point3D &getv2() const { return m_v2; };

private:
	Point3D m_v1;
	Point3D m_v2;
};