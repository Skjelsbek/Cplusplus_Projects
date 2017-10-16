#pragma once
#include <iostream>
#include <string>
class PointerTest
{
public:	
	PointerTest();
	~PointerTest();
	void setPointers(int & i, char & c, std::string & s);
	int geti();
	char getc();
	std::string gets();

private:
	int *m_p1;
	char *m_p2;
	std::string *m_p3;
};

