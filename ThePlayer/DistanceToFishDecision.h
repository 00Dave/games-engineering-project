#pragma once

#include "Decision.h"
#include "Enemy.h"

using namespace GameEngine;

class DistanceToFishDecision : public Decision<Enemy>
{
private:
	float _distance;
protected:
	DecisionTreeNode<Enemy>* getBranch(Enemy* owner);
public:
	DistanceToFishDecision(float distance, DecisionTreeNode<Enemy>* trueNode, DecisionTreeNode<Enemy>* falseNode)
		: _distance(distance), Decision(trueNode, falseNode) { }
};