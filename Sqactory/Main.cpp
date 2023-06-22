#include <iostream>
#include <Windows.h>
#include <vector>
#include "Core.h"
#include "Console.h"
#include "StartScene.h"
#include "Bottle.h"
#include "Machine.h"
#include "BottleManager.h"
#include "MachineManager.h"

using namespace std;

void Init();

int main()
{
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

	while (true)
	{
		cNearObj = Update(cMap, pPlayer, iMoney);
		Render(cMap, pPlayer, cNearObj, iMoney);
		AddBottle();
		BottleMovement(cMap, iMoney);
	}
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
