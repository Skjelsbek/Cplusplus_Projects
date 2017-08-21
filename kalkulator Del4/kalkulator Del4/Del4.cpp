#include <iostream>
#include <string>

// Alternativ til cin som takler mellomrom
std::string getInput() 
{
	std::string input = "";
	char c = std::cin.get();
	while (c != '\n') 
	{
		input += c;
		c = std::cin.get();
	}
	return input;
}

// Sjekker om en string innehloder en spesifikk char
bool contains(std::string input, char c)
{
	for (unsigned short int i = 0; i < input.length(); i++)
	{
		if(input[i] == c)
		{
			return true;
		}
	}
	return false;
}

// Utfører pluss og minus operasjonene når alt annet er tatt hånd om
std::string additionAndSubtraction(std::string calculation) 
{
	std::string sFirstNumber = "";
	std::string sSecondNumber = "";
	std::string sSum = "";
	char operation;
	float fFirstNumber = 0;
	float fSecondNumber = 0;
	float fSum = 0;
	std::string answer = "";
	unsigned short int index = 0;

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
		if (!contains(s, '+') && !contains(s, '-'))
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
	
	fFirstNumber = std::stof(sFirstNumber);
	fSecondNumber = std::stof(sSecondNumber);

	if (operation == '+')
	{
		fSum = fFirstNumber + fSecondNumber;
	}
	else if (operation == '-')
	{
		fSum = fFirstNumber - fSecondNumber;
	}


	sSum = std::to_string(fSum);
	
	for (unsigned short int i = index; i < calculation.length(); i++)
	{
		answer += calculation[i];
	}

	return additionAndSubtraction(sSum + answer);
}

// Tar hånd om gange og dele operasjoner
std::string multiplicationAndDivison(std::string calculation) 
{

	return calculation;
}

// Løser opp parantesene i utrykket
std::string parentheses(std::string calculation) 
{
	if (!contains(calculation, ')'))
	{
		return calculation;
	}

	unsigned short int firstParenthesesIndex = 0, lastParenthesesIndex = 0;
	std::string parenthesesContent = "";
	std::string newCalculation = "";
	
	while (calculation[lastParenthesesIndex] != ')')
	{
		lastParenthesesIndex++;
	}

	firstParenthesesIndex = lastParenthesesIndex - 1;
	while (calculation[firstParenthesesIndex] != '(')
	{
		firstParenthesesIndex--;
	}


	for (unsigned short int i = firstParenthesesIndex + 1; i < lastParenthesesIndex; i++)
	{
		parenthesesContent += calculation[i];
	}

	if (contains(parenthesesContent, '*') || contains(parenthesesContent, '/'))
	{
		parenthesesContent = multiplicationAndDivison(parenthesesContent);
	}
	else if (contains(parenthesesContent, '+') || contains(parenthesesContent, '-'))
	{
		parenthesesContent = additionAndSubtraction(parenthesesContent);
	}

	for (unsigned short int i = 0; i < firstParenthesesIndex; i++)
	{
		newCalculation += calculation[i];
	}

	newCalculation += parenthesesContent;

	for (unsigned short int i = lastParenthesesIndex + 1; i < calculation.length(); i++)
	{
		newCalculation += calculation[i];
	}

	newCalculation = parentheses(newCalculation);

	return newCalculation;
}



int main() 
{
	char runAgain;	
	std::string calculation = "";

	do 
	{
		system("cls");
		std::cout << "Skriv inn regnestykket:" << std::endl;
		calculation = getInput();
		
		if (contains(calculation, ')'))
		{
			calculation = parentheses(calculation);
		}
		
		if (contains(calculation, '*') || contains(calculation, '/'))
		{
			calculation = multiplicationAndDivison(calculation);
		}
		
		if (contains(calculation, '+') || contains(calculation, '-'))
		{
			calculation = additionAndSubtraction(calculation);
		}
		
		std::cout << calculation << std::endl;

		system("PAUSE");
		system("cls");
		std::cout << "Trykk 'a' for a avslutte programmet, alt annet starter programmet pa nytt." << std::endl;
		runAgain = std::cin.get();
	} while (runAgain != 'a');

	return 0;
}