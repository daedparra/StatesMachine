#pragma once
#include "FSMState.h"

class GameObject;
class Drink;

class FSM
{
public:
	FSM();
	~FSM();

	void Initialize(FSMState* pState);
	void Next(FSMState* pState);
	void Update(float fDeltaT);
	FSMState* Current() { return mCurrent; }
	const FSMState* Current() const { return mCurrent; }
	
	template<class T, typename... params>
	T* Create(params... xs)
	{
		return new T(this, xs...);
	}

private:

	FSMState* mCurrent;
	FSMState* mNext;
};

