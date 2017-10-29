#pragma once
#include "Poly2D.h"
#include "Poly3D.h"

int main()
{
	// Testing 2D
	// Create some vertexes
	Point2D v1(2.0, 3.0);
	Point2D v2(4.0, 3.0);
	Point2D v3(5.0, 3.0);
	Point2D v4(10.0, 6.0);
	Point2D v5(16.0, 11.0);
	Point2D v6(33.0, 26.0);

	// Creating lines by adding two vertexes
	Line2D l1 = v1 + v2;
	Line2D l2 = v3 + v4;
	Line2D l3 = v5 + v6;

	// Creating Polygons by adding:
	Poly2D p1 = l1 + l2;	// Line and Line
	Poly2D p2 = l3 + v1;	// Line and Vertex
	Poly2D p3 = p1 + p2;	// Polygon and Polygon
	Poly2D p4 = p3 + v5;	// Polygon and Vertex
	Poly2D p5 = p4 + l3;	// Polygon and Line	

	// Printing to test << operator
	std::cout << v1 << std::endl;
	std::cout << l1 << std::endl;
	std::cout << p5 << std::endl;


	// Testing 3D
	Point3D v7(2.0, 3.0, 4.0);
	Point3D v8(4.0, 3.0, 2.0);
	Point3D v9(5.0, 3.0, 7.0);
	Point3D v10(10.0, 6.0, 11.0);
	Point3D v11(16.0, 11.0, 7.0);
	Point3D v12(33.0, 26.0, 3.0);
	
	Line3D l4 = v7 + v8;
	Line3D l5 = v9 + v10;
	Line3D l6 = v11 + v12;

	Poly3D p6 = l4 + l5;
	Poly3D p7 = l6 + v7;
	Poly3D p8 = p6 + p7;
	Poly3D p9 = p8 + v11;
	Poly3D p10 = p9 + l6;

	std::cout << v7 << std::endl;
	std::cout << l4 << std::endl;
	std::cout << p10 << std::endl;

	system("PAUSE");
}