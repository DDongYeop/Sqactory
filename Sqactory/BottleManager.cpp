#include <list>
#include "Bottle.h"
#include "BottleManager.h"

using namespace std;

// Bottle* bottle = new Bottle();

list<Bottle*> m_lBottleList; 

void AddBottle()
{
	Bottle* bottle = new Bottle();
	m_lBottleList.push_back(bottle);
}

void BottleMovement(char cMap[20][30])
{
	for (auto b : m_lBottleList)
		b->Movement(cMap);
}

void BottleDelete()
{
	m_lBottleList.erase(m_lBottleList.begin());
}
