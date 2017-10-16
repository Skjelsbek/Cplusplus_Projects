#include "Line.h"

Line::Line( const Vertex &v1, const Vertex &v2)
{
	m_v1 = new Vertex(v1);
	m_v2 = new Vertex(v2);
}

Line::Line(const Line &l)
{
	m_v1 = new Vertex(*l.m_v1);
	m_v2 = new Vertex(*l.m_v2);
}

Line::~Line()
{
	delete m_v1;
	delete m_v2;
}

Line & Line::operator=(const Line &l)
{
	m_v1 = new Vertex(*l.m_v1);
	m_v2 = new Vertex(*l.m_v2);
	return *this;
}

Line operator+(const Vertex &a, const Vertex &b)
{
	Line l(a, b);
	return l;
}


