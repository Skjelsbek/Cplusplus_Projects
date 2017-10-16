#include "PointerTest.h"


PointerTest::PointerTest()
{	
	m_p1 = new int;
	m_p2 = new char;
	m_p3 = new std::string;
}


PointerTest::~PointerTest()
{
	delete m_p1;
	delete m_p2;
	delete m_p3;
}

void PointerTest::setPointers(int &i, char &c, std::string &s) 
{
	*m_p1 = i;
	*m_p2 = c;
	*m_p3 = s;
}

int PointerTest::geti() 
{
	return *m_p1;
}

char PointerTest::getc() 
{
	return *m_p2;
}

std::string PointerTest::gets() 
{
	return *m_p3;
}