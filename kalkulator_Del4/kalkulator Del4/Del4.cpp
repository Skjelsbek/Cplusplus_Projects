#include <iostream>
#include <string>
#include "Kalkulator.h"
#include "Syntax.h"

int main() 
{	
	std::string calculation = "", answer = "", runAgain = "";
	Kalkulator k;
	do 
	{		
		system("cls");
		std::cout << "Skriv inn regnestykket> ";
		getline(std::cin, calculation);
		answer = calculation;
		if (!answer.empty())
		{
			k.calculate(answer);
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