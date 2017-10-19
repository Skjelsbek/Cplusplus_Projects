#pragma once
#include "Vertex.h"

Vertex::Vertex() {
}

Vertex::Vertex(const double &x, const double &y)
{
	m_x = x;
	m_y = y;
	m_z = 0;
}

Vertex::Vertex(const double &x, const double &y, const double &z)
{
	m_x = x;
	m_y = y;
	m_z = z;
}

Vertex::Vertex(const Vertex &v)
{
	m_x = v.m_x;
	m_y = v.m_y;
	m_z = v.m_z;
}

Vertex &Vertex::operator=(const Vertex &v)
{
	m_x = v.m_x;
	m_y = v.m_y;
	m_z = v.m_z;
	return *this;
}

std::ostream &operator<<(std::ostream &oss, const Vertex &v)
{
	if (v.m_z != 0)
	{
		oss << "(" << v.m_x << "," << v.m_y << "," << v.m_z << ")";		
	}
	else
	{
		oss << "(" << v.m_x << "," << v.m_y << ")";
	}
	return oss;
}
