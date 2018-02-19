#pragma once
#include <iostream>

class Enemy
{
public:
	virtual void attack() = 0;
	virtual void setAttackPower();
protected:
	int attackPower;
};

