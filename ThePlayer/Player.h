#pragma once

#include "Entity.h"
#include "Object.h"
#include <unordered_map>

using namespace GameEngine;

class Player : public Entity{
private:
	float _yaw;
	float _pitch;
	float _mod;
	bool _isCarrying;
	bool _stealthActive;
	bool _isDown;
	Object* _carriedItem;
	std::unordered_map<std::string, bool> _collectedItems;
	btRigidBody* _rigidBody;
	vector3df _up;
	vector3df _forward;
	std::string _currentRoom;
	float _noiseMade;


public:
	Player() : Entity(-1, 0, "Player"){
		_isCarrying = false;
	}

	btRigidBody* getRigidBody(){ return _rigidBody; }

	float getYaw() const { return _yaw; }
	void setYaw(float value) { _yaw = value; }

	float getPitch() const { return _pitch; }
	void setPitch(float value) { _pitch = value; }

	bool isStealthActive() { return _stealthActive; }
	void setStealth(bool value) { _stealthActive = value; }

	bool isDown() { return _isDown; }
	void setDown(bool value) { _isDown = value; }

	vector3df getUp() { return _up; }
	void setUp(vector3df value) { _up = value; }

	vector3df getForward() { return _forward; }
	void setForward(vector3df value) { _forward = value; }

	std::string getCurrentRoom() { return _currentRoom; }
	void setCurrentRoom(std::string value) { _currentRoom = value; }

	Object* getCarriedItem(){ return _carriedItem; }
	void setCarriedItem(Object* val){ _carriedItem = val; }
	void clearCarriedItem(){ _carriedItem = 0; }

	void addItem(std::string val){ _collectedItems[val] = true; }
	std::unordered_map<std::string, bool> getCollectedItems(){ return _collectedItems; }

	void addToNoise(float val){ _noiseMade += val; }
	float getNoiseMade(){ return _noiseMade; }


	

	void initialise();
	void loadContent();
	void update(float deltaTime);
	void rotate(float deltaYaw, float deltaPitch);
	void unloadContent(){}
	void Player::handleMessage(const Message& message);

};