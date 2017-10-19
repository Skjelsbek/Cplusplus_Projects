#pragma once
#include "Polygon.h"

int main()
{	
	// Create some vertexes
	Vertex v1(2.0, 3.0, 4.0);
	Vertex v2(4.0, 3.0, 2.0);
	Vertex v3(5.0, 3.0, 7.0);
	Vertex v4(10.0, 6.0, 15.0);
	Vertex v5(16.0, 11.0, 14.0);
	Vertex v6(33.0, 26.0, 58.0);

	// Creating lines by adding two vertexes
	Line l1 = v1 + v2;
	Line l2 = v3 + v4;
	Line l3 = v5 + v6;

	// Creating Polygons by adding:
	Polygon p1 = l1 + l2;	// Line and Line
	Polygon p2 = l3 + v1;	// Line and Vertex
	Polygon p3 = p1 + p2;	// Polygon and Polygon
	Polygon p4 = p3 + v5;	// Polygon and Vertex
	Polygon p5 = p4 + l3;	// Polygon and Line	
	
	// Printing to test << operator
	std::cout << v1 << std::endl;
	std::cout << l1 << std::endl;
	std::cout << p5 << std::endl;

	system("PAUSE");
}