#include "FSMCoins.h"
#include "FSMSelectorDrink.h"
#include "FSM.h"

FSMSelectorDrink::FSMSelectorDrink(FSM * pFSM, Drink* pDrink) : FSMMachine(pFSM, pDrink)
{
}

void FSMSelectorDrink::OnEnter()
{
	//render
	exColor c;
	c.mColor[0] = 255;
	c.mColor[1] = 255;
	c.mColor[2] = 255;
	c.mColor[3] = 255;
	mDrink->SetColor(c);
}

void FSMSelectorDrink::Update(float fDeltaT)
{
	//wait five seconds and change to green
	
	waitTime -= fDeltaT;
	if (waitTime < 0) {
		if (mDrink->GetDrinks() > 0) {
			mDrink->MinusDrinks();
		}
		mFSM->Next(mFSM->Create<FSMCoins>(mDrink));
	}
}
