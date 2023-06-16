#include <iostream>
#include <Windows.h>
#include "Core.h"
#include "Console.h"
#include "StartScene.h"

#include "Bottle.h"

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

	Init(cMap, pPlayer);
	startScene->Title();

	system("cls");

	while (true)
	{
		Render(cMap, pPlayer);
		Update(cMap, pPlayer);
	}
}

void Init()
{
	//ȭ�� ũ�� ����.
	system("mode con cols=60 lines=27");

	//â �̸� ������.
	SetConsoleTitle(TEXT("Sqactory")); 
	
	//��ũ�� ���� �� �ϰ� ����.
	HWND console = GetConsoleWindow();
	SetWindowLong(console, GWL_STYLE, GetWindowLong(console, GWL_STYLE) & ~WS_THICKFRAME);

	//Ŀ�� �� ���̵���
	Cursorset(false, 1); 
}
