#include "Drink.h"

Drink::Drink() {
	exColor red;
	red.mColor[0] = 0;
	red.mColor[1] = 255;
	red.mColor[2] = 0;
	red.mColor[3] = 255;
	exVector2 position;
	position.x = kViewportWidth / 2 - 300;
	position.y = kViewportHeight / 2;
	exVector2 position2;
	position2.x = kViewportWidth / 2 - 200;
	position2.y = kViewportHeight / 2 + 50;
	mColor = red;
	mP1 = position;
	mP2 = position2;
}
Drink::Drink(exColor color, exVector2 p1, exVector2 p2)
{
	mColor = color;
	mP1 = p1;
	mP2 = p2;
}


Drink::~Drink()
{
}

void Drink::AddCoins()
{
	coins += 1;
}

void Drink::SetCoins()
{
	coins -= 2;
}

int Drink::GetCoins()
{
	return coins;
}

void Drink::AddDrinks()
{
	drinks += 1;
}

void Drink::MinusDrinks()
{
	drinks -= 1;
}

int Drink::GetDrinks()
{
	return drinks;
}
void Drink::setEngine(exEngineInterface * pEngine)
{
	mEngine = pEngine;
}

void Drink::Render(int Layer)
{
	mEngine->DrawBox(mP1,mP2,mColor,Layer);
}

void Drink::SetColor(exColor color)
{
	mColor = color;
}

void Drink::SetPosition(exVector2 p1, exVector2 p2)
{
	mP1 = p1;
	mP2 = p2;
}

exColor Drink::GetColor()
{
	return mColor;
}
