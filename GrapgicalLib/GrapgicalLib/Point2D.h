#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <list>
#include <algorithm>

class Point2D
{
public:
	Point2D(); // Default constructor
	Point2D(const double &x, const double &y); // Constructor setting the x and y coordinates of the point
	Point2D(const Point2D &p); // Copy constructor

	void addEdge(Point2D &target); // Create an edge between two points
	void reomveEdge(Point2D &target); // Removes an edge
	bool hasEdgeTo(const Point2D &target) const; // Used to check if a point has an edge to another point
	int endgeCount() const; // Returns how many edges a point has
	
	//  Geters for a points x and y coordinates
	double getX() { return m_x; };
	double getY() { return m_y; };

	// Operator overloads to make theese operators function the way i want
	bool operator==(const Point2D &p) const;
	friend std::ostream &operator<<(std::ostream &os, const Point2D &p);
	bool Point2D::operator<(const Point2D &p) const;

private:
	std::list<Point2D> m_edges; // List of edges from the point
	double m_x;	// x coordinate of the point
	double m_y;	// y coordinate of the point
};

