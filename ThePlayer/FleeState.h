#pragma once

#include "State.h"
#include "Enemy.h"
#include "Flee.h"

using namespace GameEngine;

class FleeState : public State<Enemy>
{
private:
	Flee _flee;
public:
	FleeState(Enemy* owner, Entity* player, float maxSpeed)
		: _flee(owner, player, maxSpeed) { }
	~FleeState() { }
	void execute(Enemy* owner, float frameTime);
};