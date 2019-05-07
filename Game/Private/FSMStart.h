#pragma once
#include "FSMTimer.h"
class FSMStart : public FSMTimer
{
public:
	FSMStart(FSM* pFSM, Clock* pClock);

	virtual void OnEnter() override;
	virtual void Update(float fDeltaT);

private:
	
};