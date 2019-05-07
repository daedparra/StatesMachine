#pragma once
#include "Engine/Public/EngineInterface.h"

class GameObject
{
public:
	GameObject();
	GameObject(exColor color, exVector2 position);
	~GameObject();
	void setEngine(exEngineInterface* pEngine);
	void Render(int Layer);
	void SetColor(exColor color);
	void SetPosition(exVector2 pPosition);
	exColor GetColor();
private:

	exColor		mColor;
	exVector2	mPosition;
	exEngineInterface* mEngine;
};

