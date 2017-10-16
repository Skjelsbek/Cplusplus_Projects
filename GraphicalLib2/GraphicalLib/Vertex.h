#pragma once
#include <iostream>
#include <sstream>
#include <string>

class Vertex
{
public:		
	Vertex();
	Vertex(const double &x, const double &y);
	Vertex(const double &x, const double &y, const double &z);
	Vertex(const Vertex &v);
	Vertex &operator=(const Vertex &v);
	std::string toString();

private:
	double m_x;
	double m_y;
	double m_z;
};

