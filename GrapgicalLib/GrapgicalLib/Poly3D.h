#pragma once
#include "Line3D.h"
#include <vector>

class Poly3D
{
public:
	Poly3D(const Poly3D &p);
	Poly3D(const Line3D &l1, const Line3D &l2);
	Poly3D(const Line3D &l, const Point3D &v);
	Poly3D(const Poly3D &p, const Point3D &v);
	Poly3D(const Poly3D &p, const Line3D &l);
	Poly3D(const Poly3D &p1, const Poly3D &p2);
	friend Poly3D operator+(const Line3D &l1, const Line3D &l2);
	friend Poly3D operator+(const Line3D &l, const Point3D &v);
	friend Poly3D operator+(const Poly3D &p, const Point3D &v);
	friend Poly3D operator+(const Poly3D &p, const Line3D &l);
	friend Poly3D operator+(const Poly3D &p1, const Poly3D &p2);
	void addEdge(Point3D &source, Point3D &target);
	void connectPointToLine();
	void connectLineToLine();
	friend std::ostream &operator<<(std::ostream &oss, const Poly3D &p);

private:
	std::vector<Point3D> m_v;
};

