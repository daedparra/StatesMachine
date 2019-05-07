#pragma once
#include "FSMState.h"
#include "Drink.h"
class FSMMachine : public FSMState
{
public:
	FSMMachine(FSM* pFSM, Drink* pDrink);
	~FSMMachine();

protected:
	Drink* mDrink;
};


