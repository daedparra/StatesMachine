#pragma once
#include "FSMLight.h"
#include "FSMRed.h"
class FSMYellow : public FSMLight
{
public:
	FSMYellow(FSM* pFSM, GameObject* pGO);

	virtual void OnEnter() override;
	virtual void Update(float fDeltaT);
private:
	float mTime = 2.0f;
};