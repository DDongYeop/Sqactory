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
	//화면 크기 설정.
	system("mode con cols=60 lines=27");

	//창 이름 정해줌.
	SetConsoleTitle(TEXT("Sqactory")); 
	
	//스크린 조절 못 하게 해줌.
	HWND console = GetConsoleWindow();
	SetWindowLong(console, GWL_STYLE, GetWindowLong(console, GWL_STYLE) & ~WS_THICKFRAME);

	//커서 안 보이도록
	Cursorset(false, 1); 
}
