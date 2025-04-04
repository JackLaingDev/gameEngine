#ifndef GameEngine_H 
#define GameEngine_H

#include <iostream> 

#include "EntityManager.h"
#include "EventManager.h"
#include "InputManager.h"
#include "RenderManager.h"
#include "MovementManager.h"
#include "EntityFactory.h"
#include "CollisionManager.h"
#include "TerrainManager.h"
#include "TerrainCollisionManager.h"
#include "PhysicsManager.h"

class GameEngine {
private:
    std::unique_ptr<sf::RenderWindow> window;


    // Systems (now initialized inside initialise())
    std::unique_ptr<EntityManager> entityManager;
    std::unique_ptr<EventManager> eventManager;
    std::unique_ptr<InputManager> inputManager;
    std::unique_ptr<RenderManager> renderManager;
    std::unique_ptr<MovementManager> movementManager;
    std::unique_ptr<CollisionManager> collisionManager;
    std::unique_ptr<EntityFactory> entityFactory;
    std::unique_ptr<TerrainManager> terrainManager;
    std::unique_ptr<TerrainCollisionManager> terrainCollisionManager;
    std::unique_ptr<PhysicsManager> physicsManager;

    bool isRunning;

public:

    // Parameterless constructor explicitly added
    GameEngine();

    // Explicit initialise function to setup all systems
    void initialise(std::unique_ptr<sf::RenderWindow> win);

    void run();
};

#endif
