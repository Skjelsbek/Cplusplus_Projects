#include "Poly2D.h"

Poly2D::Poly2D(const Poly2D &po)
{
	// Copying the points contained in the polygon to the new one
	m_p = po.m_p;
}

Poly2D::Poly2D(const Line2D &l1, const Line2D &l2)
{
	// Adding the points contained in each line to the Vector containing the polygon points
	m_p.push_back(l1.getv1());
	m_p.push_back(l1.getv2());
	m_p.push_back(l2.getv1());
	m_p.push_back(l2.getv2());

	connectLineToLine(); // Adding edges between all the points to connect and close the polygon
}

Poly2D::Poly2D(const Line2D &l, const Point2D &p)
{
	// Separate points and put them in the m_p Vector
	m_p.push_back(l.getv1());
	m_p.push_back(l.getv2());
	m_p.push_back(p);

	connectPointToLine(); // Creates edges between points to connect and close the polygon
}

Poly2D::Poly2D(const Poly2D &po, const Point2D &p)
{
	// Adding the point to the polygon
	m_p = po.m_p;
	m_p.push_back(p);
}

Poly2D::Poly2D(const Poly2D &po, const Line2D &l)
{
	// Adding the outer points of the line to the polygon
	m_p = po.m_p;
	m_p.push_back(l.getv1());
	m_p.push_back(l.getv2());
}

Poly2D::Poly2D(const Poly2D &po1, const Poly2D &po2)
{
	// Merging two polygons
	m_p = po1.m_p;
	m_p.insert(m_p.end(), po2.m_p.begin(), po2.m_p.end());
}

Poly2D operator+(const Line2D &l1, const Line2D &l2)
{
	Poly2D poly(l1, l2);
	return poly;
}

Poly2D operator+(const Line2D &l, const Point2D &p)
{
	Poly2D poly(l, p);
	return poly;
}

Poly2D operator+(const Poly2D &po, const Point2D &p)
{
	Poly2D poly(po, p);
	return poly;
}

Poly2D operator+(const Poly2D &po, const Line2D &l)
{
	Poly2D poly(po, l);
	return poly;
}

Poly2D operator+(const Poly2D &po1, const Poly2D &po2)
{
	Poly2D poly(po1, po2);
	return poly;
}

// Getting the index of both source and target points in the vector,
// and adds an edge between theese two points
void Poly2D::addEdge(Point2D &source, Point2D &target)
{
	int sourceIndex = 0, targetIndex = 0;
	for (size_t i = 0; i < m_p.size(); i++)
	{
		if (m_p[i] == source)
		{
			sourceIndex = i;
		}
		if (m_p[i] == target)
		{
			targetIndex = i;
		}
	}
	if (sourceIndex != targetIndex)
	{
		m_p[sourceIndex].addEdge(m_p[targetIndex]);
	}
}

// Adding edges in both directions between all points in the polygon
// This is used when adding a point to a line
void Poly2D::connectPointToLine()
{
	m_p[0].addEdge(m_p[1]);
	m_p[0].addEdge(m_p[2]);
	m_p[1].addEdge(m_p[2]);
}

// This method uses shell sort to sort the points in the polygon with respect to the y-coordinate
void Poly2D::sortY()
{
	shellSort::shellSort(&m_p[0], m_p.size());
}

void Poly2D::connectLineToLine()
{
	sortY(); // Sorting the vector to easily add edges

	for (size_t i = 0; i < m_p.size() - 1; i++)
	{
		// If the edge count for the point is 2 or higher, we don't want to add an edge from this point
		if (m_p[i].endgeCount() < 2) {

			/*
			* If the point at index i already has an edge to the next point, we know that both point are part of
			* one of the lines we're connecting, so we rather want to connect to the next point.
			* Also if the point we're trying to make an edge to already has two edges,
			* we know that the other point in the line has already connected to it, so we want to connect it to the next instead.
			*/
			if (m_p[i].hasEdgeTo(m_p[i + 1]) || m_p[i + 1].endgeCount() >= 2)
			{
				m_p[i].addEdge(m_p[i + 2]);
			}
			else
			{
				m_p[i].addEdge(m_p[i + 1]);
			}
		}		
	}
}

// Returns every point in the polygon within square brackets as a ostream
std::ostream &operator<<(std::ostream &os, const Poly2D &po)
{
	os << "[";
	for (size_t i = 0; i < po.m_p.size(); i++)
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