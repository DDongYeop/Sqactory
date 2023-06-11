#include "Core.h"

using namespace std;

Core::Core()
{
}

Core::~Core()
{
}

void Core::Init()
{
	m_pPlayer.x = 15;
	m_pPlayer.y = 10;

	strcpy_s(m_cMap[0],  "00044444444000555555550000000");
	strcpy_s(m_cMap[1],  "33344444444333555555553333300");
	strcpy_s(m_cMap[2],  "33344444444333555555553333300");
	strcpy_s(m_cMap[3],  "33344444444333555555553333300");
	strcpy_s(m_cMap[4],  "00044444444000555555550033300");
	strcpy_s(m_cMap[5],  "00000000000000000000000033300");
	strcpy_s(m_cMap[6],  "00000000000000000000000033300");
	strcpy_s(m_cMap[7],  "00000000000000000000000666660");
	strcpy_s(m_cMap[8],  "88000000000000000000000666660");
	strcpy_s(m_cMap[9],  "88000000000000000000000666660");
	strcpy_s(m_cMap[10], "88000000000000100000000666660");
	strcpy_s(m_cMap[11], "88000000000000000000000666660");
	strcpy_s(m_cMap[12], "88000000000000000000000666660");
	strcpy_s(m_cMap[13], "00000000000000000000000666660");
	strcpy_s(m_cMap[14], "00000000000000000000000033300");
	strcpy_s(m_cMap[15], "00000000000000000000000033300");
	strcpy_s(m_cMap[16], "00000000000000333333333333300");
	strcpy_s(m_cMap[17], "00000000000000333333333333300");
	strcpy_s(m_cMap[18], "00000000000000333333333333300");
	strcpy_s(m_cMap[19], "00000000000000000000000000000");
}

void Core::Update()
{
	if (GetAsyncKeyState(VK_UP) & 0x8000)
	{
		if (m_pPlayer.y - 1 > 0 && *m_cMap[m_pPlayer.y - 1, m_pPlayer.x] == '0')
		{
			//m_cMap[m_pPlayer.y, m_pPlayer.x] = '0';
			strcat_s(m_cMap[m_pPlayer.y, m_pPlayer.x], "0");
			SetColor((int)COLOR::BLACK, (int)COLOR::LIGHT_RED);
			--m_pPlayer.y;
			//cout << *m_cMap[m_pPlayer.y, m_pPlayer.x];
			strcat_s(m_cMap[m_pPlayer.y, m_pPlayer.x], "0");
		}
		Sleep(100);
	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
	{
		if (m_pPlayer.y + 1 < 20 && *m_cMap[m_pPlayer.y + 1, m_pPlayer.x] == '0')
		{
			*m_cMap[m_pPlayer.y, m_pPlayer.x] = '0';
			++m_pPlayer.y;
			*m_cMap[m_pPlayer.y, m_pPlayer.x] = '1';
		}
		Sleep(100);
	}
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		if (m_pPlayer.x - 1 > 0 && *m_cMap[m_pPlayer, m_pPlayer.x - 1] == '0')
		{
			*m_cMap[m_pPlayer.y, m_pPlayer.x] = '0';
			--m_pPlayer.y;
			*m_cMap[m_pPlayer.y, m_pPlayer.x] = '1';
		}
		Sleep(100);
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		if (m_pPlayer.x + 1 < 30 && *m_cMap[m_pPlayer.y, m_pPlayer.x + 1] == '0')
		{
			*m_cMap[m_pPlayer.y, m_pPlayer.x] = '0';
			++m_pPlayer.y;
			*m_cMap[m_pPlayer.y, m_pPlayer.x] = '1';
		}
		Sleep(100);
	}

}

void Core::Render()
{
	int prevmode = _setmode(_fileno(stdout), _O_U16TEXT);
	Gotoxy(0, 0);
	for (int y = 0; y < 20; ++y)
	{
		for (int x = 0; x < 30; ++x)
		{
			switch (m_cMap[y][x])
			{
			case '0':
				SetColor((int)COLOR::WHITE, (int)COLOR::WHITE);
				break;
			case '1':
				SetColor((int)COLOR::BLACK, (int)COLOR::BLACK);
				break;
			case '2':
				SetColor((int)COLOR::RED, (int)COLOR::RED);
				break;
			case '3':
				SetColor((int)COLOR::GRAY, (int)COLOR::GRAY);
				break;
			case '4':
				SetColor((int)COLOR::LIGHY_VIOLET, (int)COLOR::LIGHY_VIOLET);
				break;
			case '5':
				SetColor((int)COLOR::YELLOW, (int)COLOR::YELLOW);
				break;
			case '6':
				SetColor((int)COLOR::LIGHT_RED, (int)COLOR::LIGHT_RED);
				break;
			case '7':
				SetColor((int)COLOR::YELLOW, (int)COLOR::YELLOW);
				break;
			case '8':
				SetColor((int)COLOR::GREEN, (int)COLOR::GREEN);
				break;
			default:
				break;
			}
			wcout << L"██";
		}
		wcout << '\n';
	}
	int Curmode = _setmode(_fileno(stdout), prevmode);
}
