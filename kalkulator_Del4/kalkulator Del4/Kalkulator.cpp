#include "Kalkulator.h"

void Kalkulator::calculate(std::string &calculation)
{	
	checkSyntax(calculation);
	
	if (contains(calculation, '^'))
	{
		power(calculation);
	}	
	if (contains(calculation, '(') || contains(calculation, ')'))
	{
		parentheses(calculation);
	}	
	if (contains(calculation, '*') || contains(calculation, '/'))
	{
		multiplicationAndDivision(calculation);
	}		
	if (contains(calculation, '+') || contains(calculation, '-'))
	{
		additionAndSubtraction(calculation);
	}	
}

// Utfører pluss og minus operasjonene når alt annet er tatt hånd om
void Kalkulator::additionAndSubtraction(std::string &calculation)
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
		return;
	}
	else if (calculation[0] == '-')
	{
		std::string s = "";
		for (unsigned short int i = 1; i < calculation.length(); i++)
		{
			s += calculation[i];
		}
		if (!(contains(s, '+') || contains(s, '-')))
		{
			return;
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

	fixSyntax(calculation);

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


	sSum = myToString(dSum);

	for (unsigned short int i = index; i < calculation.length(); i++)
	{
		notCalculated += calculation[i];
	}
	calculation = sSum + notCalculated;
	additionAndSubtraction(calculation);
}

// Tar hånd om gange og dele operasjoner
void Kalkulator::multiplicationAndDivision(std::string &calculation)
{
	// Base case
	if (!contains(calculation, '*') && !contains(calculation, '/'))
	{
		return;
	}

	std::string sFirstNumber = "", sSecondNumber = "", sSum = "", sBeforeAnswer = "", sAfterAnswer = "";
	char operation;
	double dFirstNumber = 0, dSecondNumber = 0, dSum = 0;
	unsigned short int index = 0, operationIndex = 0, firstNumberStartIndex = 0;

	fixSyntax(calculation);

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
			calculation = "Syntax Error!";
			return;
		}
	}

	// Putter svaret tilbake i resten av utrykket og kjører rekursivt kall til det ikke er flere gange og dele operasjoner i utrykket.
	sSum = myToString(dSum);

	for (unsigned short int i = 0; i < firstNumberStartIndex; i++)
	{
		sBeforeAnswer += calculation[i];
	}
	for (unsigned short int i = index; i < calculation.length(); i++)
	{
		sAfterAnswer += calculation[i];
	}
	calculation = sBeforeAnswer + sSum + sAfterAnswer;
	multiplicationAndDivision(calculation);
}

// Løser opp parantesene i utrykket
void Kalkulator::parentheses(std::string &calculation)
{
	if (!contains(calculation, ')'))
	{
		return;
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
		multiplicationAndDivision(parenthesisContent);
	}
	if (contains(parenthesisContent, '+') || contains(parenthesisContent, '-'))
	{
		additionAndSubtraction(parenthesisContent);
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

	calculation = newCalculation;
	parentheses(calculation);
}

void Kalkulator::power(std::string &calculation)
{
	// Base case
	if (!contains(calculation, '^'))
	{
		return;
	}

	std::string sFirstNumber = "", sSecondNumber = "", sSum = "", sBeforeAnswer = "", sAfterAnswer = "";
	double dFirstNumber = 0, dSecondNumber = 0, dSum = 0;
	unsigned short int index = 0, operationIndex = 0, firstNumberStartIndex = 0;

	fixSyntax(calculation);

	// Finner regneart
	while (index < calculation.length() && (calculation[index] != '^'))
	{
		index++;
	}

	// Lagrer regneartens index
	operationIndex = index;

	// Finner startindeksen til det første tallet
	index--;
	if (calculation[index] == ')')
	{
		unsigned short int cpc = 1;	// cpc = closing parentheses count
		unsigned short int opc = 0; // opc = opening parentheses count
		index--;

		while (index >= 0 && cpc != opc)
		{
			if (calculation[index] == ')')
			{
				cpc++;
			}
			else if (calculation[index] == '(')
			{
				opc++;
			}
			index--;
		}
		firstNumberStartIndex = ++index;
	}
	else
	{
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
			firstNumberStartIndex = ++index;
		}
	}

	// Lagrer det første tallet
	for (unsigned short int i = firstNumberStartIndex; i < operationIndex; i++)
	{
		sFirstNumber += calculation[i];
	}
	if (contains(sFirstNumber, ')'))
	{
		parentheses(sFirstNumber);
	}

	// Lagrer det andre tallet
	index = operationIndex + 1;
	if (calculation[index] == '(')
	{
		unsigned short int cpc = 0;	// cpc = closing parentheses count
		unsigned short int opc = 1; // opc = opening parentheses count
		index++;

		while (index < calculation.length() && cpc != opc)
		{
			if (calculation[index] == ')')
			{
				cpc++;
			}
			else if (calculation[index] == '(')
			{
				opc++;
			}
			index++;
		}

		for (unsigned short int i = operationIndex + 1; i < index; i++)
		{
			sSecondNumber += calculation[i];
		}

		parentheses(sSecondNumber);
	}
	else
	{
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
	}


	// Konverterer tallene fra string til double
	dFirstNumber = std::stod(sFirstNumber);
	dSecondNumber = std::stod(sSecondNumber);

	dSum = pow(dFirstNumber, dSecondNumber);

	// Putter svaret tilbake i resten av utrykket og kjører rekursivt kall til det ikke er flere gange og dele operasjoner i utrykket.
	sSum = myToString(dSum);

	for (unsigned short int i = 0; i < firstNumberStartIndex; i++)
	{
		sBeforeAnswer += calculation[i];
	}
	for (unsigned short int i = index; i < calculation.length(); i++)
	{
		sAfterAnswer += calculation[i];
	}

	calculation = sBeforeAnswer + sSum + sAfterAnswer;
	power(calculation);
}