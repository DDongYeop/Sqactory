#include <iostream>
#include "Core.h"
using namespace std;

int main()
{
	Core* core = new Core();

	core->Init();
	while (true)
	{
		core->Render();
	}
}
