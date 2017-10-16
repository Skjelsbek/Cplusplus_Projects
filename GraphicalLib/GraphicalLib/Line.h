#pragma once
#include "Vertex.h"
class Line
{
public:	
	Line(const Vertex &v1,  const Vertex &v2);
	Line(const Line &l);
	~Line();
	Line& operator=(const Line &l);
	friend Line operator+(const Vertex &a, const Vertex &b);

private:
	Vertex *m_v1;
	Vertex *m_v2;
};
