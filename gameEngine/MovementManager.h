#ifndef MovementManager_H 
#define MovementManager_H

#include <iostream>
#include <algorithm>

#include "EntityManager.h"
#include "EventManager.h"

// Class declaration
class MovementManager {
private:

	EntityManager* entityManager;

public:

	MovementManager(EntityManager* entityManager);

	void update(float deltatime);

};

#endif 
