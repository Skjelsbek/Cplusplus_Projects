#pragma once
#include "Calculator.h"

// Utfører riktige regneoperasjoner i forhold til hva brukeren ønsker å regne ut
void Calculator::calculate(std::string &calculation)
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

// Utfører pluss og minus operasjonene
void Calculator::additionAndSubtraction(std::string &calculation)
{	
	std::string sFirstNumber = "", sSecondNumber = "", sAnswer = "", sAfterAnswer = "";
	double dFirstNumber = 0, dSecondNumber = 0, dSum = 0;
	char operation;
	int index = 0;

	// Base case 1
	if (!contains(calculation, '+') && !contains(calculation, '-')) {
		return;
	}
	else if (calculation[0] == '-') // Base case 2
	{
		std::string s = "";
		for (int i = 1; i < calculation.length(); i++)
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

	// Lagrer tallet på venstre side av operatoren i sFirstNumber
	while (index < calculation.length() && (isdigit(calculation[index]) || calculation[index] == '.'))
	{
		sFirstNumber += calculation[index];
		index++;
	}

	operation = calculation[index]; // Lagrer regneoperasjonen i operation

	// Lagrer tallet på høyre side av operatoren i sSecondNumber
	index++;
	while (index < calculation.length() && (isdigit(calculation[index]) || calculation[index] == '.'))
	{
		sSecondNumber += calculation[index];
		index++;
	}

	// Konverterer tallene fra string til double for å kunne regne med dem
	dFirstNumber = std::stod(sFirstNumber);
	dSecondNumber = std::stod(sSecondNumber);

	// Utfører riktig regneoperasjon med hennsyn på om operation er - eller +
	if (operation == '+')
	{
		dSum = dFirstNumber + dSecondNumber;
	}
	else if (operation == '-')
	{
		dSum = dFirstNumber - dSecondNumber;
	}

	// Konverterer svaret fra double til string for å kunne bytte det ut med det opprinnelige regnestykket i uttrykket
	sAnswer = myToString(dSum);

	// Bytter ut det utregnede regnestykket med svaret i det opprinnelige uttrykket,
	// og kjører funksjonen på nytt til det ikke er flere + og - operasjoner igjen i uttrykket
	for (int i = index; i < calculation.length(); i++)
	{
		sAfterAnswer += calculation[i];
	}
	calculation = sAnswer + sAfterAnswer;
	additionAndSubtraction(calculation);
}

// Tar hånd om gange og dele operasjoner
void Calculator::multiplicationAndDivision(std::string &calculation)
{
	// Base case
	if (!contains(calculation, '*') && !contains(calculation, '/'))
	{
		return;
	}
		
	std::string sFirstNumber = "", sSecondNumber = "", sAnswer = "", sBeforeAnswer = "", sAfterAnswer = "";
	double dFirstNumber = 0, dSecondNumber = 0, dSum = 0;
	char operation;
	int index = 0, operationIndex = 0, firstNumberStartIndex = 0;

	fixSyntax(calculation);

	// Finner regneart
	while (index < calculation.length() && (calculation[index] != '*' && calculation[index] != '/'))
	{
		index++;
	}

	// Lagrer regneart og regneartens indeks
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
	for (int i = firstNumberStartIndex; i < operationIndex; i++)
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
			calculation = "Math Error!";
			return;
		}
	}

	// Putter svaret tilbake i resten av uttrykket og kjører rekursivt kall til det ikke er flere gange og dele operasjoner i uttrykket.
	sAnswer = myToString(dSum);

	for (int i = 0; i < firstNumberStartIndex; i++)
	{
		sBeforeAnswer += calculation[i];
	}
	for (int i = index; i < calculation.length(); i++)
	{
		sAfterAnswer += calculation[i];
	}
	calculation = sBeforeAnswer + sAnswer + sAfterAnswer;
	multiplicationAndDivision(calculation);
}

// Løser opp parantesene i uttrykket
void Calculator::parentheses(std::string &calculation)
{
	// Base case
	if (!contains(calculation, ')'))
	{
		return;
	}	

	std::string parenthesisContent = "", newCalculation = "";
	int firstParentheiesIndex = 0, lastParenthesisIndex = 0;		

	// Finner indeksen til den innerste parentesen
	while (calculation[lastParenthesisIndex] != ')')
	{
		lastParenthesisIndex++;
	}	

	// Finner startparentesen til den innerste parentesen
	firstParentheiesIndex = lastParenthesisIndex - 1;
	while (calculation[firstParentheiesIndex] != '(')
	{
		firstParentheiesIndex--;
	}	

	// Legger innholdet i parentesene i en ny string parenthesisContent
	for (int i = firstParentheiesIndex + 1; i < lastParenthesisIndex; i++)
	{
		parenthesisContent += calculation[i];
	}

	
	calculate(parenthesisContent);	// Regner ut det som er inni parentesen

	// Bytter ut det opprinnelige uttrykket med ett uttrykk hvor parentesen er regnet ut,
	// og kjører rekursivt kall til det ikke er flere parenteser i uttrykket
	for (int i = 0; i < firstParentheiesIndex; i++)
	{
		newCalculation += calculation[i];
	}
	newCalculation += parenthesisContent;
	for (int i = lastParenthesisIndex + 1; i < calculation.length(); i++)
	{
		newCalculation += calculation[i];
	}
	calculation = newCalculation;
	parentheses(calculation);
}

// Utfører potensregning
void Calculator::power(std::string &calculation)
{
	// Base case
	if (!contains(calculation, '^'))
	{
		return;
	}

	fixSyntax(calculation);
	std::string sFirstNumber = "", sSecondNumber = "", sAnswer = "", sBeforeAnswer = "", sAfterAnswer = "";
	double dFirstNumber = 0, dSecondNumber = 0, dSum = 0;
	int index = 0, operationIndex = 0, firstNumberStartIndex = 0;

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
		int cpc = 1;	// cpc = closing parentheses count
		int opc = 0; // opc = opening parentheses count
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
	for (int i = firstNumberStartIndex; i < operationIndex; i++)
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
		int cpc = 0;	// cpc = closing parentheses count
		int opc = 1; // opc = opening parentheses count
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

		for (int i = operationIndex + 1; i < index; i++)
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
	sAnswer = myToString(dSum);

	// Putter svaret tilbake i resten av uttrykket og kjører rekursivt kall til det ikke er flere gange og dele operasjoner i uttrykket.
	for (int i = 0; i < firstNumberStartIndex; i++)
	{
		sBeforeAnswer += calculation[i];
	}
	for (int i = index; i < calculation.length(); i++)
	{
		sAfterAnswer += calculation[i];
	}
	calculation = sBeforeAnswer + sAnswer + sAfterAnswer;
	power(calculation);
}