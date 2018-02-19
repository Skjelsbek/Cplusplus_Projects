#include "Ninja.h"



Ninja::Ninja()
{
}

void Ninja::attack()
{
	std::cout << "Ninja chop! -" << attackPower << std::endl;
}

void Ninja::setAttackPower()
{
	attackPower = 100;
}
