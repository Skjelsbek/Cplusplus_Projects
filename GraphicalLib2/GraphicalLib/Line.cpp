#include "Line.h"

Line::Line(const Vertex &v1, const Vertex &v2)
{
	m_v1 = v1;
	m_v2 = v2;
}

Line operator+(const Vertex &a, const Vertex &b)
{
	Line l(a, b);
	return l;
}

std::ostream &operator<<(std::ostream &oss, const Line &l)
{
	oss << "[" << l.getv1() << "," << l.getv2() << "]";
	return oss;
}


const Vertex &Line::getv1() const
{
	return m_v1;
}

const Vertex &Line::getv2() const
{
	return m_v2;
}