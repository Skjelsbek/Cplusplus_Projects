#pragma once
#include "Calculator.h"

int main() 
{	
	std::string calculation = "", answer = "", runAgain = "";
	Calculator c;

	// Bruker en do-while så bruker slipper å starte programmet på nytt hvis de ønsker å regne ut flere regnestykker
	do 
	{		
		system("cls"); // Clearer skjermen for at programmet skal være mer oversiktlig å bruke

		// Ber bruker skrive inn regnestykke, og lagrer det i calculation og answer.
		std::cout << "Skriv inn regnestykket> ";
		getline(std::cin, calculation);
		answer = calculation;

		// Regner ut uttrykket og skriver ut svaret
		if (!answer.empty())
		{
			c.calculate(answer);
			if (answer == "Syntax Error!" || answer == "Math Error!")
			{
				std::cout << answer << std::endl;
			}
			else
			{
				std::cout << "Svaret pa " << calculation << " er " << std::stod(answer) << std::endl;
			}
		}

		// Scanner inn en string, men benytter bare første charen i stringen for å bestemme om programmmet
		// skal starte på nytt eller ikke
		std::cout << "Trykk 'a' for a avslutte programmet, alt annet starter programmet pa nytt." << std::endl;
		getline(std::cin, runAgain);
	} while (runAgain[0] != 'a');
	return 0;
}