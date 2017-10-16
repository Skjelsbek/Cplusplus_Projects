#pragma once
#include "Line.h"

class Polygon
{
public:
	Polygon();
	Polygon(const Polygon &p);
	Polygon &operator=(const Polygon &v);
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
	void extend();
	std::string toString();
	~Polygon();

private:	
	Vertex *m_v;
	int m_size;
};

