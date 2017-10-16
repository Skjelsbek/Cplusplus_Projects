#pragma once
#include "Vertex.h"

class Line
{
public:	
	Line(const Vertex &v1,  const Vertex &v2);
	friend Line operator+(const Vertex &a, const Vertex &b);
	std::string toString();
	const Vertex &getv1() const;
	const Vertex &getv2() const;

private:
	Vertex m_v1;
	Vertex m_v2;
};
