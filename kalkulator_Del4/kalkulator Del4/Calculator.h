#pragma once
#include "Syntax.h"

class Calculator : public Syntax
{	
public:

	void power(std::string &calculation);
	void additionAndSubtraction(std::string &calculation);
	void multiplicationAndDivision(std::string &calculation);
	void parentheses(std::string &calculation);
	void calculate(std::string &calculation);	
};
