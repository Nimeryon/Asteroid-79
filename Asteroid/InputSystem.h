#pragma once
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>
#include <map>

#include "Vector2.h"

class InputSystem
{
public:
	InputSystem();
	~InputSystem();
	
	static void update();

	// KeyBoard Events
	static bool getKey(sf::Keyboard::Key key);
	static bool getKeyDown(sf::Keyboard::Key key);
	static bool getKeyUp(sf::Keyboard::Key key);

	// Mouse Events
	static Vector2 getMousePosition();
	static void setMousePosition(Vector2 position);
	
	static bool getMouse(sf::Mouse::Button button);
	static bool getMouseDown(sf::Mouse::Button button);
	static bool getMouseUp(sf::Mouse::Button button);

private:
	// State
	static std::map<sf::Keyboard::Key, bool> getKeyBoardState();
	static std::map<sf::Mouse::Button, bool> getMouseState();

	// KeyBoard
	static std::map<sf::Keyboard::Key, bool> m_keyboardState;
	static std::map<sf::Keyboard::Key, bool> m_oldKeyboardState;
	// Mouse
	static std::map<sf::Mouse::Button, bool> m_mouseState;
	static std::map<sf::Mouse::Button, bool> m_oldmouseState;
};