#include "MovementManager.h"

MovementManager::MovementManager(EntityManager* entityManager) : entityManager(entityManager)
{
}


// Collider componenet should derive its position from the transofmr componenet within the collision system not here
void MovementManager::update(float deltatime)
{
	auto entities = entityManager->getEntitiesByComponent<VelocityComponent>();

	for (auto entity : entities) {
		auto velocityComponent = entityManager->getComponent<VelocityComponent>(entity);
		auto transformComponent = entityManager->getComponent<TransformComponent>(entity);

		// Clamp x velocity
		velocityComponent->velocity.x = std::clamp(
			velocityComponent->velocity.x,
			velocityComponent->minVelocity.x,
			velocityComponent->maxVelocity.x
		);

		// Clamp y velocity
		velocityComponent->velocity.y = std::clamp(
			velocityComponent->velocity.y,
			velocityComponent->minVelocity.y,
			velocityComponent->maxVelocity.y
		);

		transformComponent->position.x += deltatime * velocityComponent->velocity.x;
		transformComponent->position.y += deltatime * velocityComponent->velocity.y;
	}
	
}
