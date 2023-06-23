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

	cout << "\n \n \n \n \n";
	Sleep(500);
	for (auto c : "플레이어는 방향키로 움직입니다. (→, ←, ↑, ↓)")
	{
		cout << c;
		Sleep(10);
	}
	cout << "\n\n";
	Sleep(200);

	for (auto c : "기계에 다가가 Space를 누르면 업그레이드 됩니다.")
	{
		cout << c;
		Sleep(10);
	}
	cout << "\n\n";
	Sleep(200);

	for (auto c : "빠르게 1000원을 버세요.")
	{
		cout << c;
		Sleep(10);
	}
	cout << "\n\n";
	Sleep(200);
	
	for (auto c : "행운을 빕니다.")
	{
		cout << c;
		Sleep(10);
	}
	Sleep(400);
}

void StartScene::MenuSelect()
{
}