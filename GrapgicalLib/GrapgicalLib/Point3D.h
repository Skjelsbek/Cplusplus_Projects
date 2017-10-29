#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <list>

class Point3D
{
public:
	Point3D();
	Point3D(const double &x, const double &y, const double &z);
	Point3D(const Point3D &v);
	void addEdge(Point3D &target);
	void reomveEdge(Point3D & target);
	double getX() { return m_x; };
	double getY() { return m_y; };
	Point3D &operator=(const Point3D &v);
	bool operator==(const Point3D & v) const;
	friend std::ostream &operator<<(std::ostream &o, const Point3D &v);

private:
	std::list<Point3D> m_edges;
	double m_x;
	double m_y;
	double m_z;
};

