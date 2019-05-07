#pragma once
#include "FSMState.h"
#include "Clock.h"
class FSMTimer : public FSMState
{
public:
	FSMTimer(FSM* pFSM, Clock* pClock);
	~FSMTimer();

protected:
	Clock* mClock;
};


