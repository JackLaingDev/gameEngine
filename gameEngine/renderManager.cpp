#include "renderManager.h"

RenderManager::RenderManager(std::unique_ptr<sf::RenderWindow> window, EntityManager* entityManager) 
	: window(std::move(window)), entityManager(entityManager)
{
}

void RenderManager::render()
{
	window->clear(sf::Color::Black);

	const auto& renderEntities = entityManager->getEntitiesByComponent<RectangleComponent>();

	for (const auto& entity : renderEntities) {
		auto rect = entityManager->getComponent<RectangleComponent>(entity);
		auto transform = entityManager->getComponent<TransformComponent>(entity);

		rect->rectangle.setPosition(transform->position);

		window->draw(rect->rectangle);
	}

	window->display();
}

sf::RenderWindow* RenderManager::getWindow()
{
	return window.get();
}
