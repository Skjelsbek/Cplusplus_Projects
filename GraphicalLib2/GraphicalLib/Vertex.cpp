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

std::string Vertex::toString()
{
	if (m_z != 0)
	{
		std::ostringstream oss;
		oss << "(" << m_x << "," << m_y << "," << m_z << ")";
		return oss.str();
	}
	else
	{
		std::ostringstream oss;
		oss << "(" << m_x << "," << m_y << ")";
		return oss.str();
	}
}