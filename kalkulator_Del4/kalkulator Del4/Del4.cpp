#include <iostream>
#include <string>

// Sjekker om en string innehloder en spesifikk char
bool contains(std::string s, char c)
{
	for (unsigned short int i = 0; i < s.length(); i++)
	{
		if(s[i] == c)
		{
			return true;
		}
	}
	return false;
}

// Teller hvor mange ganger en char oppstår i en string
unsigned short int count(std::string s, char c)
{
	unsigned short int counter = 0;
	for (unsigned short int i = 0; i < s.length(); i++)
	{
		if (s[i] == c)
		{
			counter++;
		}
	}
	return counter;
}

// Fjerner alle mellomromene i en string
std::string removeSpaces(std::string s) 
{
	std::string tmp = "";
	for (unsigned short int i = 0; i < s.length(); i++)
	{
		if (s[i] != ' ') 
		{
			tmp += s[i];
		}
	}
	return tmp;
}

// bytter ut alle tilfeller av str2 med str3 i str1
std::string replace(std::string str1, std::string str2, std::string str3)
{		
	if (str1.find(str2) > str1.length() - 1 || str1.find(str2) < 0)
	{
		return str1;
	}
	str1.replace(str1.find(str2), str2.length(), str3);	// Fant dette 22.08.2017 på: http://www.cplusplus.com/reference/string/string/find/	
	return replace(str1, str2, str3);
}

// Retter opp noen syntax feil
std::string fixSyntax(std::string str)
{		
	str = replace(str, "--", "+");
	str = replace(str, "+-", "-");
	str = replace(str, "-+", "-");
	str = replace(str, "++", "-");
	return str;
}

// Sjekker om syntaxen er riktig, hvis den er feil oppstår det syntax error
std::string checkSyntax(std::string str)
{
	str = removeSpaces(str);
	str = fixSyntax(str);
	std::string allowedSyntax = "1234567890+-*/()^sqrtpi%!";
	for (unsigned short int i = 0; i < str.length(); i++)
	{
		if (!contains(allowedSyntax, str[i]))
		{
			return "Syntax Error!";
		}
	}
	return str;
}

// Utfører pluss og minus operasjonene når alt annet er tatt hånd om
std::string additionAndSubtraction(std::string calculation) 
{
	std::string sFirstNumber = "";
	std::string sSecondNumber = "";
	std::string sSum = "";
	char operation;
	double dFirstNumber = 0;
	double dSecondNumber = 0;
	double dSum = 0;
	std::string notCalculated = "";
	unsigned short int index = 0;

	// Base case
	if (!contains(calculation, '+') && !contains(calculation, '-')) {
		return calculation;
	}
	else if (calculation[0] == '-') 
	{
		std::string s = "";
		for (unsigned short int i = 1; i < calculation.length(); i++)
		{
			s += calculation[i];
		}
		if (!(contains(s, '+') && contains(s, '-')))
		{
			return calculation;
		}
		else
		{
			index = 1;
			sFirstNumber = "-";
		}
	}
	else
	{
		index = 0;
	}
	
	calculation = fixSyntax(calculation);

	while (index < calculation.length() && (isdigit(calculation[index]) || calculation[index] == '.'))
	{
		sFirstNumber += calculation[index];
		index++;
	}
		
	operation = calculation[index];		
	
	index++;
	while (index < calculation.length() && (isdigit(calculation[index]) || calculation[index] == '.'))
	{
		sSecondNumber += calculation[index];
		index++;
	}		
	
	dFirstNumber = std::stod(sFirstNumber);
	dSecondNumber = std::stod(sSecondNumber);

	if (operation == '+')
	{
		dSum = dFirstNumber + dSecondNumber;
	}
	else if (operation == '-')
	{
		dSum = dFirstNumber - dSecondNumber;
	}


	sSum = std::to_string(dSum);
	
	for (unsigned short int i = index; i < calculation.length(); i++)
	{
		notCalculated += calculation[i];
	}

	return additionAndSubtraction(sSum + notCalculated);
}

