#pragma once
#include <string>
class Vertex
{
public:		
	Vertex(const double &x, const double &y);
	Vertex(const double &x, const double &y, const double &z);
	Vertex(const Vertex &v);
	Vertex& operator=(const Vertex &v);
	~Vertex();
	double &getx() { return *m_x; }
	double &gety() { return *m_y; }
	double &getz() { return *m_z; }
	std::string toString();

private:
	double *m_x;
	double *m_y;
	double *m_z;
};

