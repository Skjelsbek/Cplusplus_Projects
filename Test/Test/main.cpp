#include <iostream>
#include <thread>
#include "Monster.h"
#include "Ninja.h"

int **getArr()
{
	int **arr = new int*[10];
	for (int i = 0; i < 10; i++)
		arr[i] = new int[10];

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			arr[i][j] = j;
		}
	}

	return arr;
}

int main()
{
	/*int **arr = getArr();

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			std::cout << arr[i][j] << std::endl;
		}
	}
	
	for (int i = 0; i < 10; i++)
		delete[] arr[i];

	delete[] arr;*/

	Enemy *e1 = new Ninja;
	Enemy *e2 = new Monster;
	e1->setAttackPower();
	e2->setAttackPower();
	e1->attack();
	e2->attack();

	system("pause");
	return 0;
}