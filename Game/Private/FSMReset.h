#pragma once
#include "FSMTimer.h"
class FSMReset : public FSMTimer
{
public:
	FSMReset(FSM* pFSM, Clock* pClock);

	virtual void OnEnter() override;
	virtual void Update(float fDeltaT);

private:

};