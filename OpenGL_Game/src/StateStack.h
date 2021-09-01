#pragma once
#include "states/State.h"
#include "Renderer.h"

class StateStack
{
public:
	void handleEvent();
	void update(double dt);
	void draw(Renderer& renderer);

	void pushState(std::unique_ptr<State> state);
	void popState();
	void clearStates();

	inline int  getSize() const { return m_states.size(); }

private:
	std::stack<std::unique_ptr<State>> m_states;
};

