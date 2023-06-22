#include "Machine.h"

Machine::Machine() : m_iLevel{1}, m_iMoney{0}, m_iUpgradeCost{1}
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

	m_iUpgradeCost *= 2;
	++m_iMoney;

	return true;
}
