#pragma once
#include "Core.h"

class Bottle
{
public:
	Bottle();
	~Bottle();

public:
	void Movement(char cMap[20][30]);

private:
	POS c_mPosition;
	char c_mLastMap;
	int c_mPrise;
};

