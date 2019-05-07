#pragma once

#include "FSMLight.h"

class FSMRed : public FSMLight
{
public:
	FSMRed(FSM* pFSM, GameObject* pGO);

	virtual void OnEnter() override;
	virtual void Update(float fDeltaT);
private:
	float mTime = 3.0f;
};