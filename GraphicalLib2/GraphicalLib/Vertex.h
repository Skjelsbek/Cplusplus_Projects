#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <list>

class Vertex
{
public:		
	Vertex();
	Vertex(const double &x, const double &y);
	Vertex(const double &x, const double &y, const double &z);
	Vertex(const Vertex &v);
	void addEdge(Vertex &target);
	void reomveEdge(Vertex & target);
	double getX() { return m_x; };
	double getY() { return m_y; };
	Vertex &operator=(const Vertex &v);
	bool operator==(const Vertex & v) const;
	friend std::ostream &operator<<(std::ostream &o, const Vertex &v);

private:
	std::list<Vertex> m_edges;
	double m_x;
	double m_y;
	double m_z;
};

