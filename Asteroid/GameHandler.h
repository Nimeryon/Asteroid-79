#pragma once
#include <SFML/Graphics.hpp>

#include "Event.h"

class GameHandler
{
public:
	GameHandler();
	~GameHandler();

	void update(sf::RenderWindow& window);

	static Event<void> onStart;
	static Event<void> onEarlyUpdate;
	static Event<void> onUpdate;
	static Event<void> onLateUpdate;

	static Event<sf::RenderWindow&> onDraw;
};