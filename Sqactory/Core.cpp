﻿#include <iostream>
#include <Windows.h>
#include <io.h>
#include <fcntl.h>
#include "Core.h"
#include "Console.h"
#include "MachineManager.h"

using namespace std;

char cNearIndex;

void Init(char _cMap[20][30], POS& _pPlayer)
{
	_pPlayer.x = 14;
	_pPlayer.y = 10;

	strcpy_s(_cMap[0],  "00000444444444444440000000000");
	strcpy_s(_cMap[1],  "33333444444444444443333333300");
	strcpy_s(_cMap[2],  "33333444444444444443333333300");
	strcpy_s(_cMap[3],  "33333444444444444443333333300");
	strcpy_s(_cMap[4],  "00000444444444444440000033300");
	strcpy_s(_cMap[5],  "00000000000000000000000033300");
	strcpy_s(_cMap[6],  "00000000000000000000000555550");
	strcpy_s(_cMap[7],  "00000000000000000000000555550");
	strcpy_s(_cMap[8],  "00000000000000000000000555550");
	strcpy_s(_cMap[9],  "00000000000000000000000555550");
	strcpy_s(_cMap[10], "00000000000000100000000555550");
	strcpy_s(_cMap[11], "00000000000000000000000555550");
	strcpy_s(_cMap[12], "00000000000000000000000555550");
	strcpy_s(_cMap[13], "00000000000000000000000555550");
	strcpy_s(_cMap[14], "00000000000000000000000033300");
	strcpy_s(_cMap[15], "00000666666666666660000033300");
	strcpy_s(_cMap[16], "33333666666666666663333333300");
	strcpy_s(_cMap[17], "33333666666666666663333333300");
	strcpy_s(_cMap[18], "33333666666666666663333333300");
	strcpy_s(_cMap[19], "00000666666666666660000000000");
}

char Update(char _cMap[20][30], POS& _pPlayer, int& _iMoney)
{
	if (GetAsyncKeyState(VK_UP) & 0x8000)
	{
		if (_pPlayer.y - 1 > -1 && _cMap[_pPlayer.y - 1][_pPlayer.x] == '0')
		{
			_cMap[_pPlayer.y][_pPlayer.x] = '0';
			--_pPlayer.y;
			_cMap[_pPlayer.y][_pPlayer.x] = '1';
		}
		Sleep(75);
	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
	{
		if (_pPlayer.y + 1 < 19 && _cMap[_pPlayer.y + 1][_pPlayer.x] == '0')
		{
			_cMap[_pPlayer.y][_pPlayer.x] = '0';
			++_pPlayer.y;
			_cMap[_pPlayer.y][_pPlayer.x] = '1';
		}
		Sleep(75);
	}
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		if (_pPlayer.x - 1 > 0 && _cMap[_pPlayer.y][_pPlayer.x - 1] == '0')
		{
			_cMap[_pPlayer.y][_pPlayer.x] = '0';
			--_pPlayer.x;
			_cMap[_pPlayer.y][_pPlayer.x] = '1';
		}
		Sleep(75);
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		if (_pPlayer.x + 1 < 28 && _cMap[_pPlayer.y][_pPlayer.x + 1] == '0')
		{
			_cMap[_pPlayer.y][_pPlayer.x] = '0';
			++_pPlayer.x;
			_cMap[_pPlayer.y][_pPlayer.x] = '1';
		}
		Sleep(75);
	}

	if		(_cMap[_pPlayer.y + 1][_pPlayer.x] != '0' && _cMap[_pPlayer.y + 1][_pPlayer.x] != '3')
		cNearIndex = _cMap[_pPlayer.y + 1][_pPlayer.x];
	else if (_cMap[_pPlayer.y - 1][_pPlayer.x] != '0' && _cMap[_pPlayer.y - 1][_pPlayer.x] != '3')
		cNearIndex = _cMap[_pPlayer.y - 1][_pPlayer.x];
	else if (_cMap[_pPlayer.y][_pPlayer.x + 1] != '0' && _cMap[_pPlayer.y][_pPlayer.x + 1] != '3')
		cNearIndex = _cMap[_pPlayer.y][_pPlayer.x + 1];
	else if (_cMap[_pPlayer.y][_pPlayer.x - 1] != '0' && _cMap[_pPlayer.y][_pPlayer.x - 1] != '3')
		cNearIndex = _cMap[_pPlayer.y][_pPlayer.x - 1];
	else
		cNearIndex = '0';
	
	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
	{
		switch (cNearIndex)
		{
		case '4':
			MachineUpgrade(0, _iMoney);
			break;
		case '5':
			MachineUpgrade(1, _iMoney);
			break;
		case '6':
			MachineUpgrade(2, _iMoney);
			break;
		}
	}

	return cNearIndex;
} 
 
