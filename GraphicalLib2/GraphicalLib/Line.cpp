#include "Line.h"

Line::Line(const Vertex &v1, const Vertex &v2)
{
	m_v1 = v1;
	m_v2 = v2;
}

std::string Line::toString()
{
	std::ostringstream oss;
	oss << "[" << m_v1.toString() << "," << m_v2.toString() << "]";
	return oss.str();
}

Line operator+(const Vertex &a, const Vertex &b)
{
	Line l(a, b);
	return l;
}

const Vertex &Line::getv1() const
{
	return m_v1;
}

const Vertex &Line::getv2() const
{
	return m_v2;
}