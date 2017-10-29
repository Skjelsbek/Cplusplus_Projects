#include "Poly2D.h"

Poly2D::Poly2D(const Poly2D &p)
{
	// Copying the points contained in the polygon to the new one
	m_v = p.m_v;
}

Poly2D::Poly2D(const Line2D &l1, const Line2D &l2)
{
	// Adding the points contained in each line to the Vector containing the polygon points
	m_v.push_back(l1.getv1());
	m_v.push_back(l1.getv2());
	m_v.push_back(l2.getv1());
	m_v.push_back(l2.getv2());

	connectLineToLine(); // Adding edges between all the points to connect and close the polygon
}

Poly2D::Poly2D(const Line2D &l, const Point2D &v)
{
	// Separate points and put them in the m_v Vector
	m_v.push_back(l.getv1());
	m_v.push_back(l.getv2());
	m_v.push_back(v);

	connectPointToLine(); // Creates edges between vertexes to connect and close the polygon
}

Poly2D::Poly2D(const Poly2D &p, const Point2D &v)
{
	// Adding the point to the polygon
	m_v = p.m_v;
	m_v.push_back(v);
}

Poly2D::Poly2D(const Poly2D &p, const Line2D &l)
{
	// Adding the outer points of the line to the polygon
	m_v = p.m_v;
	m_v.push_back(l.getv1());
	m_v.push_back(l.getv2());
}

Poly2D::Poly2D(const Poly2D &p1, const Poly2D &p2)
{
	// Merging two polygons
	m_v = p1.m_v;
	m_v.insert(m_v.end(), p2.m_v.begin(), p2.m_v.end());
}

Poly2D operator+(const Line2D &l1, const Line2D &l2)
{
	Poly2D p(l1, l2);
	return p;
}

Poly2D operator+(const Line2D &l, const Point2D &v)
{
	Poly2D p(l, v);
	return p;
}

Poly2D operator+(const Poly2D &p, const Point2D &v)
{
	Poly2D po(p, v);
	return po;
}

Poly2D operator+(const Poly2D &p, const Line2D &l)
{
	Poly2D po(p, l);
	return po;
}

Poly2D operator+(const Poly2D &p1, const Poly2D &p2)
{
	Poly2D p(p1, p2);
	return p;
}

/*
	Getting the index of both source and target points in the vector,
	and adds an edge between theese two points
*/
void Poly2D::addEdge(Point2D &source, Point2D &target)
{
	int sourceIndex = 0, targetIndex = 0;
	for (size_t i = 0; i < m_v.size(); i++)
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
	}
}

// Returns every point in the polygon within square brackets as a ostream
std::ostream &operator<<(std::ostream &oss, const Poly2D &p)
{
	oss << "[";
	for (size_t i = 0; i < p.m_v.size(); i++)
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

// Adding edges between all points in the polygon
// This is used when adding a point to a line
void Poly2D::connectPointToLine()
{
	m_v[0].addEdge(m_v[1]);
	m_v[0].addEdge(m_v[2]);
	m_v[1].addEdge(m_v[2]);
}

// This method uses shell sort to sort the points in the polygon with respect to the y-coordinate
void Poly2D::sortY()
{
	shellSort::shellSort(&m_v[0], m_v.size());
}

void Poly2D::connectLineToLine()
{
	sortY(); // Sorting the vector to easily add edges

	for (size_t i = 0; i < m_v.size() - 1; i++)
	{
		// If the edge count for the point is 2 or higher, we don't want to add an edge from this point
		if (m_v[i].endgeCount() < 2) {

			// If the point at index i already has an edge to the next point, we know that both point are part of
			// one of the lines we're connecting, so we rather want to connect to the next point.
			// Also if the point we're trying to make an edge to already has two edges,
			// we know that the other point in the line has already connected to it, so we want to connect it to the next instead.
			if (m_v[i].hasEdgeTo(m_v[i + 1]) || m_v[i + 1].endgeCount() >= 2)
			{
				m_v[i].addEdge(m_v[i + 2]);
			}
			else
			{
				m_v[i].addEdge(m_v[i + 1]);
			}
		}		
	}
}