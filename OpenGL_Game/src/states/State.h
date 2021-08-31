#pragma once
#include "../SharedContext.h"
#include "../Renderer.h"

//#include <memory>

class StateStack;

class State
{
public:
	State(StateStack& stateStack, SharedContext context);
	virtual ~State() = default;

	virtual void handleEvent()			 = 0;
	virtual void update(double dt)		 = 0;
	virtual void draw(Renderer& rendere) = 0;

protected:
	void requestStackPush(std::unique_ptr<State> state);
	void requestStackPop();
	void requestStackClear();

protected:
	StateStack&   m_stateStack; 
	SharedContext m_context;
};

