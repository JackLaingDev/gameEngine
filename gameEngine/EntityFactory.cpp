#include "EntityFactory.h"

EntityFactory::EntityFactory(EntityManager* em) : em(em)
{
}

void EntityFactory::playerEntity(int id)
{
	Entity entity(id);
	sf::RectangleShape rect;
	sf::Vector2f pos(100, 300);
	sf::Vector2f size(100, 100);
	sf::Vector2f velocity(0.04, 0.04);

	em->addComponent<TransformComponent>(entity, pos);
	em->addComponent<RectangleComponent>(entity, rect, size, sf::Color::Red);
	em->addComponent<PlayerComponent>(entity, 1);
	em->addComponent<VelocityComponent>(entity, velocity);
	em->addComponent<ColliderComponent>(entity, pos, size);
}

void EntityFactory::testEntity(int id)
{
}
