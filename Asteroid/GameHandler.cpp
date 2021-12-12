#include "GameHandler.h"

Event<void> GameHandler::onStart = Event<void>();
Event<void> GameHandler::onEarlyUpdate = Event<void>();
Event<void> GameHandler::onUpdate = Event<void>();
Event<void> GameHandler::onLateUpdate = Event<void>();

Event<sf::RenderWindow&> GameHandler::onDraw = Event<sf::RenderWindow&>();

GameHandler::GameHandler() = default;
GameHandler::~GameHandler() = default;

void GameHandler::update(sf::RenderWindow& window)
{
	onEarlyUpdate();
	onUpdate();
	onLateUpdate();

	onDraw(window);
}
