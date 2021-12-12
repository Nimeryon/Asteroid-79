#pragma once
#include "GameObject.h"

class CollidableObject : public GameObject
{
public:
	CollidableObject(sf::Shape* shape, const float& size, const Vector2& velocity, const float& speed);
	CollidableObject(sf::Shape* shape, const float& size);
	CollidableObject(sf::Shape* shape);
	~CollidableObject() override;

	static bool isColliding(const CollidableObject& obj1, const CollidableObject& obj2);
	bool isColliding(const CollidableObject& obj) const;

	void draw(sf::RenderWindow& window) override;

	// Transfrom setters
	void setPosition(const Vector2& pos) override;
	void setRotation(const float& rotation) override;
	void setOrigin(const Vector2& origin) override;
	void setScale(const Vector2& scale) override;

	// Transform properties
	void move(const Vector2& offset) override;
	void rotate(const float& offset) override;

private:
	sf::CircleShape* m_collision;
};