#pragma once
#include "Enemy.h"

class Ninja : public Enemy
{
public:
	Ninja();
	void attack();
	void setAttackPower();
};

