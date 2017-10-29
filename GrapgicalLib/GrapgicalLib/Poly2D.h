#pragma once
#include "Line2D.h"
#include <vector>
#include "shellSort.h"

class Poly2D
{
public:
	Poly2D(const Poly2D &p); // Copy constructor
	Poly2D(const Line2D &l1, const Line2D &l2); // To add two lines
	Poly2D(const Line2D &l, const Point2D &v);  // To add a point to a line
	Poly2D(const Poly2D &p, const Point2D &v);	// to add a point to a polygon
	Poly2D(const Poly2D &p, const Line2D &l);	// to add a line to a polygon
	Poly2D(const Poly2D &p1, const Poly2D &p2);	// to add two polygons
	friend Poly2D operator+(const Line2D &l1, const Line2D &l2);// Adding two lines
	friend Poly2D operator+(const Line2D &l, const Point2D &v);	// Adding a point to a line	
	friend Poly2D operator+(const Poly2D &p, const Point2D &v);	// Adding a point to a polygon
	friend Poly2D operator+(const Poly2D &p, const Line2D &l);	// Adding a line to a polygon
	friend Poly2D operator+(const Poly2D &p1, const Poly2D &p2);// Adding two polygons
	
	// Methods for connecting and closing polygons 
	void addEdge(Point2D &source, Point2D &target);
	void connectPointToLine();
	void sortY();
	void connectLineToLine();

	// Overload of << operator so i can print polygon objects directly
	friend std::ostream &operator<<(std::ostream &oss, const Poly2D &p);

private:
	std::vector<Point2D> m_v; // Vector of the points contained in the polygon
};
