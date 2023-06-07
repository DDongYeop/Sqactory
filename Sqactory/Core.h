#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <io.h>
#include <fcntl.h>
#include "Console.h"

#pragma once
typedef struct _tagpos
{
	int x;
	int y;
}POS, *PPOS;

class Core
{
public:
	char m_cMap[20][30] = {};

public:
	Core();
	~Core();

public:
	void Init();
	void Update(POS& _pPlayer);
	void Render();
};
