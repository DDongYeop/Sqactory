#include <iostream>
#include <Windows.h>
#include <vector>
#include <mmsystem.h>
#include <Digitalv.h>
#include <io.h>
#include <fcntl.h>
#include "Core.h"
#include "Console.h"
#include "StartScene.h"
#include "Bottle.h"
#include "Machine.h"
#include "BottleManager.h"
#include "MachineManager.h"

#pragma comment(lib, "winmm.lib")

using namespace std;

void Init();
void PlayerBgm();
void GameClear();

MCI_OPEN_PARMS openBgm; //여는거
MCI_OPEN_PARMS OoenEffect; //여는거
UINT Bgmid, Effectid;
float startTime;

int main()
{
	PlayerBgm();
	SetColor((int)COLOR::WHITE, (int)COLOR::BLACK);
	system("cls");
	Init();
	StartScene* startScene = new StartScene;

	char cMap[20][30] = {};
	POS pPlayer;
	char cNearObj;
	int iMoney = 0;
	startScene->Title();
	Init(cMap, pPlayer);
	MachineInit();

	system("cls");

	startTime = clock();

	while (true)
	{
		cNearObj = Update(cMap, pPlayer, iMoney);
		Render(cMap, pPlayer, cNearObj, iMoney);
		AddBottle(OoenEffect, Effectid);
		BottleMovement(cMap, iMoney, OoenEffect, Effectid);

		if (iMoney > 999)
			break;
	}

	GameClear();
}

void Init()
{
	//화면 크기 설정.
	system("mode con cols=60 lines=28");

	//창 이름 정해줌.
	SetConsoleTitle(TEXT("Sqactory")); 
	
	//스크린 조절 못 하게 해줌.
	HWND console = GetConsoleWindow();
	SetWindowLong(console, GWL_STYLE, GetWindowLong(console, GWL_STYLE) & ~WS_THICKFRAME);

	//커서 안 보이도록
	Cursorset(false, 1); 
}

void PlayerBgm()
{
	openBgm.lpstrDeviceType = TEXT("mpegvideo");
	openBgm.lpstrElementName = TEXT("Sound\\City of Backstreet.mp3");
	mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD_PTR)&openBgm);
	openBgm.wDeviceID;
	Bgmid = openBgm.wDeviceID;
	mciSendCommand(Bgmid, MCI_PLAY, MCI_DGV_PLAY_REPEAT, (DWORD_PTR)&openBgm);

}

void GameClear()
{
	SetColor((int)COLOR::WHITE, (int)COLOR::BLACK);
	system("cls");

	Gotoxy(0, 5);

	int prevmode = _setmode(_fileno(stdout), _O_U16TEXT);
	wcout << L"          ██████╗██╗     ███████╗ █████╗ ██████╗ \n";
	wcout << L"         ██╔════╝██║     ██╔════╝██╔══██╗██╔══██╗\n";
	wcout << L"         ██║     ██║     █████╗  ███████║██████╔╝\n";
	wcout << L"         ██║     ██║     ██╔══╝  ██╔══██║██╔══██╗\n";
	wcout << L"         ╚██████╗███████╗███████╗██║  ██║██║  ██║\n";
	wcout << L"          ╚═════╝╚══════╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝\n";
	int Curmode = _setmode(_fileno(stdout), prevmode);

	Gotoxy(0, 15);

	cout << "플레이타임 : " << (clock() - startTime) / 1000 << "초\n\n";

	cout << "다시 플레이는 ↑ \n게임종료는 ↓\n";
	while (true)
	{
		if (GetAsyncKeyState(VK_UP) & 0x8000)
		{
			main();
			break;
		}
		if (GetAsyncKeyState(VK_DOWN) & 0x8000)
			break;
	}

	Gotoxy(30, 17);
	cout << "\r수고하셨습니다. \n                            \n\n\n\n";
}
