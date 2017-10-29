#pragma once
#include "Line.h"
#include <vector>

class Polygon
{
public:
	Polygon(const Polygon &p);
	Polygon(const Line &l1, const Line &l2);
	Polygon(const Line &l, const Vertex &v);
	Polygon(const Polygon &p, const Vertex &v);
	Polygon(const Polygon &p, const Line &l);
	Polygon(const Polygon &p1, const Polygon &p2);
	friend Polygon operator+(const Line &l1, const Line &l2);
	friend Polygon operator+(const Line &l, const Vertex &v);
	friend Polygon operator+(const Polygon &p, const Vertex &v);
	friend Polygon operator+(const Polygon &p, const Line &l);
	friend Polygon operator+(const Polygon &p1, const Polygon &p2);
	void addEdge(Vertex & source, Vertex & target);
	void connectPointToLine();
	void sortY();
	void connectLineToLine();
	friend std::ostream &operator<<(std::ostream &oss, const Polygon &p);

private:	
	std::vector<Vertex> m_v;
};

