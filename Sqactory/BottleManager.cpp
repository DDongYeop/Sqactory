#include <list>
#include <Windows.h>
#include <ctime>
#include <mmsystem.h>
#include <Digitalv.h>
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

void AddBottle(MCI_OPEN_PARMS& OoenEffect, UINT& Effectid)
{
	spawnIndex++;

	if (spawnIndex % 40 == 0)
	{
		spawnIndex = 0;
		Bottle* bottle = new Bottle();
		m_lBottleList.push_back(bottle);
		PlayAddBottle(OoenEffect, Effectid);
	}
}

void BottleMovement(char cMap[20][30], int& iMoney, MCI_OPEN_PARMS& OoenEffect, UINT& Effectid)
{
	moveIndex++;

	if (moveIndex % 3 == 0)
	{
		moveIndex = 0;
		for (auto b : m_lBottleList)
			if (b->Movement(cMap, iMoney, OoenEffect, Effectid) == 1)
				break;
	}
}

void BottleDelete(int& iMoney, MCI_OPEN_PARMS& OoenEffect, UINT& Effectid)
{
	delete(m_lBottleList.front());
	m_lBottleList.pop_front();
	iMoney += GetAllMoney() + 1;
	PlayAddMoney(OoenEffect, Effectid);
}

void PlayAddBottle(MCI_OPEN_PARMS& OoenEffect, UINT& Effectid)
{
	OoenEffect.lpstrDeviceType = TEXT("waveaudio");
	OoenEffect.lpstrElementName = TEXT("Sound\\AddBottle.wav");
	mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD_PTR)&OoenEffect);
	OoenEffect.wDeviceID;
	Effectid = OoenEffect.wDeviceID;
	mciSendCommand(Effectid, MCI_PLAY, MCI_NOTIFY, (DWORD_PTR)&OoenEffect);
	Sleep(50);
	mciSendCommand(Effectid, MCI_SEEK, MCI_SEEK_TO_START, (DWORD_PTR)&OoenEffect);
}

void PlayAddMoney(MCI_OPEN_PARMS& OoenEffect, UINT& Effectid)
{
	OoenEffect.lpstrDeviceType = TEXT("waveaudio");
	OoenEffect.lpstrElementName = TEXT("Sound\\AddMoney.wav");
	mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD_PTR)&OoenEffect);
	OoenEffect.wDeviceID;
	Effectid = OoenEffect.wDeviceID;
	mciSendCommand(Effectid, MCI_PLAY, MCI_NOTIFY, (DWORD_PTR)&OoenEffect);
	Sleep(50);
	mciSendCommand(Effectid, MCI_SEEK, MCI_SEEK_TO_START, (DWORD_PTR)&OoenEffect);
}
