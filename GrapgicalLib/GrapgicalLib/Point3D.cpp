#pragma once
#include "Point3D.h"

Point3D::Point3D() {
}

Point3D::Point3D(const double &x, const double &y, const double &z)
{
	m_x = x;
	m_y = y;
	m_z = z;
}

Point3D::Point3D(const Point3D &p)
{
	m_x = p.m_x;
	m_y = p.m_y;
	m_z = p.m_z;
}

void Point3D::addEdge(Point3D &target)
{
	m_edges.push_back(target);
}

void Point3D::reomveEdge(Point3D &target)
{
	m_edges.remove(target);
	target.m_edges.remove(*this);
}

bool Point3D::operator==(const Point3D &p) const
{
	if (m_x == p.m_x && m_y == p.m_y && m_z == p.m_z)
	{
		return true;
	}
	return false;
}

std::ostream &operator<<(std::ostream &os, const Point3D &p)
{
	os << "(" << p.m_x << "," << p.m_y << "," << p.m_z << ")";
	return os;
}
