#include "Event.h"
#include "Vector2.h"
#include "GameHandler.h"
#include "InputSystem.h"

// KeyBoard
std::map<sf::Keyboard::Key, bool> InputSystem::m_keyboardState = getKeyBoardState();
std::map<sf::Keyboard::Key, bool> InputSystem::m_oldKeyboardState = m_keyboardState;
// Mouse
std::map<sf::Mouse::Button, bool> InputSystem::m_mouseState = getMouseState();
std::map<sf::Mouse::Button, bool> InputSystem::m_oldmouseState = m_mouseState;

InputSystem::InputSystem()
{
	GameHandler::onEarlyUpdate += EventHandler::bind(update);
}
InputSystem::~InputSystem()
{
	GameHandler::onEarlyUpdate -= EventHandler::bind(update);
}

void InputSystem::update()
{
	// Keyboard
	m_oldKeyboardState = m_keyboardState;
	m_keyboardState = getKeyBoardState();

	// Mouse
	m_oldmouseState = m_mouseState;
	m_mouseState = getMouseState();
}

// State
std::map<sf::Keyboard::Key, bool> InputSystem::getKeyBoardState()
{
	std::map<sf::Keyboard::Key, bool> keyMap = {};

	for (int keyInt = sf::Keyboard::Key::A; keyInt != sf::Keyboard::Key::Pause; ++keyInt)
	{
		auto key = static_cast<sf::Keyboard::Key>(keyInt);
		keyMap[key] = sf::Keyboard::isKeyPressed(key);
	}

	return keyMap;
}
std::map<sf::Mouse::Button, bool> InputSystem::getMouseState()
{
	std::map<sf::Mouse::Button, bool> mouseMap = {};

	for (int buttonInt = sf::Mouse::Button::Left; buttonInt != sf::Mouse::Button::XButton2; ++buttonInt)
	{
		auto button = static_cast<sf::Mouse::Button>(buttonInt);
		mouseMap[button] = sf::Mouse::isButtonPressed(button);
	}

	return mouseMap;
}

// KeyBoard Events
bool InputSystem::getKey(sf::Keyboard::Key key) { return m_keyboardState[key]; }
bool InputSystem::getKeyDown(sf::Keyboard::Key key) { return m_keyboardState[key] && !m_oldKeyboardState[key]; }
bool InputSystem::getKeyUp(sf::Keyboard::Key key) { return !m_keyboardState[key] && m_oldKeyboardState[key]; }

// Mouse Events
Vector2 InputSystem::getMousePosition()
{
	sf::Vector2i pos = sf::Mouse::getPosition();
	return Vector2(pos.x, pos.y);
}
void InputSystem::setMousePosition(Vector2 position) { sf::Mouse::setPosition(position); }

bool InputSystem::getMouse(sf::Mouse::Button button) { return m_mouseState[button]; }
bool InputSystem::getMouseDown(sf::Mouse::Button button) { return m_mouseState[button] && !m_oldmouseState[button]; }
bool InputSystem::getMouseUp(sf::Mouse::Button button) { return !m_mouseState[button] && m_oldmouseState[button]; }