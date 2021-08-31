#include "pch.h"
#include "State.h"
#include "../StateStack.h"


State::State(StateStack& stateStack, SharedContext context)
	: m_stateStack{ stateStack }, m_context{ context }
{
}

void State::requestStackPush(std::unique_ptr<State> state)
{
	m_stateStack.pushState(std::move(state));
}

void State::requestStackPop()
{
	m_stateStack.popState();
}

void State::requestStackClear()
{
	m_stateStack.clearStates();
}