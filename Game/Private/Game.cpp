//
// * ENGINE-X
// * SAMPLE GAME
//
// + Game.cpp
// implementation of MyGame, an implementation of exGameInterface
//

#include "Game/Private/Game.h"
#include <string>
#include "Engine/Public/EngineInterface.h"
#include "Engine/Public/SDL.h"

#include "GameObject.h"

#include "FSMCoins.h"

//-----------------------------------------------------------------
//-----------------------------------------------------------------

const char* gWindowName = "Street Light David";

//-----------------------------------------------------------------
//-----------------------------------------------------------------

MyGame::MyGame()
	: mEngine( nullptr )
	, mFontID( -1 )
	, mUp( false )
	, mDown( false )
	, start(false)
	, stop(true)
	,reset(false)
{
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

MyGame::~MyGame()
{
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

void MyGame::Initialize( exEngineInterface* pEngine )
{
	mEngine = pEngine;

	mFontID = mEngine->LoadFont( "Old School Adventures.ttf", 20 );

	mTextPosition.x = 20.0f;
	mTextPosition.y = 200.0f;
	
	mDrinkPos.x = 80.0f;
	mDrinkPos.y = 250.0f;
	
	lightOne.setEngine(pEngine);
	mState = mFSM.Create<FSMRed>(&lightOne);
	mFSM.Initialize(mState);

	mDrink.setEngine(pEngine);
	mStateVendor = mFSMVendor.Create<FSMCoins>(&mDrink);
	mFSMVendor.Initialize(mStateVendor);

	mClock.setEngine(pEngine);
	mStateTimer = mFSMTimer.Create<FSMPause>(&mClock);
	mFSMTimer.Initialize(mStateTimer);
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

const char* MyGame::GetWindowName() const
{
	return gWindowName;
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

void MyGame::GetClearColor( exColor& color ) const
{
	color.mColor[0] = 128;
	color.mColor[1] = 128;
	color.mColor[2] = 128;
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

void MyGame::OnEvent( SDL_Event* pEvent )
{
	

}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

void MyGame::OnEventsConsumed()
{
	int nKeys = 0;
	const Uint8 *pState = SDL_GetKeyboardState(&nKeys);

	bool upOld = mUp;
	bool downOld = mDown;
	bool startOld = start;
	bool stopOld = stop;
	bool resetOld = reset;
	mUp = pState[SDL_SCANCODE_C];
	mDown = pState[SDL_SCANCODE_A];
	start = pState[SDL_SCANCODE_B];
	stop = pState[SDL_SCANCODE_S];
	reset = pState[SDL_SCANCODE_R];
	if (mUp && !upOld) {
		if (mDrink.GetDrinks() != 0) {
			mDrink.AddCoins();
		}
	}
	if (mDown && !downOld) {
		mDrink.AddDrinks(); 
	}
	if (start && !startOld) {
		mClock.SetPlay(true);
		mClock.SetPause(false);
		mClock.SetReset(false);
	}
	if (stop && !stopOld) {
		mClock.SetPlay(false);
		mClock.SetPause(true);
		mClock.SetReset(false);
	}
	if (reset && !resetOld) {
		mClock.SetPlay(false);
		mClock.SetPause(false);
		mClock.SetReset(true);
	}
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

void MyGame::Run( float fDeltaT )
{
	exColor black;
	black.mColor[0] = 255;
	black.mColor[1] = 255;
	black.mColor[2] = 255;
	black.mColor[3] = 255;

	

	exVector2 position;
	position.x = kViewportWidth / 2 - 50;
	position.y = kViewportHeight / 2 - 160;
	exColor c;
	c.mColor[0] = 0;
	c.mColor[1] = 0;
	c.mColor[2] = 0;
	c.mColor[3] = 255;
	GameObject* red = new GameObject(c, position);
	exVector2 positiony;
	positiony.x = kViewportWidth / 2 - 50;
	positiony.y = kViewportHeight / 2;
	
	GameObject* yellow = new GameObject(c, positiony);
	exVector2 positiong;
	positiong.x = kViewportWidth / 2 - 50;
	positiong.y = kViewportHeight / 2 + 160;
	
	GameObject* green = new GameObject(c, positiong);
	red->setEngine(mEngine);
	yellow->setEngine(mEngine);
	green->setEngine(mEngine);
	red->Render(0);
	yellow->Render(0);
	green->Render(0);

	mFSM.Update(fDeltaT);
	lightOne.Render(-5);

	std::string Coins = "";
	Coins = "Coins: " + std::to_string(mDrink.GetCoins());
	mEngine->DrawText(mFontID, mTextPosition, Coins.c_str(), black, -10);
	std::string Drinks = "";
	Drinks = "Drinks: " +  std::to_string(mDrink.GetDrinks());
	mEngine->DrawText(mFontID, mDrinkPos, Drinks.c_str(), black, -10);
	mFSMVendor.Update(fDeltaT);
	mDrink.Render(-5);

	mFSMTimer.Update(fDeltaT);
	if (mClock.GetPlay()) {
		mClock.addTime(fDeltaT);
	}
	mClock.Render(-5);

	position.x = kViewportWidth / 2 + 120;
	position.y = kViewportHeight / 2 - 200;
	c.mColor[0] = 255;
	c.mColor[1] = 255;
	c.mColor[2] = 255;
	c.mColor[3] = 255;
	mEngine->DrawText(mFontID, position,"B for Start", c, -10);

	position.x = kViewportWidth / 2 + 120;
	position.y = kViewportHeight / 2 - 160;
	mEngine->DrawText(mFontID, position, "S for Stop", c, -10);
	position.x = kViewportWidth / 2 + 120;
	position.y = kViewportHeight / 2 - 120;
	mEngine->DrawText(mFontID, position, "R for Reset", c, -10);
	position.x = kViewportWidth / 2 - 350;
	position.y = kViewportHeight / 2 - 140;
	mEngine->DrawText(mFontID, position,"C for Coins", c, -10);
	position.x = kViewportWidth / 2 - 350;
	position.y = kViewportHeight / 2 - 180;
	mEngine->DrawText(mFontID, position, "A for Add", c, -10);
}

