#pragma once

#include "Entity.h"
#include "PhysicsEngine.h"

using namespace GameEngine;

class Collectable : public Entity{
private:

	std::string _itemName;
	vector3df _startPos;

public:
	//constructor
	Collectable(std::string name, vector3df startPos);
	//destructor
	~Collectable(){}

	//initialise
	void initialise();
	//Loads any content
	void loadContent();
	//Updates enemy
	void update(float deltaTime);
	//Unloads anything not handled by Irrlicht or Bullet
	void unloadContent(){}

	std::string getItemName(){
		return this->_itemName;
	}

	void Collectable::handleMessage(const Message& message);
};