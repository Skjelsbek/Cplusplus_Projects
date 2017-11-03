#include "Poly3D.h"

Poly3D::Poly3D(const Poly3D &po)
{
	m_p = po.m_p;
}

Poly3D::Poly3D(const Line3D &l1, const Line3D &l2)
{
	m_p.push_back(l1.getv1());
	m_p.push_back(l1.getv2());
	m_p.push_back(l2.getv1());
	m_p.push_back(l2.getv2());	
}

Poly3D::Poly3D(const Line3D &l, const Point3D &p)
{
	// Separate vertexes and put them in the m_p Vector
	m_p.push_back(l.getv1());
	m_p.push_back(l.getv2());
	m_p.push_back(p);
}

Poly3D::Poly3D(const Poly3D &po, const Point3D &p)
{
	m_p = po.m_p;
	m_p.push_back(p);
}

Poly3D::Poly3D(const Poly3D &po, const Line3D &l)
{
	m_p = po.m_p;
	m_p.push_back(l.getv1());
	m_p.push_back(l.getv2());
}

Poly3D::Poly3D(const Poly3D &po1, const Poly3D &po2)
{
	m_p = po1.m_p;
	m_p.insert(m_p.end(), po2.m_p.begin(), po2.m_p.end());
}

Poly3D operator+(const Line3D &l1, const Line3D &l2)
{
	Poly3D poly(l1, l2);
	return poly;
}

Poly3D operator+(const Line3D &l, const Point3D &p)
{
	Poly3D poly(l, p);
	return poly;
}

Poly3D operator+(const Poly3D &po, const Point3D &p)
{
	Poly3D poly(po, p);
	return poly;
}

Poly3D operator+(const Poly3D &po, const Line3D &l)
{
	Poly3D poly(po, l);
	return poly;
}

Poly3D operator+(const Poly3D &po1, const Poly3D &po2)
{
	Poly3D poly(po1, po2);
	return poly;
}

std::ostream &operator<<(std::ostream &os, const Poly3D &po)
{
	os << "[";
	for (int i = 0; i < po.m_p.size(); i++)
	{
		os << po.m_p[i];
		if (i != po.m_p.size() - 1)
		{
			os << ", ";
		}
	}
	os << "]";
	return os;
}