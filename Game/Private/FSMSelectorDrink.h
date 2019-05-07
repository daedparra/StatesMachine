#pragma once
#include "FSMMachine.h"
class FSMSelectorDrink : public FSMMachine
{
public:
	FSMSelectorDrink(FSM* pFSM, Drink* pDrink);

	virtual void OnEnter() override;
	virtual void Update(float fDeltaT);
private:
	float waitTime = 2.0f;
};