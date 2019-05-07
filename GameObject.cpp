#include "GameObject.h"
GameObject::GameObject() {
	exColor red;
	red.mColor[0] = 255;
	red.mColor[1] = 0;
	red.mColor[2] = 0;
	red.mColor[3] = 255;
	exVector2 position;
	position.x = kViewportWidth / 2 - 50;
	position.y = kViewportHeight / 2 - 160;
	mColor = red;
	mPosition = position;
}
GameObject::GameObject(exColor color, exVector2 position)
{
	mColor = color;
	mPosition = position;
}


GameObject::~GameObject()
{
}

void GameObject::setEngine(exEngineInterface * pEngine)
{
	mEngine = pEngine;
}

void GameObject::Render(int Layer)
{
	mEngine->DrawCircle(mPosition, 70, mColor, Layer);
}

void GameObject::SetColor(exColor color)
{
	mColor = color;
}

void GameObject::SetPosition(exVector2 pPosition)
{
	mPosition = pPosition;
}

exColor GameObject::GetColor()
{
	return mColor;
}
