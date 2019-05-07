#include "FSMYellow.h"
#include "FSM.h"
#include "FSMREd.h"

FSMYellow::FSMYellow(FSM * pFSM, GameObject* pGO) : FSMLight(pFSM, pGO)
{
}

void FSMYellow::OnEnter()
{
	//render
	exColor yellow;
	yellow.mColor[0] = 255;
	yellow.mColor[1] = 255;
	yellow.mColor[2] = 0;
	yellow.mColor[3] = 255;
	exVector2 position;
	position.x = kViewportWidth / 2 - 50;
	position.y = kViewportHeight / 2;
	mGO->SetColor(yellow);
	mGO->SetPosition(position);

}

void FSMYellow::Update(float fDeltaT)
{
	//wait five seconds and change to green
	mTime -= fDeltaT;
	if (mTime <= 0.0f) {
		mFSM->Next(mFSM->Create<FSMRed>(mGO));
	}
}
