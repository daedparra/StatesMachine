#include "FSMMachine.h"

FSMMachine::FSMMachine(FSM* pFSM, Drink* pDrink)
	: FSMState(pFSM), mDrink(pDrink)
{
}


FSMMachine::~FSMMachine()
{
}