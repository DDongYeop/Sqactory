#include "MachineManager.h"

Machine* mMachines[3];

void MachineInit()
{
	for (int i = 0; i < 3; ++i)
		mMachines[i] = new Machine;
}

int GetAllMoney()
{
	int upMoney = 0;
	for (auto m : mMachines)
		upMoney += m->GetMoney();
	return upMoney;
}

int GetMachineIndex(int i, int j)
{
	switch (j)
	{
	case 1:
		return mMachines[i]->GetLevel();
	case 2:
		return mMachines[i]->GetUpgradeCost();
	case 3:
		return mMachines[i]->GetMoney();
	}
}

void MachineUpgrade(int i, int& _iMoney)
{
	mMachines[i]->Upgrade(_iMoney);
}
