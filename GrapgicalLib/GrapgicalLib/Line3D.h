#pragma once
#include "Point3D.h"

class Line3D
{
public:
	Line3D(const Point3D &p1, const Point3D &p2);
	friend Line3D operator+(const Point3D &p1, const Point3D &p2);
	friend std::ostream &operator<<(std::ostream &os, const Line3D &l);
	const Point3D &getv1() const { return m_p1; };
	const Point3D &getv2() const { return m_p2; };

private:
	Point3D m_p1;
	Point3D m_p2;
};