// Tar hånd om gange og dele operasjoner
std::string multiplicationAndDivision(std::string calculation) 
{
	std::string sFirstNumber = "";
	std::string sSecondNumber = "";
	std::string sSum = "";
	char operation;
	double dFirstNumber = 0;
	double dSecondNumber = 0;
	double dSum = 0;
	std::string beforeAnswer = "", afterAnswer = "";
	unsigned short int index = 0, operationIndex = 0, firstNumberStartIndex = 0;

	// Base case
	if (!contains(calculation, '*') && !contains(calculation, '/'))
	{
		return calculation;
	}

	calculation = fixSyntax(calculation);

	// Finner regneart
	while (index < calculation.length() && (calculation[index] != '*' && calculation[index] != '/')) 
	{
		index++;
	}
	
	// Lagrer regneart og regneartens index
	operationIndex = index;
	operation = calculation[index];
	
	// Finner startindeksen til det første tallet
	index--;
	while (index > 0 && (isdigit(calculation[index]) || calculation[index] == '.'))
	{
		index--;		
	}
	if (isdigit(calculation[index])) 
	{	
		firstNumberStartIndex = index;
	}
	else
	{
		firstNumberStartIndex = index + 1;
	}	

	// Lagrer det første tallet
	for (unsigned short int i = firstNumberStartIndex; i < operationIndex; i++)
	{
		sFirstNumber += calculation[i];
	}	

	// Lagrer det andre tallet
	index = operationIndex + 1;
	if (calculation[index] == '-' || calculation[index] == '+')
	{
		sSecondNumber += calculation[index];
		index++;
	}
	
	while (index < calculation.length() && (isdigit(calculation[index]) || calculation[index] == '.')) 
	{
		sSecondNumber += calculation[index];
		index++;
	}

	// Konverterer tallene fra string til double
	dFirstNumber = std::stod(sFirstNumber);
	dSecondNumber = std::stod(sSecondNumber);

	// Velger og utfører riktig operasjon
	if (operation == '*')
	{		
		dSum = dFirstNumber * dSecondNumber;
	}
	else if (operation == '/')
	{		
		if (dSecondNumber != 0)
		{
			dSum = dFirstNumber / dSecondNumber;
		}
		else
		{
			return "Syntax Error!";
		}
	}

	// Putter svaret tilbake i resten av utrykket og kjører rekursivt kall til det ikke er flere gange og dele operasjoner i utrykket.
	sSum = std::to_string(dSum);	
		
	for (unsigned short int i = 0; i < firstNumberStartIndex; i++) 
	{
		beforeAnswer += calculation[i];
	}
	for (unsigned short int i = index; i < calculation.length(); i++)
	{
		afterAnswer += calculation[i];
	}
	return multiplicationAndDivision(beforeAnswer + sSum + afterAnswer);
}

// Løser opp parantesene i utrykket
std::string parentheses(std::string calculation) 
{
	if (!contains(calculation, ')'))
	{
		return calculation;
	} else if (count(calculation, '(') != count(calculation, ')')) 
	{
		return "Syntax Error!";
	}

	unsigned short int firstParentheiesIndex = 0, lastParenthesisIndex = 0;
	std::string parenthesisContent = "";
	std::string newCalculation = "";
	
	while (calculation[lastParenthesisIndex] != ')')
	{
		lastParenthesisIndex++;
	}

	firstParentheiesIndex = lastParenthesisIndex - 1;
	while (calculation[firstParentheiesIndex] != '(')
	{
		firstParentheiesIndex--;
	}


	for (unsigned short int i = firstParentheiesIndex + 1; i < lastParenthesisIndex; i++)
	{
		parenthesisContent += calculation[i];
	}
	
	if (contains(parenthesisContent, '*') || contains(parenthesisContent, '/'))
	{
		parenthesisContent = multiplicationAndDivision(parenthesisContent);
	}
	if (contains(parenthesisContent, '+') || contains(parenthesisContent, '-'))
	{
		parenthesisContent = additionAndSubtraction(parenthesisContent);
	}

	for (unsigned short int i = 0; i < firstParentheiesIndex; i++)
	{
		newCalculation += calculation[i];
	}

	newCalculation += parenthesisContent;

	for (unsigned short int i = lastParenthesisIndex + 1; i < calculation.length(); i++)
	{
		newCalculation += calculation[i];
	}

	newCalculation = parentheses(newCalculation);

	return newCalculation;
}

int main() 
{	
	std::string calculation = "", answer = "", runAgain = "";

	do 
	{		
		system("cls");
		std::cout << "Skriv inn regnestykket> ";
		getline(std::cin, calculation);

		if (!calculation.empty()) 
		{
			answer = checkSyntax(calculation);

			if (contains(answer, '(') || contains(answer, ')'))
			{
				answer = parentheses(answer);
			}		
		
			if (contains(answer, '*') || contains(answer, '/'))
			{
				answer = multiplicationAndDivision(answer);
			}
		
			if (contains(answer, '+') || contains(answer, '-'))
			{
				answer = additionAndSubtraction(answer);
			}
		
			if (answer == "Syntax Error!")
			{
				std::cout << answer << std::endl;
			}
			else
			{
				std::cout << "Svaret pa " << calculation << " er " << std::stod(answer) << std::endl;
			}
		}
		std::cout << "Trykk 'a' for a avslutte programmet, alt annet starter programmet pa nytt." << std::endl;
		getline(std::cin, runAgain);
	} while (runAgain[0] != 'a');
	return 0;
}