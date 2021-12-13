#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

#include "Event.h"
#include "GameObject.h"

class GameHandler
{
public:
	GameHandler();
	~GameHandler();

	void update(sf::RenderWindow& window);

	// GameObject Handling
	static void addObject(GameObject* object);
	static void destroyObject(GameObject* object);

	// Events
	static Event<void> onStart;
	static Event<void> onEarlyUpdate;
	static Event<void> onUpdate;
	static Event<void> onLateUpdate;

	static Event<sf::RenderWindow&> onDraw;

private:
	static std::vector<GameObject*> m_objects;
	static std::vector<GameObject*> m_objectsToDelete;

	static void deleteObjects();
};