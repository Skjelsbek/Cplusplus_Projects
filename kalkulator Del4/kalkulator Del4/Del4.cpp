#include <iostream>
#include <string>

std::string getInput() {
	std::string input = "";
	char c = std::cin.get();
	while (c != '\n') {
		input += c;
		c = std::cin.get();
	}
	return input;
}

int main() {
	char runAgain;
	std::string uttrykk;

	std::cout << "Skriv inn regnestykket:" << std::endl;
	uttrykk = getInput();
	std::cout << uttrykk << std::endl;
	system("PAUSE");

	do {
		system("cls");

		std::cout << "Trykk 'a' for å avslutte programmet, alt annet starter programmet på nytt." << std::endl;
		runAgain = std::cin.get();
	} while (runAgain != 'a');

	system("PAUSE");
	return 0;
}