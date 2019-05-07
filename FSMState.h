#pragma once

class FSM;

class FSMState
{
public:
	FSMState(FSM* pFSM);

	virtual ~FSMState();
	virtual void OnEnter() {}
	virtual void OnExit() {}
	virtual void Update(float FDeltaT) {}

protected:
	FSM* mFSM;
};

