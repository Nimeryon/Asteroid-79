#include "Time.h"

float Time::deltaTime = 0.f;

void Time::setTime(sf::Time time)
{
	m_clockTime = time;
	deltaTime = m_clockTime.asSeconds();
}
