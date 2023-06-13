#pragma once

typedef struct _tagpos
{
	int x;
	int y;
}POS, * PPOS;

void Init(char _cMap[20][30], POS& _pPlayer);
void Render(char _cMap[20][30], POS& _pPlayer);
void Update(char _cMap[20][30], POS& _pPlayer);