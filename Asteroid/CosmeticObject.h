#pragma once
#include "GameObject.h"

class CosmeticObject : public GameObject
{
public:
	CosmeticObject(sf::Shape* shape, const float& size);
	CosmeticObject(sf::Shape* shape);
};