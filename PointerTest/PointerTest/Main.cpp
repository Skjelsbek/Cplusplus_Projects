#pragma once
#include "PointerTest.h"

int main() 
{
	int i = 20;
	char c = 'a';
	std::string s = "snickers";

	PointerTest *test = new PointerTest();
	test->setPointers(i, c ,s);
	
	std::cout << test->geti() << "\n" << test->getc() << "\n" << test->gets() << "\n";
	delete test;

	system("PAUSE");
}