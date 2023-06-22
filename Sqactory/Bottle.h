#pragma once
#include "Core.h"

class Bottle
{
public:
	Bottle();
	~Bottle();

public:
	int Movement(char cMap[20][30], int &iMoney);

private:
	POS c_mPosition;
	char c_mLastMap;
	int c_mPrise;
};

