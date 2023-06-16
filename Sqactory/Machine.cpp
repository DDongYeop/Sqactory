#include "Machine.h"

Machine::Machine() : m_iLevel{0}, m_iMoney{0}, m_iUpgradeCost{0}
{
}

Machine::~Machine()
{
}

bool Machine::Upgrade(int& _playerMoney)
{
	if (_playerMoney < m_iUpgradeCost)
		return false;

	_playerMoney -= m_iUpgradeCost;
	++m_iLevel;

	// UpgradeCost add
	// Money up

	return true;
}
