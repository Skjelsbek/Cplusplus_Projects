#pragma once
#include "Vertex.h"
#include <sstream>

Vertex::Vertex(const double &x, const double &y)
{
	m_x = new double(x);
	m_y = new double(y);
	m_z = 0;
}

Vertex::Vertex(const double &x, const double &y, const double &z)
{
	m_x = new double(x);
	m_y = new double(y);
	m_z = new double(z);
}

Vertex::Vertex(const Vertex &v)
{
	m_x = new double(*v.m_x);
	m_y = new double(*v.m_y);
	m_z = new double(*v.m_z);
}

Vertex & Vertex::operator=(const Vertex & v)
{
	m_x = new double(*v.m_x);
	m_y = new double(*v.m_y);
	m_z = new double(*v.m_z);
	return *this;
}


Vertex::~Vertex()
{
	delete m_x;
	delete m_y;
	delete m_z;
}

std::string Vertex::toString()
{
	if (m_z)
	{
		std::ostringstream oss;
		oss << "(" << *m_x << "," << *m_y << "," << *m_z << ")" << "\n";
		return oss.str();
	}
	else
	{
		std::ostringstream oss;
		oss << "(" << *m_x << "," << *m_y << ")" << "\n";
		return oss.str();
	}
}