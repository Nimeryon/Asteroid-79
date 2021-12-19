#include <SFML/Graphics.hpp>

#include "Event.h"
#include "GameObject.h"
#include "CollidableObject.h"
#include "GameHandler.h"

// Events
Event<void> GameHandler::onStart = Event<void>();
Event<void> GameHandler::onEarlyUpdate = Event<void>();
Event<void> GameHandler::onUpdate = Event<void>();
Event<void> GameHandler::onLateUpdate = Event<void>();

Event<sf::RenderWindow&> GameHandler::onDraw = Event<sf::RenderWindow&>();

GameHandler::GameHandler() = default;
GameHandler::~GameHandler() = default;

void GameHandler::start()
{
	onStart();
}
void GameHandler::update(sf::RenderWindow& window)
{
	onEarlyUpdate();
	onUpdate();
	onLateUpdate();

	onDraw(window);

	deleteObjects();
}

// GameObject Handling
std::vector<GameObject*> GameHandler::m_objects = {};
std::vector<GameObject*> GameHandler::m_objectsToDelete = {};

void GameHandler::addObject(GameObject* object)
{
	m_objects.push_back(object);
}
void GameHandler::destroyObject(GameObject* object)
{
	m_objectsToDelete.push_back(object);
}
std::vector<CollidableObject*> GameHandler::getObjectsOfTag(const CollisionTag& tag)
{
	std::vector<CollidableObject*> objects = {};
	for (auto it = m_objects.begin(); it != m_objects.end(); ++it)
	{
		GameObject* object = *it;
		auto* collidableObject = dynamic_cast<CollidableObject*>(object);
		if (collidableObject)
			if (collidableObject->getTag() == tag) objects.push_back(collidableObject);
	}
	return objects;
}

void GameHandler::deleteObjects()
{
	for (auto it = m_objectsToDelete.begin(); it != m_objectsToDelete.end(); ++it)
	{
		GameObject* object = *it;
		if (object)
		{
			auto objectIt = std::find(m_objects.begin(), m_objects.end(), object);
			m_objects.erase(objectIt);

			delete object;
			object = nullptr;
		}
	}
	m_objectsToDelete.clear();
}