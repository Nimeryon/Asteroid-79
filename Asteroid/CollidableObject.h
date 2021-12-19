#pragma once
#include "GameObject.h"

namespace sf
{
	class Shape;
	class RenderWindow;
	class CircleShape;
}
struct Vector2;
enum CollisionTag;

class CollidableObject : public GameObject
{
public:
	CollidableObject(sf::Shape* shape, const CollisionTag& tag, const float& size, const float& collision, const Vector2& velocity, const float& speed);
	CollidableObject(sf::Shape* shape, const float& size, const float& collision, const Vector2& velocity, const float& speed);
	CollidableObject(sf::Shape* shape, const CollisionTag& tag, const float& size, const Vector2& velocity, const float& speed);
	CollidableObject(sf::Shape* shape, const float& size, const Vector2& velocity, const float& speed);
	CollidableObject(sf::Shape* shape, const CollisionTag& tag, const float& size);
	CollidableObject(sf::Shape* shape, const float& size);
	CollidableObject(sf::Shape* shape, const CollisionTag& tag);
	CollidableObject(sf::Shape* shape);
	~CollidableObject() override;

	static bool isColliding(const CollidableObject& obj1, const CollidableObject& obj2);
	bool isColliding(const CollidableObject& obj) const;

	void draw(sf::RenderWindow& window) override;

	// Getters
	float getCollisionRadius();
	CollisionTag getTag();

	// Setters
	void setCollisionRadius(const float& collision);
	void setTag(const CollisionTag& tag);

	// Transfrom setters
	void setPosition(const Vector2& pos) override;
	void setRotation(const float& rotation) override;

	// Transform properties
	void move(const Vector2& offset) override;
	void rotate(const float& offset) override;

private:
	CollisionTag m_collision_tag;
	float m_collisionRadius;
	sf::CircleShape* m_collision;
};