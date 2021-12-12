#pragma once
#include "Vector2.h"
#include "Transform.h"

class GameObject : public Transform
{
public:
	GameObject(sf::Shape* shape, const float& size, const Vector2& velocity, const float& speed);
	GameObject(sf::Shape* shape, const float& size, const float& speed);
	GameObject(sf::Shape* shape, const float& size, const Vector2& velocity);
	GameObject(sf::Shape* shape, const float& size);
	GameObject(sf::Shape* shape);
	virtual ~GameObject();

	virtual void start() = 0;
	virtual void update() = 0;
	virtual void draw(sf::RenderWindow& window) = 0;

	// Setters
	virtual void setVelocity(const Vector2& velocity);
	virtual void setSize(const float& size);
	virtual void setSpeed(const float& speed);

	// Getters
	virtual sf::Shape* getShape() const;
	virtual Vector2 getVelocity() const;
	virtual float getSize() const;
	virtual float getSpeed() const;

	// Transfrom setters
	void setPosition(const Vector2& pos) override;
	void setRotation(const float& rotation) override;
	void setOrigin(const Vector2& origin) override;
	void setScale(const Vector2& scale) override;

	// Transform properties
	void move(const Vector2& offset) override;
	void rotate(const float& offset) override;

	// Methods
	virtual void clampPositionToScreen();

protected:
	sf::Shape* m_shape;

	float m_size;
	Vector2 m_velocity;
	float m_speed;
};