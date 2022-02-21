#pragma once
class ResourceManager
{
public:
	static bool load();

	// Getters
	static sf::Font getFont();

private:
	static sf::Font m_font;
};