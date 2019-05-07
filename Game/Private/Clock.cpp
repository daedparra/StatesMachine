#include "Clock.h"

Clock::Clock() {
	exColor red;
	red.mColor[0] = 255;
	red.mColor[1] = 0;
	red.mColor[2] = 0;
	red.mColor[3] = 255;
	exVector2 position;
	position.x = kViewportWidth / 2 + 100;
	position.y = kViewportHeight / 2;
	mColor = red;	
	mPosition = position;
	timer = 0.0;
}
Clock::Clock(exColor color, exVector2 p1)
{
	mColor = color;
	mPosition = p1;

}


Clock::~Clock()
{
}

void Clock::setEngine(exEngineInterface * pEngine)
{
	mEngine = pEngine;
}

void Clock::Render(int Layer)
{
	std::string Timer = "";
	Timer = "Time: " + std::to_string(timer);
	mFontID = mEngine->LoadFont("Old School Adventures.ttf", 20);
	mEngine->DrawText(mFontID, mPosition, Timer.c_str(), mColor, Layer);
}

void Clock::SetTime()
{
	timer = 0.0f;
}

void Clock::SetColor(exColor color)
{
	mColor = color;
}

void Clock::addTime(float time)
{
	timer += time;
}

void Clock::SetPlay(bool action)
{
	play = action;
}

bool Clock::GetPlay()
{
	return play;
}

void Clock::SetPause(bool action)
{
	pause = action;
}

bool Clock::GetPause()
{
	return pause;
}

void Clock::SetReset(bool action)
{
	reset = action;
}

bool Clock::GetReset()
{
	return reset;
}

