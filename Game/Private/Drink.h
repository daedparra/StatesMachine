#pragma once
#include "Engine/Public/EngineInterface.h"
class Drink
{
public:
	Drink();
	Drink(exColor color, exVector2 p1, exVector2 p2);
	~Drink();
	void setEngine(exEngineInterface* pEngine);
	void Render(int Layer);
	void SetColor(exColor color);
	void SetPosition(exVector2 p1, exVector2 p2);
	void AddCoins();
	int GetCoins();
	void SetCoins();
	void AddDrinks();
	int GetDrinks();
	void MinusDrinks();
	exColor GetColor();
private:
	int coins=0;
	int drinks = 1;
	exColor		mColor;
	exVector2	mP1;
	exVector2   mP2;
	exEngineInterface* mEngine;
};

