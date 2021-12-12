#pragma once
#include <SFML/System/Clock.hpp>

class Time
{
public:
	static float deltaTime;

	void setTime(sf::Time time);

private:
	sf::Time m_clockTime;
};