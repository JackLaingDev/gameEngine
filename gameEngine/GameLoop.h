#ifndef GameLoop_H 
#define GameLoop_H

#include <iostream> 

#include "EntityManager.h"
#include "EventManager.h"
#include "InputManager.h"

class GameLoop {
private:

	// Systems
	std::unique_ptr<EntityManager> entityManager;
	std::unique_ptr<EventManager> eventManager;
	std::unique_ptr<InputManager> inputManager;
	std::unique_ptr<sf::RenderWindow> window;

	bool isRunning;

public:

	GameLoop(std::unique_ptr<EntityManager> entityManager, std::unique_ptr<EventManager> eventManager,
		std::unique_ptr<InputManager> inputManager, std::unique_ptr<sf::RenderWindow> window);

	void run();

};


#endif 
