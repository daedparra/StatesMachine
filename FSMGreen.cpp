#include "FSMGreen.h"
#include "FSMYellow.h"
#include "FSM.h"

FSMGreen::FSMGreen(FSM * pFSM, GameObject* pGO) : FSMLight(pFSM, pGO)
{
}

void FSMGreen::OnEnter()
{
	exColor green;
	green.mColor[0] = 0;
	green.mColor[1] = 255;
	green.mColor[2] = 0;
	green.mColor[3] = 255;
	exVector2 position;
	position.x = kViewportWidth / 2 - 50;
	position.y = kViewportHeight / 2 + 160;
	mGO->SetColor(green);
	mGO->SetPosition(position);

}

void FSMGreen::Update(float fDeltaT)
{
	//wait five seconds and change to yellow
	mTime -= fDeltaT;
	if (mTime <= 0.0f) {
		mFSM->Next(mFSM->Create<FSMYellow>(mGO));
	}
}
