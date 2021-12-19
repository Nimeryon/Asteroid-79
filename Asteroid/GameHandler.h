#pragma once
#include <vector>

namespace sf { class RenderWindow; }
template<typename T>
class Event;
class GameObject;
class CollidableObject;
enum CollisionTag;

class GameHandler
{
public:
	GameHandler();
	~GameHandler();

	void start();
	void update(sf::RenderWindow& window);

	// GameObject Handling
	static void addObject(GameObject* object);
	static void destroyObject(GameObject* object);
	static std::vector<CollidableObject*> getObjectsOfTag(const CollisionTag& tag);

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