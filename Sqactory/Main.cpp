#include <iostream>
#include "Core.h"
using namespace std;

void Init();

int main()
{
	Init();
	Core* core = new Core();

	core->Init();
	while (true)
	{
		core->Render();
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
