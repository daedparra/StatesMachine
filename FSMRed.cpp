#include "FSMRed.h"
#include "FSMGreen.h"
#include "FSM.h"

FSMRed::FSMRed(FSM * pFSM, GameObject* pGO) : FSMLight(pFSM, pGO)
{
}

void FSMRed::OnEnter()
{
	//render
	exColor red;
	red.mColor[0] = 255;
	red.mColor[1] = 0;
	red.mColor[2] = 0;
	red.mColor[3] = 255;
	exVector2 position;
	position.x = kViewportWidth / 2 - 50;
	position.y = kViewportHeight / 2 - 160;
	mGO->SetColor(red);
	mGO->SetPosition(position);

}

void FSMRed::Update(float fDeltaT)
{
	//wait five seconds and change to green
	mTime -= fDeltaT;
	if (mTime <= 0.0f) {
		mFSM->Next(mFSM->Create<FSMGreen>(mGO));
	}
}
