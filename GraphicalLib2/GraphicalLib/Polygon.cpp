#include "Polygon.h"

Polygon::Polygon(const Polygon &p)
{
	m_v = p.m_v;
}

Polygon::Polygon(const Line &l1, const Line &l2) 
{
	m_v.push_back(l1.getv1());
	m_v.push_back(l1.getv2());
	m_v.push_back(l2.getv1());
	m_v.push_back(l2.getv2());
	connectLineToLine();
}

Polygon::Polygon(const Line &l, const Vertex &v) 
{
	// Separate vertexes and put them in the m_v Vector
	m_v.push_back(l.getv1());
	m_v.push_back(l.getv2());
	m_v.push_back(v);

	connectPointToLine(); // Creates edges between vertexes to connect the polygon
}

Polygon::Polygon(const Polygon &p, const Vertex &v) 
{
	m_v = p.m_v;
	m_v.push_back(v);
}

Polygon::Polygon(const Polygon &p, const Line &l) 
{
	m_v = p.m_v;
	m_v.push_back(l.getv1());
	m_v.push_back(l.getv2());
}

Polygon::Polygon(const Polygon &p1, const Polygon &p2) 
{
	m_v = p1.m_v;
	m_v.insert(m_v.end(), p2.m_v.begin(), p2.m_v.end());
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

void Polygon::addEdge(Vertex &source, Vertex &target) 
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

std::ostream &operator<<(std::ostream &oss, const Polygon &p)
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

void Polygon::connectPointToLine() 
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

void Polygon::connectLineToLine()
{
	for (int i = 0; i < m_v.size(); i++)
	{

	}
}