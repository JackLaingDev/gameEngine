#ifndef GameLoop_H 
#define GameLoop_H

#include <iostream> 

#include "EntityManager.h"
#include "EventManager.h"
#include "InputManager.h"
#include "RenderManager.h"
#include "MovementManager.h"

class GameLoop {
private:

	// Systems
	std::unique_ptr<EntityManager> entityManager;
	std::unique_ptr<EventManager> eventManager;
	std::unique_ptr<InputManager> inputManager;
	std::unique_ptr<RenderManager> renderManager;
	std::unique_ptr<MovementManager> movementManager;

	bool isRunning;

public:

	GameLoop(std::unique_ptr<EntityManager> entityManager, std::unique_ptr<EventManager> eventManager,
		std::unique_ptr<InputManager> inputManager, std::unique_ptr<RenderManager> renderManager,
		std::unique_ptr<MovementManager> movementManager);

	void run();

};


#endif 
