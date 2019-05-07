#pragma once
#include "FSMMachine.h"
class FSMCoins : public FSMMachine
{
public:
	FSMCoins(FSM* pFSM, Drink* pDrink);

	virtual void OnEnter() override;
	virtual void Update(float fDeltaT);

private:
	float waitTime = 2.0f;
};