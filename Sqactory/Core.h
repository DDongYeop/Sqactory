#pragma once
typedef struct _tagpos
{
	int x;
	int y;
}POS, *PPOS;

class Core
{
private:
	Core();
	~Core();

public:
	void Init(POS &_pPlayer);
	void Update(POS& _pPlayer);
	void Render(POS& _pPlayer);
};
