#include "Syntax.h"
#include <sstream>

// For å få med flere desimaler
std::string Syntax::myToString(double &d) 
{
	std::stringstream ss;
	ss.precision(8);
	ss << d;
	return ss.str();
}

// Sjekker om en string innehloder en spesifikk char
bool Syntax::contains(std::string &str, char c)
{
	for (unsigned short int i = 0; i < str.length(); i++)
	{
		if (str[i] == c)
		{
			return true;
		}
	}
	return false;
}

// Teller hvor mange ganger en char oppstår i en string
unsigned short int Syntax::count(std::string &str, char c)
{
	unsigned short int counter = 0;
	for (unsigned short int i = 0; i < str.length(); i++)
	{
		if (str[i] == c)
		{
			counter++;
		}
	}
	return counter;
}

// Fjerner alle mellomromene i en string
void Syntax::removeSpaces(std::string &str)
{
	std::string tmp = "";
	for (unsigned short int i = 0; i < str.length(); i++)
	{
		if (str[i] != ' ')
		{
			tmp += str[i];
		}
	}
	str = tmp;
}

// bytter ut alle tilfeller av str2 med str3 i str1
void Syntax::replace(std::string &str1, std::string str2, std::string str3)
{
	if (str1.find(str2) > str1.length() - 1 || str1.find(str2) < 0)
	{
		return;
	}
	str1.replace(str1.find(str2), str2.length(), str3);	// Fant dette 22.08.2017 på: http://www.cplusplus.com/reference/string/string/find/	
	replace(str1, str2, str3);
}

// Retter opp noen syntax feil
void Syntax::fixSyntax(std::string &str)
{
	replace(str, "--", "+");
	replace(str, "+-", "-");
	replace(str, "-+", "-");
	replace(str, "++", "+");	
}

// Sjekker om syntaxen er riktig, hvis den er feil oppstår det syntax error
void Syntax::checkSyntax(std::string &str)
{
	std::string allowedSyntax = "1234567890+-*/()^sqrtpi%!. ";
	for (unsigned short int i = 0; i < str.length(); i++)
	{
		if (!contains(allowedSyntax, str[i]))
		{
			str = "Syntax Error!";
		}
	}
	if (str != "Syntax Error!" && count(str, '(') != count(str, ')'))
	{
		str = "Syntax Error!";
	}
	else if (str != "Syntax Error!")
	{
		removeSpaces(str);
		fixSyntax(str);
	}		
}
