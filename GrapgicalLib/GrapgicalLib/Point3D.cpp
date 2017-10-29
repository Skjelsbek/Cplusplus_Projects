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

Point3D::Point3D(const Point3D &v)
{
	m_x = v.m_x;
	m_y = v.m_y;
	m_z = v.m_z;
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

Point3D &Point3D::operator=(const Point3D &v)
{
	m_x = v.m_x;
	m_y = v.m_y;
	m_z = v.m_z;
	return *this;
}

bool Point3D::operator==(const Point3D &v) const
{
	if (m_x == v.m_x && m_y == v.m_y && m_z == v.m_z)
	{
		return true;
	}
	return false;
}

std::ostream &operator<<(std::ostream &oss, const Point3D &v)
{
	oss << "(" << v.m_x << "," << v.m_y << "," << v.m_z << ")";
	return oss;
}
