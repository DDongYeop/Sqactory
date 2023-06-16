#pragma once
class Machine
{
public:
	Machine();
	~Machine();

public: 
	bool Upgrade(int& _playerMoney);

public:
	int		GetLevel()					{ return m_iLevel;	}
	void	SetLevel(int value)			{ m_iLevel = value; }
	int		GetMoney()					{ return m_iMoney;	}
	void	SetMoney(int value)			{ m_iMoney = value; }
	int		GetUpgradeCost()			{ return m_iUpgradeCost; }
	void	SetUpgradeCost(int value)	{ m_iUpgradeCost = value; }

private:
	int m_iLevel;
	int m_iMoney;
	int m_iUpgradeCost;
};

