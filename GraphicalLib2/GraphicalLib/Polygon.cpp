#include "Polygon.h"

Polygon::Polygon(const Polygon &p)
{
	m_v = new Vertex[p.m_size];
	for (int i = 0; i < p.m_size; i++)
	{
		m_v[i] = p.m_v[i];
	}
	m_size = p.m_size;
}

Polygon &Polygon::operator=(const Polygon &p)
{
	delete []m_v;
	m_v = new Vertex[p.m_size];
	for (int i = 0; i < p.m_size; i++)
	{
		m_v[i] = p.m_v[i];
	}
	m_size = p.m_size;
	return *this;
}

Polygon::Polygon(const Line &l1, const Line &l2) {
	m_v = new Vertex[4];
	m_v[0] = l1.getv1();
	m_v[1] = l1.getv2();
	m_v[2] = l2.getv1();
	m_v[3] = l2.getv2();
	m_size = 4;
}

Polygon::Polygon(const Line &l, const Vertex &v) {
	m_v = new Vertex[3];
	m_v[0] = l.getv1();
	m_v[1] = l.getv2();
	m_v[2] = v;	
	m_size = 3;
}

Polygon::Polygon(const Polygon &p, const Vertex &v) {
	m_v = new Vertex[p.m_size + 1];
	int i;
	for (i = 0; i < p.m_size; i++)
	{		
		m_v[i] = p.m_v[i];
	}
	m_v[i] = v;
	m_size = p.m_size + 1;
}

Polygon::Polygon(const Polygon &p, const Line &l) {
	m_v = new Vertex[p.m_size + 2];
	int i;
	for (i = 0; i < p.m_size; i++)
	{
		m_v[i] = p.m_v[i];
	}
	m_v[i] = l.getv1();
	m_v[i + 1] = l.getv2();
	m_size = p.m_size + 2;
}

Polygon::Polygon(const Polygon &p1, const Polygon &p2) {
	m_v = new Vertex[p1.m_size + p2.m_size];

	for (int i = 0; i < p1.m_size; i++)
	{
		m_v[i] = p1.m_v[i];
	}

	for (int i = 0; i < p2.m_size; i++)
	{
		m_v[i + p1.m_size] = p2.m_v[i];
	}
	m_size = p1.m_size + p2.m_size;
}

Polygon operator+(const Line &l1, const Line &l2)
{
	Polygon p(l1, l2);
	return p;
}

Polygon operator+(const Line &l, const Vertex &v)
{
	Polygon p(l, v);
	return p;
}

Polygon operator+(const Polygon &p, const Vertex &v)
{
	Polygon po(p, v);
	return po;
}

Polygon operator+(const Polygon &p, const Line &l)
{
	Polygon po(p, l);
	return po;
}

Polygon operator+(const Polygon &p1, const Polygon &p2)
{
	Polygon p(p1, p2);
	return p;
}

std::ostream &operator<<(std::ostream &oss, const Polygon &p)
{
	oss << "[";
	for (int i = 0; i < p.m_size; i++)
	{
		oss << p.m_v[i];
		if (i != p.m_size - 1)
		{
			oss << ", ";
		}
	}
	oss << "]";
	return oss;
}

Polygon::~Polygon()
{
	delete []m_v;
}