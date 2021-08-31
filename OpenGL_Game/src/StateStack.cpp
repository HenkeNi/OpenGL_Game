#include "pch.h"
#include "StateStack.h"


void StateStack::handleEvent()
{
	if (!m_states.empty())
		m_states.top()->handleEvent();
}


void StateStack::update(double dt)
{
	if (!m_states.empty())
		m_states.top()->update(dt);
}


void StateStack::draw(Renderer& renderer)
{
	if (!m_states.empty())
		m_states.top()->draw(renderer);
}


void StateStack::pushState(std::unique_ptr<State> state)
{
	m_states.push(std::move(state));
}


void StateStack::popState()
{
	m_states.pop();
}


void StateStack::clearStates()
{
	while (!m_states.empty())
		m_states.pop();
}
