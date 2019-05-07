#include "FSMLight.h"

FSMLight::FSMLight(FSM* pFSM, GameObject* pGO)
	: FSMState(pFSM), mGO(pGO)
{
}


FSMLight::~FSMLight()
{
}