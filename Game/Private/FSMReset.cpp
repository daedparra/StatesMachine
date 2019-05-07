#include "FSMStart.h"
#include "FSMReset.h"
#include "FSMPause.h"
#include "FSM.h"

FSMReset::FSMReset(FSM * pFSM, Clock* pClock) : FSMTimer(pFSM, pClock)
{
}

void FSMReset::OnEnter()
{
	//render
	exColor c;
	c.mColor[0] = 255;
	c.mColor[1] = 0;
	c.mColor[2] = 0;
	c.mColor[3] = 255;
	mClock->SetColor(c);
	mClock->SetTime();
}

void FSMReset::Update(float fDeltaT)
{
	//wait five seconds and change to green
	if (mClock->GetPlay()) {
		mFSM->Next(mFSM->Create<FSMStart>(mClock));
	}
	else if (mClock->GetReset()) {
	}

}
