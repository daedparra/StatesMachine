#pragma once
#include "Engine/Public/EngineInterface.h"
#include <string>
class Clock
{
public:
	Clock();
	Clock(exColor color, exVector2 p1);
	~Clock();
	void setEngine(exEngineInterface* pEngine);
	void Render(int Layer);
	void SetTime();
	void SetColor(exColor color);
	void addTime(float time);
	void SetPlay(bool action);
	bool GetPlay();
	void SetPause(bool action);
	bool GetPause();
	void SetReset(bool action);
	bool GetReset();
private:
	float timer;
	exColor		mColor;
	exVector2	mPosition;
	exEngineInterface* mEngine;
	int	mFontID;
	bool play = false, pause = false, reset = false;

};

