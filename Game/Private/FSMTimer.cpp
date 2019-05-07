#include "FSMTimer.h"


FSMTimer::FSMTimer(FSM* pFSM, Clock* pClock)
	: FSMState(pFSM), mClock(pClock)
{
}


FSMTimer::~FSMTimer()
{
}