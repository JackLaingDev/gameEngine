#include "InputManager.h"

InputManager::InputManager(sf::Window* win, EventManager* eventManager, EntityManager* entityManager) 
    : win(win), eventManager(eventManager), entityManager(entityManager)
{

}

void InputManager::update() {

    // Process events
    auto entities = entityManager->getEntitiesByComponent<PlayerComponent>();

    if (entities.size() != 0) {
        player = entities[0];
        playerVelocity = entityManager->getComponent<VelocityComponent>(player);
    }

    while (const std::optional eventSF = win->pollEvent()) {
        processKeyEvents(eventSF);
    }

    processHeldKeys(playerVelocity);
}

void InputManager::processKeyEvents(const std::optional<sf::Event> eventSF)
{
    if (eventSF->is<sf::Event::KeyPressed>()) {
        const auto* keyPressed = eventSF->getIf<sf::Event::KeyPressed>();
        auto key = keyPressed->scancode;

        heldKeys.insert(key);
    }
    if (eventSF->is<sf::Event::KeyReleased>()) {
        const auto* keyReleased = eventSF->getIf<sf::Event::KeyReleased>();
        auto key = keyReleased->scancode;

        heldKeys.erase(key);
    }
}

void InputManager::processHeldKeys(VelocityComponent* playerVelocity)
{

    sf::Vector2f newVelocity(0.f, 0.f);

    // Vertical Movement
    if (heldKeys.find(sf::Keyboard::Scancode::W) != heldKeys.end()) {
        newVelocity.y -= speed;
    }
    if (heldKeys.find(sf::Keyboard::Scancode::S) != heldKeys.end()) {
        newVelocity.y += speed;
    }

    // Horizontal Movement
    if (heldKeys.find(sf::Keyboard::Scancode::A) != heldKeys.end()) {
        newVelocity.x -= speed;
    }
    if (heldKeys.find(sf::Keyboard::Scancode::D) != heldKeys.end()) {
        newVelocity.x += speed;
    }

    playerVelocity->velocity = newVelocity;

    // Escape handling
    if (heldKeys.find(sf::Keyboard::Scancode::Escape) != heldKeys.end()) {
        win->close();
    }

}

