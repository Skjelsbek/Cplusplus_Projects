#pragma once
#include "Line3D.h"
#include <vector>

class Poly3D
{
public:
	Poly3D(const Poly3D &po);
	Poly3D(const Line3D &l1, const Line3D &l2);
	Poly3D(const Line3D &l, const Point3D &p);
	Poly3D(const Poly3D &po, const Point3D &p);
	Poly3D(const Poly3D &po, const Line3D &l);
	Poly3D(const Poly3D &po1, const Poly3D &po2);
	friend Poly3D operator+(const Line3D &l1, const Line3D &l2);
	friend Poly3D operator+(const Line3D &l, const Point3D &p);
	friend Poly3D operator+(const Poly3D &po, const Point3D &p);
	friend Poly3D operator+(const Poly3D &po, const Line3D &l);
	friend Poly3D operator+(const Poly3D &po1, const Poly3D &po2);
	friend std::ostream &operator<<(std::ostream &os, const Poly3D &po);

private:
	std::vector<Point3D> m_p;
};

