#include "Poly3D.h"

Poly3D::Poly3D(const Poly3D &p)
{
	m_v = p.m_v;
}

Poly3D::Poly3D(const Line3D &l1, const Line3D &l2)
{
	m_v.push_back(l1.getv1());
	m_v.push_back(l1.getv2());
	m_v.push_back(l2.getv1());
	m_v.push_back(l2.getv2());
	connectLineToLine();
}

Poly3D::Poly3D(const Line3D &l, const Point3D &v)
{
	// Separate vertexes and put them in the m_v Vector
	m_v.push_back(l.getv1());
	m_v.push_back(l.getv2());
	m_v.push_back(v);

	connectPointToLine(); // Creates edges between vertexes to connect the polygon
}

Poly3D::Poly3D(const Poly3D &p, const Point3D &v)
{
	m_v = p.m_v;
	m_v.push_back(v);
}

Poly3D::Poly3D(const Poly3D &p, const Line3D &l)
{
	m_v = p.m_v;
	m_v.push_back(l.getv1());
	m_v.push_back(l.getv2());
}

Poly3D::Poly3D(const Poly3D &p1, const Poly3D &p2)
{
	m_v = p1.m_v;
	m_v.insert(m_v.end(), p2.m_v.begin(), p2.m_v.end());
}

Poly3D operator+(const Line3D &l1, const Line3D &l2)
{
	Poly3D p(l1, l2);
	return p;
}

Poly3D operator+(const Line3D &l, const Point3D &v)
{
	Poly3D p(l, v);
	return p;
}

Poly3D operator+(const Poly3D &p, const Point3D &v)
{
	Poly3D po(p, v);
	return po;
}

Poly3D operator+(const Poly3D &p, const Line3D &l)
{
	Poly3D po(p, l);
	return po;
}

Poly3D operator+(const Poly3D &p1, const Poly3D &p2)
{
	Poly3D p(p1, p2);
	return p;
}

void Poly3D::addEdge(Point3D &source, Point3D &target)
{
	int sourceIndex = 0, targetIndex = 0;
	for (int i = 0; i < m_v.size(); i++)
	{
		if (m_v[i] == source)
		{
			sourceIndex = i;
		}
		if (m_v[i] == target)
		{
			targetIndex = i;
		}
	}
	if (sourceIndex != targetIndex)
	{
		m_v[sourceIndex].addEdge(m_v[targetIndex]);
		m_v[targetIndex].addEdge(m_v[sourceIndex]);
	}
}

std::ostream &operator<<(std::ostream &oss, const Poly3D &p)
{
	oss << "[";
	for (int i = 0; i < p.m_v.size(); i++)
	{
		oss << p.m_v[i];
		if (i != p.m_v.size() - 1)
		{
			oss << ", ";
		}
	}
	oss << "]";
	return oss;
}

void Poly3D::connectPointToLine()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (j != i)
			{
				m_v[i].addEdge(m_v[j]);
			}
		}
	}
}

void Poly3D::connectLineToLine()
{
	for (int i = 0; i < m_v.size(); i++)
	{

	}
}