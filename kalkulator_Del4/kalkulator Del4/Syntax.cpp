#pragma once
#include "Syntax.h"

// For � f� med flere desimaler n�r jeg gj�r konvertering fra double til string
std::string Syntax::myToString(double &d) 
{
	std::stringstream ss;
	ss.precision(8);
	ss << d;
	return ss.str();
}

// Sjekker om en string inneholder en spesifikk char
bool Syntax::contains(std::string &str, char c)
{
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == c)
		{
			return true;
		}
	}
	return false;
}

// Teller hvor mange ganger en char oppst�r i en string
int Syntax::count(std::string &str, char c)
{
	int counter = 0;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == c)
		{
			counter++;
		}
	}
	return counter;
}

// Fjerner alle mellomrommene i en string
void Syntax::removeSpaces(std::string &str)
{
	std::string tmp = "";
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] != ' ')
		{
			tmp += str[i];
		}
	}
	str = tmp;	
}

// Bytter ut alle tilfeller av str2 med str3 i str1
void Syntax::replace(std::string &str1, std::string str2, std::string str3)
{
	// Base case
	if (str1.find(str2) > str1.length() - 1 || str1.find(str2) < 0)
	{
		return;
	}

	str1.replace(str1.find(str2), str2.length(), str3);	// Fant dette 22.08.2017 p�: http://www.cplusplus.com/reference/string/string/find/	
	replace(str1, str2, str3);
}

// Gj�r om "--" til "+", "+-" til "-", "-+" til "+" og "++" til "+"
void Syntax::fixSyntax(std::string &str)
{
	replace(str, "--", "+");
	replace(str, "+-", "-");
	replace(str, "-+", "-");
	replace(str, "++", "+");		
}

// Sjekker om syntaksen er riktig, hvis den er feil oppst�r det syntaks feil
void Syntax::checkSyntax(std::string &str)
{
	// Sjekker om bruker har oppgitt riktig syntaks
	std::string allowedSyntax = "1234567890+-*/()^. ";
	for (int i = 0; i < str.length(); i++)
	{
		if (!contains(allowedSyntax, str[i]))
		{
			str = "Syntax Error!";
		}
	}

	if (str != "Syntax Error!" && count(str, '(') != count(str, ')')) // Sjekker om antall start- og sluttparenteser er ekvivalent
	{
		str = "Syntax Error!";
	}
	else if (str != "Syntax Error!") // Fikser "tilatte" syntaks feil
	{
		removeSpaces(str);
		fixSyntax(str);
	}		
}