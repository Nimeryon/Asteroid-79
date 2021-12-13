#include "GameHandler.h"

// Events
Event<void> GameHandler::onStart = Event<void>();
Event<void> GameHandler::onEarlyUpdate = Event<void>();
Event<void> GameHandler::onUpdate = Event<void>();
Event<void> GameHandler::onLateUpdate = Event<void>();

Event<sf::RenderWindow&> GameHandler::onDraw = Event<sf::RenderWindow&>();

GameHandler::GameHandler() = default;
GameHandler::~GameHandler() = default;

void GameHandler::update(sf::RenderWindow& window)
{
	std::cout << "Obect size: " << m_objectsToDelete.size() << std::endl;

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

void GameHandler::deleteObjects()
{
	for (auto it = m_objectsToDelete.begin(); it != m_objectsToDelete.end(); ++it)
	{
		GameObject* object = *it;
		if (object)
		{
			object->destroy();

			auto objectIt = std::find(m_objects.begin(), m_objects.end(), object);
			m_objects.erase(objectIt);

			delete object;
			object = nullptr;
		}
	}
	m_objectsToDelete.clear();
}