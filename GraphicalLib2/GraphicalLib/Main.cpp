#pragma once
#include "Polygon.h"

int main()
{		
	Vertex v1(2.0, 3.0, 4.0);
	Vertex v2(4.0, 3.0, 2.0);
	Vertex v3(5.0, 3.0, 7.0);
	Vertex v4(10.0, 6.0, 15.0);
	Line l1 = v1 + v2;
	Line l2 = v3 + v4;
	Polygon p1(l1, l2);
	Polygon p2 = l1 + v1;
	Polygon p3 = p1 + p2;
	std::cout << p3.toString();


	system("PAUSE");
}