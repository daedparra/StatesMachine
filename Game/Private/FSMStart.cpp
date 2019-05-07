#include "FSMStart.h"
#include "FSMReset.h"
#include "FSMPause.h"
#include "FSM.h"

FSMStart::FSMStart(FSM * pFSM, Clock* pClock) : FSMTimer(pFSM, pClock)
{
}

void FSMStart::OnEnter()
{
	//render
	exColor c;
	c.mColor[0] = 0;
	c.mColor[1] = 255;
	c.mColor[2] = 0;
	c.mColor[3] = 255;
	mClock->SetColor(c);
}

void FSMStart::Update(float fDeltaT)
{
	//wait five seconds and change to green
	if (mClock->GetPlay()) { 
		
	}
	else if (mClock->GetPause()) {
		mFSM->Next(mFSM->Create<FSMPause>(mClock));
	}
	else if(mClock->GetReset()) {
		mFSM->Next(mFSM->Create<FSMReset>(mClock));
	}

}
