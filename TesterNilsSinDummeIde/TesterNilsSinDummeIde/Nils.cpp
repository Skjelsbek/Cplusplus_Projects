#include <iostream>
#include <sstream>

int main() 
{
	char *c1 = new char[11];
	char *c2 = new char[11];

	c1 = "Helloworld";
	c2 = "Helloworld";

	//int i1 = (int)c1;
	int i1 = reinterpret_cast<int>(c1);
	int i2 = (int)c2;
	if (i1 == i2)
	{
		std::cout << "Det funker" << std::endl;
	}

	int nils = 20;
	int marthe = 35;

	std::ostringstream oss;
	oss << nils << ":" << marthe;
	
	oss.str();

	int i = 0;
	for (int i = 0; i < oss.str().length(); i++)
	{
		if (oss.str()[i] != ':')
		{
			std::cout << oss.str()[i];
		}

	}
	std::cout << std::endl;

	system("PAUSE");
}