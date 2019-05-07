#pragma once
#include "FSMState.h"
#include "GameObject.h"
class FSMLight : public FSMState
{
public:
	FSMLight(FSM* pFSM, GameObject* pGO);
	~FSMLight();

protected :
	GameObject* mGO;
};

