#pragma once
#include <iostream>
#include <string>
class Syntax
{
protected:
	bool contains(std::string &str, char c);
	unsigned short int count(std::string &str, char c);
	void removeSpaces(std::string &str);
	void replace(std::string &str1, std::string str2, std::string str3);
	void fixSyntax(std::string &str);
	void checkSyntax(std::string &str);
	std::string myToString(double &d);
};

