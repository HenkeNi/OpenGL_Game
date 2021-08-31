#pragma once
#include "../GameObject.h"
#include "State.h"

//#include <vector>

class GameState : public State
{
public:
	GameState(StateStack& stateStack, SharedContext context);

	virtual void handleEvent()			  override;
	virtual void update(double dt)		  override;
	virtual void draw(Renderer& renderer) override;

private:
	void initGameObjects();
	

private:
	std::vector<GameObject> m_gameObjects; // Use unordered_map instead??


	unsigned int m_VAO;
};

