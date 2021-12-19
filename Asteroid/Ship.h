#pragma once
namespace sf { class RenderWindow; }
struct Vector2;

#include "CollidableObject.h"

class Ship : public CollidableObject
{
public:
	Ship();
	~Ship() override;

	void start() override;
	void update() override;
	void draw(sf::RenderWindow& window) override;
	void destroy() override;

	void handleRotation();
	void handleMovement();
	void handleShoot();

private:
	// Rotation values
	float m_rotationDragFactor = .999f;
	float m_rotationSpeed = 0.f;
	float m_rotationAcceleration = 420.f;
	float m_maxRotationSpeed = 150.f;
	// Movement values
	float m_movementDragFactor = .9998f;
	float m_movementAcceleration = 250.f;
	float m_movementMaxSpeed = 220.f;
};