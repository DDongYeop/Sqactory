#include <list>
#include <Windows.h>
#include <ctime>
#include "Bottle.h"
#include "BottleManager.h"
#include "MachineManager.h"

using namespace std;

int spawnIndex = -1;
int moveIndex = -1;
list<Bottle*> m_lBottleList; 

void BottleManagerInit(int& iMoney)
{
}

void AddBottle()
{
	spawnIndex++;

	if (spawnIndex % 40 == 0)
	{
		spawnIndex = 0;
		Bottle* bottle = new Bottle();
		m_lBottleList.push_back(bottle);
	}
}

void BottleMovement(char cMap[20][30], int& iMoney)
{
	moveIndex++;

	if (moveIndex % 3 == 0)
	{
		moveIndex = 0;
		for (auto b : m_lBottleList)
			if (b->Movement(cMap, iMoney) == 1)
				break;
	}
}

void BottleDelete(int& iMoney)
{
	delete(m_lBottleList.front());
	m_lBottleList.pop_front();
	iMoney += GetAllMoney() + 1;
}
