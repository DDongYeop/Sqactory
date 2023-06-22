#include <Windows.h>
#include "Bottle.h"
#include "BottleManager.h"

Bottle::Bottle()
{
	c_mPrise = 0;
	c_mLastMap = '3';
	c_mPosition.x = 0;
	c_mPosition.y = 2;
}

Bottle::~Bottle()
{
}

int Bottle::Movement(char cMap[20][30], int& iMoney)
{
	if (c_mLastMap == '3')
		cMap[c_mPosition.y][c_mPosition.x] = '3';

	if (c_mPosition.x < 25)
	{
		if (c_mPosition.y < 3)
			++c_mPosition.x;
		else
			--c_mPosition.x;
	}
	else
	{
		if (c_mPosition.y <= 16)
			++c_mPosition.y;
		else
			--c_mPosition.x;
	}

	if (c_mPosition.x < 0)
	{
		c_mLastMap = cMap[c_mPosition.y][c_mPosition.x];
		if (cMap[c_mPosition.y][c_mPosition.x] == '3')
			cMap[c_mPosition.y][c_mPosition.x] = '2';

		BottleDelete(iMoney);
		return 1;
	}

	if (cMap)
	{
		c_mLastMap = cMap[c_mPosition.y][c_mPosition.x];
		if (cMap[c_mPosition.y][c_mPosition.x] == '3')
		{
			cMap[c_mPosition.y][c_mPosition.x] = '2';
		}
	}

	return 0;
}
