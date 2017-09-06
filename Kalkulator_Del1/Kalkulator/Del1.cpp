#include <iostream>
#include <string>

int main() 
{	
	std::string sTall1, sTall2, sRegneart;
	double fTall1, fTall2, svar;
	char cRegneart;
	bool feilRegneArt = false, delePaNull = false, ikkeTall1 = false, ikkeTall2 = false, punktum = false;

	// Bruker getInput funksjonen til å hente data fra bruker
	std::cout << "Skriv inn tall 1" << std::endl;
	getline(std::cin, sTall1);
	std::cout << "Skriv onsket regneart" << std::endl;
	cRegneart = getchar();
	std::cout << "Skriv inn tall 2" << std::endl;
	getline(std::cin, sTall2);

	// Sjekker den innhentede regnearten
	if (sRegneart.length() > 1) 
	{
		feilRegneArt = true;
	}
	else 
	{
		cRegneart = sRegneart[0];
	}
	
	// Sjekker om sTall1 er et tall
	for (int i = 0; i < sTall1.length(); i++) 
	{
		if (!isdigit(sTall1[i])) 
		{
			if (sTall1[i] == '.' && !punktum) 
			{
				punktum = true;
			}
			else 
			{
				ikkeTall1 = true;
				break;
			}
		}
	}

	punktum = false;	// Tilbakestiller punktum for å kunne bruke den på nytt

	// Sjekker sTall2
	for (int i = 0; i < sTall2.length(); i++) 
	{
		if (!isdigit(sTall2[i])) 
		{
			if (sTall2[i] == '.' && !punktum)
			{
				punktum = true;
			}
			else
			{
				ikkeTall2 = true;
				break;
			}
		}
	}

	// Hvis det er skrevet inn ordentlige tall og regneart så vil programmet kjøre videre
	if (ikkeTall1 == false && ikkeTall2 == false && feilRegneArt == false) 
	{	
		// Gjør om tallene fra string til float
		fTall1 = std::stof(sTall1);
		fTall2 = std::stof(sTall2);

		// Utfører riktig regneoperasjon
		switch (cRegneart)
		{
		case '+': svar = fTall1 + fTall2;
			break;
		case '-': svar = fTall1 - fTall2;
			break;
		case '*': svar = fTall1 * fTall2;
			break;
		case '/':
			// Sjekker om bruker prøver å dele på null
			if (fTall2 != 0)
			{
				svar = fTall1 / fTall2;
				break;
			}
			else
			{
				delePaNull = true;
				std::cout << "Trodde du visste at det var dumt a dele pa null?!?" << std::endl;
				break;
			}
		default: std::cout << cRegneart << " ser ikke ut til a vere en regneart gitt.." << std::endl;
			feilRegneArt = true;
		}

		// Skriver ut svar om det ikke har blitt gjort en feil
		if (delePaNull == false && feilRegneArt == false) 
		{
			std::cout << "Svaret pa " << fTall1 << " " << cRegneart << " " << fTall2 << " er " << svar << std::endl;
		}

	}
	else
	{
		std::cout << "Det pleier a vere greit a regne med tall og en normal regneart.." << std::endl;
	}

	system("PAUSE");
	return 0;
}