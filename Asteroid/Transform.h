#pragma once
#include "Vector2.h"

struct Transform
{
public:
	// Setters
	virtual void setPosition(const Vector2& pos) = 0;
	virtual void setOrigin(const Vector2& origin) = 0;
	virtual void setScale(const Vector2& scale) = 0;
	virtual void setRotation(const float& rotation) = 0;
	
	// Transform properties
	virtual void move(const Vector2& offset) = 0;
	virtual void rotate(const float& offset) = 0;
}; 