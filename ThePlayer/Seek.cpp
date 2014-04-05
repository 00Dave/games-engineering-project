#include "Seek.h"
#include <cmath>

using namespace irr::core;

namespace GameEngine {
	SteeringOutput Seek::getSteering()
	{
		// Create output
		SteeringOutput steering;

		// Calculate direction. This is the vector from the character to the target
		vector3df characterPos = _character->getNode()->getPosition();
		vector3df targetPos = _target->getNode()->getPosition();
		vector3df direction = targetPos - characterPos;
		direction.Y = 0.0f;

		// We want to travel in this direciton at max speed
		// Normalise the direction vector (make 1 unit long) and multiply by max speed
		direction = direction.normalize();
		direction *= _maxSpeed;
	

		// Use this in the steering output. Rotation is 0
		steering.direction = direction;
		steering.rotation = 0.0f;

		// Return steering direction
		return steering;
	}
}