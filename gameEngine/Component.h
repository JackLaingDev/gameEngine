#ifndef Component_H 
#define Component_H

#include <iostream>
#include <vector>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

// Class declaration
class Component {
private:


public:
	virtual ~Component() noexcept = default;

};

// Public inheritance to allow usage of ~Component
// Health Component to store entity health
class HealthComponent : public Component {
private:

public:
	int health;

	HealthComponent(int health);
};

//
class VelocityComponent : public Component {
private: 

public:
	sf::Vector2f velocity; // x and y velocities

	VelocityComponent(sf::Vector2f velocity);

};

//
class TransformComponent : public Component {
public:
	sf::Vector2f position;
	float rotation; // In degrees (SFML uses degrees)
	sf::Vector2f scale;

	TransformComponent(sf::Vector2f position);
};

//
class ColliderComponent : public Component {
private:

public:
	sf::Vector2f position;
	sf::Vector2f size;

	ColliderComponent(sf::Vector2f position, sf::Vector2f size);

};

//
class TerrainColliderComponent : public Component {
private:

public:
	
	sf::Vector2f position;
	sf::Vector2f size;

	TerrainColliderComponent(sf::Vector2f position, sf::Vector2f size);

};

//
class PlayerComponent : public Component {

private:

public:

	int playerId;
	
	PlayerComponent(int playerId);

};

// USED FOR TEST GAME
class RectangleComponent : public Component {
private:


public:

	sf::RectangleShape rectangle;
	sf::Vector2f size;
	sf::Color colour;

	RectangleComponent(sf::RectangleShape rectangle, sf::Vector2f size, sf::Color colour);

};



#endif 
