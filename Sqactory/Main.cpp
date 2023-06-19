#include <iostream>
#include <Windows.h>
#include <vector>
#include "Core.h"
#include "Console.h"
#include "StartScene.h"
#include "Bottle.h"
#include "Machine.h"

using namespace std;

void Init();

int main()
{
	SetColor((int)COLOR::WHITE, (int)COLOR::BLACK);
	system("cls");
	Init();
	StartScene* startScene = new StartScene;
	vector<Machine*> machines;
	for (int i = 0; i < 3; ++i)
		machines.push_back(new Machine());

	char cMap[20][30] = {};
	POS pPlayer;
	char cNearObj;

	Init(cMap, pPlayer);
	startScene->Title();

	system("cls");

	while (true)
	{
		cNearObj = Update(cMap, pPlayer);
		Render(cMap, pPlayer, cNearObj, machines);
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
