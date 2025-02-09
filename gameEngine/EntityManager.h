#ifndef EntityManager_H 
#define EntityManager_H

#include <unordered_map>
#include <typeindex>
#include <memory>
#include <iostream> 

#include "Component.h"
#include "Entity.h"

// Class declaration
class EntityManager {
private:
    std::unordered_map<int, std::unordered_map < std::type_index, std::unique_ptr<Component>>> entities;

public:

    template <typename T, typename... Args>
    void addComponent(Entity entity, Args... args) {
		int entityID = entity.id;

		// Accesses the std::unordered_map for a given entity and creates and stores a unique pointer to its component
		entities[entityID][std::type_index(typeid(T))] = std::make_unique<T>(std::forward<Args>(args)...);
    }
    
    template <typename T>
    T* getComponent(Entity entity) {
		int entityID = entity.id;

		// Check entity exists
		if (entities.find(entityID) != entities.end()) {

			auto& componentMap = entities[entityID];
			std::type_index type_index = typeid(T);

			// Check component of type T exists in Entity
			auto it = componentMap.find(type_index);
			if (it != componentMap.end()) {

				return static_cast<T*>(it->second.get()); // Converts to derived class ptr instead of base class ptr
			}

		}
		return nullptr;
    }

    template <typename T>
    std::vector<Entity> getEntitiesByComponent() {
        std::vector<Entity> entitiesFound;

        for (const auto& entity : entities) {
            int entityID = entity.first; // Get the entity ID
            const auto& componentMap = entity.second; // Get the component map for this entity

            // Check if the component of type T exists in the entity's component map
            auto it = componentMap.find(std::type_index(typeid(T)));
            if (it != componentMap.end()) {
                entitiesFound.emplace_back(entityID); // Add the entity to the result
            }
        }

        return entitiesFound;
    }

};

#endif 
