#pragma once

#include "DecisionTreeNode.h"
#include "Enemy.h"

class SeekItemDecision : public DecisionTreeNode<Enemy>
{
public:
	void makeDecision(Enemy* owner) { owner->getStateMachine().setState("SeekItem"); }
};