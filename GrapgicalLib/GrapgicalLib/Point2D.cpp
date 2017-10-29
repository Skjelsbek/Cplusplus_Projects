#pragma once
#include "Point2D.h"

Point2D::Point2D() {
}

Point2D::Point2D(const double &x, const double &y)
{
	m_x = x;
	m_y = y;
}

Point2D::Point2D(const Point2D &v)
{
	m_x = v.m_x;
	m_y = v.m_y;
}

void Point2D::addEdge(Point2D &target)
{
	m_edges.push_back(target);
	target.m_edges.push_back(*this);
}

void Point2D::reomveEdge(Point2D &target)
{
	m_edges.remove(target);
	target.m_edges.remove(*this);
}

bool Point2D::hasEdgeTo(const Point2D &target) const
{
	// Using find algorithm to check if it finds the point in the edges list
	bool found = (std::find(m_edges.begin(), m_edges.end(), target) != m_edges.end());
	return found;
}

int Point2D::endgeCount() const
{
	return m_edges.size();
}

Point2D &Point2D::operator=(const Point2D &v)
{
	m_x = v.m_x;
	m_y = v.m_y;
	return *this;
}

bool Point2D::operator==(const Point2D &v) const
{
	if (m_x == v.m_x && m_y == v.m_y)
	{
		return true;
	}
	return false;
}

// Returns a ostream containing bot the x and the y coordinate of a point in brackets
std::ostream &operator<<(std::ostream &oss, const Point2D &v)
{
	oss << "(" << v.m_x << "," << v.m_y << ")";
	return oss;
}

/*
	I want to sort with regard to y to make it easier to connect two lines,
	so i overload the less than operator to be able to compare the y values.
*/
bool Point2D::operator<(const Point2D &p) const
{
	if (m_y < p.m_y) 
	{
		return true;
	}
	return false;
}
