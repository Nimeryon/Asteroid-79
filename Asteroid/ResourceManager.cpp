#include <SFML/Graphics.hpp>

#include "ResourceManager.h"

sf::Font ResourceManager::m_font = sf::Font();

bool ResourceManager::load()
{
	return m_font.loadFromFile("./Fonts/Minecraft.ttf");
}

sf::Font ResourceManager::getFont() { return m_font; }