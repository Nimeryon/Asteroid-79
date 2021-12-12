#include "CosmeticObject.h"

CosmeticObject::CosmeticObject(sf::Shape* shape, const float& size) : GameObject(shape, size) {}
CosmeticObject::CosmeticObject(sf::Shape* shape) : CosmeticObject(shape, 1.f) {}