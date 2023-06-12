#include <iostream>
#include "Core.h"
#include "StartScene.h"
using namespace std;

void Init();

int main()
{
	Init();
	Core* core = new Core();
	StartScene* startScene = new StartScene();
	
	core->Init();
	startScene->Title();

	system("cls");

	while (true)
	{
		core->Render();
		core->Update();
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
