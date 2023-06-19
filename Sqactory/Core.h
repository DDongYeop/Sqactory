#include "Machine.h"
#include <vector>

using namespace std;

#pragma once

typedef struct _tagpos
{
	int x;
	int y;
}POS, * PPOS;

void Init(char _cMap[20][30], POS& _pPlayer);
char Update(char _cMap[20][30], POS& _pPlayer);
void Render(char _cMap[20][30], POS& _pPlayer, char _cNearObj, vector<Machine*> machines);