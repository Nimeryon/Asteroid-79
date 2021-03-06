#pragma once
#include "GameObject.h"

namespace sf { class Shape; }
class GameObject;

class CosmeticObject : public GameObject
{
public:
	CosmeticObject(sf::Shape* shape, const float& size);
	CosmeticObject(sf::Shape* shape);
	~CosmeticObject() override;
};