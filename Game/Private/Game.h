//
// * ENGINE-X
// * SAMPLE GAME
//
// + Game.h
// definition of MyGame, an implementation of exGameInterface
//

#include "Game/Public/GameInterface.h"
#include "Engine/Public/EngineTypes.h"
#include "FSM.h"
#include "FSMState.h"

#include "FSMLight.h"
#include "FSMRed.h"
#include "FSMGreen.h"
#include "FSMYellow.h"

#include "FSMMachine.h"
#include "FSMCoins.h"
#include "FSMSelectorDrink.h"

#include "FSMTimer.h"
#include "FSMStart.h"
#include "FSMPause.h"
#include "FSMReset.h"
//-----------------------------------------------------------------
//-----------------------------------------------------------------

class MyGame : public exGameInterface
{
public:

								MyGame();
	virtual						~MyGame();

	virtual void				Initialize( exEngineInterface* pEngine );

	virtual const char*			GetWindowName() const;
	virtual void				GetClearColor( exColor& color ) const;

	virtual void				OnEvent( SDL_Event* pEvent );
	virtual void				OnEventsConsumed();

	virtual void				Run( float fDeltaT );

private:

	exEngineInterface*			mEngine;

	int							mFontID;

	bool						mUp;
	bool						mDown;
	bool						start, stop, reset;
	GameObject					lightOne;
	exVector2					mTextPosition;
	exVector2					mDrinkPos;
	FSM							mFSM;
	FSMState*					mState;
	Drink						mDrink;
	FSM							mFSMVendor;
	FSMState*					mStateVendor;
	Clock						mClock;
	FSM							mFSMTimer;
	FSMState*					mStateTimer;
};