void Render(char _cMap[20][30], POS& _pPlayer, char _cNearObj, int _iMoney)
{
	int prevmode = _setmode(_fileno(stdout), _O_U16TEXT);
	Gotoxy(0, 0);
	for (int y = 0; y < 20; ++y)
	{
		for (int x = 0; x < 30; ++x)
		{
			switch (_cMap[y][x])
			{
			case '0':
				SetColor((int)COLOR::WHITE, (int)COLOR::WHITE);
				break;
			case '1':
				SetColor((int)COLOR::BLACK, (int)COLOR::BLACK);
				break;
			case '2':
				SetColor((int)COLOR::RED, (int)COLOR::RED);
				break;
			case '3':
				SetColor((int)COLOR::GRAY, (int)COLOR::GRAY);
				break;
			case '4':
				SetColor((int)COLOR::LIGHY_VIOLET, (int)COLOR::LIGHY_VIOLET);
				break;
			case '5':
				SetColor((int)COLOR::YELLOW, (int)COLOR::YELLOW);
				break;
			case '6':
				SetColor((int)COLOR::LIGHT_RED, (int)COLOR::LIGHT_RED);
				break;
			case '7':
				SetColor((int)COLOR::YELLOW, (int)COLOR::YELLOW);
				break;
			case '8':
				SetColor((int)COLOR::GREEN, (int)COLOR::GREEN);
				break;
			default:
				break;
			}
			wcout << L"██";
		}
		wcout << '\n';
		SetColor((int)COLOR::WHITE, (int)COLOR::BLACK);
	}
	int Curmode = _setmode(_fileno(stdout), prevmode);

	SetColor((int)COLOR::LIGHT_YELLOW, (int)COLOR::BLACK);
	Gotoxy(30, 21);
	cout << "\rMoney : " << _iMoney;
	SetColor((int)COLOR::WHITE, (int)COLOR::BLACK);

	if (_cNearObj != '0')
	{
		switch (_cNearObj)
		{
		case '4':
			Gotoxy(30, 23);
			cout << "\r  Beverrage machine";

			Gotoxy(30, 24);
			cout << "\r  LEVEL : " << GetMachineIndex(0, 1);

			Gotoxy(30, 25);
			cout << "\r  UpgradeCost : " << GetMachineIndex(0, 2);

			Gotoxy(30, 26);
			cout << "\r  Money : " << GetMachineIndex(0, 2);
			break;
		case '5':
			Gotoxy(30, 23);
			cout << "\r  Label machine";

			Gotoxy(30, 24);
			cout << "\r  LEVEL : " << GetMachineIndex(1, 1);

			Gotoxy(30, 25);
			cout << "\r  UpgradeCost : " << GetMachineIndex(1, 2);

			Gotoxy(30, 26);
			cout << "\r  Money : " << GetMachineIndex(1, 3);
			break;
		case '6':
			Gotoxy(30, 23);
			cout << "\r  Cap machine";

			Gotoxy(30, 24);
			cout << "\r  LEVEL : " << GetMachineIndex(2, 1);

			Gotoxy(30, 25);
			cout << "\r  UpgradeCost : " << GetMachineIndex(2, 2);

			Gotoxy(30, 26);
			cout << "\r  Money : " << GetMachineIndex(2, 3);
			break;
		}
	}
	else
	{
		Gotoxy(30, 23);
		cout << "\r                              ";
		Gotoxy(30, 24);
		cout << "\r                              ";
		Gotoxy(30, 25);
		cout << "\r                              ";
		Gotoxy(30, 26);
		cout << "\r                              ";
	}
}
