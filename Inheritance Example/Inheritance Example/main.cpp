#include <iostream>
#include <string>

using namespace std;

class Buddy
{
public:
	void attack() { cout << "Buddy attacking!" << endl; }
	void dodge() { cout << "Buddy dodged!" << endl; }
};

class Enemy
{
public:
	virtual void attack() = 0;
	virtual void setAttackPower() { attackPower = 50; }
protected:
	int attackPower;
};

class Ninja : public Enemy, public Buddy
{
public:
	void attack() { cout << "Ninja chop! -" << attackPower << endl; }
	void setAttackPower() { attackPower = 100; }
	void dodge() { cout << "Ninja super backflip dodge!" << endl; }
};

class Monster : public Enemy
{
public:
	void attack() { cout << "Eating you from under your bed! -" << attackPower << endl; }
};

class Machine
{
public:
	Machine(int id, string name) { m_id = id; m_name = name; }
	virtual void start() { cout << "Machine starting!" << endl; }
protected:
	int m_id;
	string m_name;
};

class CoffeeMaker : public Machine
{
public:
	CoffeeMaker(int id, string name) : Machine(id, name) {}
	void start() { cout << m_name << m_id << " making coffee..." << endl; coffeePotFull = true; }
private:
	bool coffeePotFull;
};

int main()
{
	Machine *cm = new CoffeeMaker(10000, "Moccamaster");
	cm->start();
	system("pause");
	return 0;
}

/*Buddy *b1 = new Ninja;
b1->attack();
b1->dodge();

Enemy *e1 = new Ninja;
Enemy *e2 = new Monster;
e1->setAttackPower();
e2->setAttackPower();
e1->attack();
e2->attack();

delete e1, e2;*/