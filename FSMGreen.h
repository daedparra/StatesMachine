#pragma once
#include "FSMLight.h"
#include "FSMYellow.h"

class FSMGreen : public FSMLight
{
public:
	FSMGreen(FSM* pFSM, GameObject* pGO);
	
	virtual void OnEnter() override;
	virtual void Update(float fDeltaT);
private:
	float mTime = 5.0f;
};