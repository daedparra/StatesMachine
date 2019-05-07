#pragma once
#include "FSMTimer.h"
class FSMPause : public FSMTimer
{
public:
	FSMPause(FSM* pFSM, Clock* pClock);

	virtual void OnEnter() override;
	virtual void Update(float fDeltaT);

private:

};