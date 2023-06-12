#include <iostream>
#include <Windows.h>
#include <io.h>
#include <fcntl.h>
#include "StartScene.h"

using namespace std;

void StartScene::Title()
{
	int prevmode = _setmode(_fileno(stdout), _O_U16TEXT);
	wcout << "\n \n \n \n \n";
	Sleep(100);
	wcout << L"██████  █████   ████   █████ ██████  █████  ██████  ██    ██\n";
	Sleep(100);
	wcout << L"██     ██   ██ ██  ██ ██       ██   ██   ██ ██   ██  ██  ██ \n";
	Sleep(100);
	wcout << L"██████ ██   ██ ██████ ██       ██   ██   ██ ██████    ████  \n";
	Sleep(100);
	wcout << L"    ██ ██   ██ ██  ██ ██       ██   ██   ██ ██   ██    ██   \n";
	Sleep(100);
	wcout << L"██████  █████  ██  ██  █████   ██    █████  ██   ██    ██   \n";
	int Curmode = _setmode(_fileno(stdout), prevmode);

	Sleep(1000);
}

void StartScene::MenuSelect()
{
}