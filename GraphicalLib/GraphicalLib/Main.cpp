#pragma once
#include "Vertex.h"
#include "Line.h"
#include <iostream>
int main()
{	
	Vertex *v1 = new Vertex(2.0, 3.0, 4.0);
	Vertex *v2 = new Vertex(4.0, 3.0, 2.0);
	std::cout << v1->toString();
	//Line l = *v1 + *v2;
	//Line l1(*v1 + *v2);
	Line l(*v1,*v2);
	l = *v1 + *v2;
	delete v1;
	delete v2;
	system("PAUSE");
}