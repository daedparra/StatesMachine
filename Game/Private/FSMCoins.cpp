#include "FSMCoins.h"
#include "FSMSelectorDrink.h"
#include "FSM.h"

FSMCoins::FSMCoins(FSM * pFSM, Drink* pDrink) : FSMMachine(pFSM, pDrink)
{
}

void FSMCoins::OnEnter()
{
	//render
	if (mDrink->GetDrinks() != 0) {
		exColor c;
		c.mColor[0] = 0;
		c.mColor[1] = 255;
		c.mColor[2] = 0;
		c.mColor[3] = 255;
		mDrink->SetColor(c);
	}
	else {
		exColor c;
		c.mColor[0] = 255;
		c.mColor[1] = 0;
		c.mColor[2] = 0;
		c.mColor[3] = 255;
		mDrink->SetColor(c);
	}

	
}

void FSMCoins::Update(float fDeltaT)
{
	//wait five seconds and change to green
	if (mDrink->GetCoins() >= 2 && mDrink->GetDrinks() != 0) {
		waitTime -= fDeltaT;
		if (waitTime < 0) {
			mDrink->SetCoins();
			mFSM->Next(mFSM->Create<FSMSelectorDrink>(mDrink));
		}
	}
}
