#ifndef Component_H 
#define Component_H

#include <iostream> 

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
	float velocity;

	VelocityComponent(float velocity);

};

//
class MoveComponent : public Component {
private:

public:
	int x, y;

	MoveComponent(int x, int y);

};

//
class PositionComponent : public Component {
private:

public:
	float x, y;

	PositionComponent(float x, float y);

};

//
class ColliderComponent : public Component {
private:

public:
	float x, y;
	float width, height;

	ColliderComponent(float x, float y, int width, int height);

};

//
class TerrainColliderComponent : public Component {
private:

public:
	struct Region {
		float x, y;
		float width, height;

		Region(float x, float y, float width, float height) : x(x), y(y), width(width), height(height) {};
		~Region() {}
	};

	std::vector<Region> regions;

	~TerrainColliderComponent() noexcept override {}

	void addRegion(float x, float y, float width, float height);

};

//
class PlayerComponent : public Component {
private:

public:
	int playerId;

	PlayerComponent(int PlayerId);

};

//
class EnemyComponent : public Component {
private:

public:
	int enemyId;

	EnemyComponent(int enemyId);

};



#endif 
