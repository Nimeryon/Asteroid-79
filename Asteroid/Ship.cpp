#include "InputSystem.h"
#include "Time.h"
#include "Math.h"
#include "Bullet.h"
#include "Ship.h"

extern int SCREEN_WIDTH;
extern int SCREEN_HEIGHT;

Ship::Ship() : CollidableObject(
	new sf::ConvexShape(),
	15.f,
	Vector2::zero(),
	0.f
)
{
	// Set points of Ship
	auto shape = dynamic_cast<sf::ConvexShape*>(m_shape);
	shape->setPointCount(6);
	shape->setPoint(0, Vector2(0.f, -1.f));
	shape->setPoint(1, Vector2(1.f, 0.7f));
	shape->setPoint(2, Vector2(0.5f, 0.6f));
	shape->setPoint(3, Vector2(0.f, 1.f));
	shape->setPoint(4, Vector2(-0.5f, 0.6f));
	shape->setPoint(5, Vector2(-1.f, 0.7f));

	// Set different values of the shape
	setPosition(Vector2(SCREEN_WIDTH / 2.f, SCREEN_HEIGHT / 2.f));
}
Ship::~Ship() = default;

void Ship::start() {}
void Ship::update()
{
	handleRotation();
	handleMovement();
	handleShoot();

	clampPositionToScreen();
}
void Ship::draw(sf::RenderWindow& window)
{
	window.draw(*m_shape);
	CollidableObject::draw(window);
}
void Ship::destroy() {}


void Ship::handleRotation()
{
	// Rotate
	if (InputSystem::getKey(sf::Keyboard::Q) || InputSystem::getKey(sf::Keyboard::Left)) m_rotationSpeed -= m_rotationAcceleration * Time::deltaTime;
	if (InputSystem::getKey(sf::Keyboard::D) || InputSystem::getKey(sf::Keyboard::Right)) m_rotationSpeed += m_rotationAcceleration * Time::deltaTime;
	if (std::abs(m_rotationSpeed) > 0.f) m_rotationSpeed *= m_rotationDragFactor;
	if (std::abs(m_rotationSpeed) <= 0.1f) m_rotationSpeed = 0.f;
	m_rotationSpeed = Math::clamp(m_rotationSpeed, -m_maxRotationSpeed, m_maxRotationSpeed);

	rotate(m_rotationSpeed * Time::deltaTime);
}
void Ship::handleMovement()
{
	// Move
	if (InputSystem::getKey(sf::Keyboard::Z) || InputSystem::getKey(sf::Keyboard::Up))
		m_velocity += Math::angleToVector(m_shape->getRotation()) * m_movementAcceleration * Time::deltaTime;

	// Velocity X
	if (std::abs(m_velocity.X) > 0.f) m_velocity.X *= m_movementDragFactor;
	if (std::abs(m_velocity.X) <= 0.1f) m_velocity.X = 0.f;
	m_velocity.X = Math::clamp(m_velocity.X, -m_movementMaxSpeed, m_movementMaxSpeed);
	// Velocity Y
	if (std::abs(m_velocity.Y) > 0.f) m_velocity.Y *= m_movementDragFactor;
	if (std::abs(m_velocity.Y) <= 0.1f) m_velocity.Y = 0.f;
	m_velocity.Y = Math::clamp(m_velocity.Y, -m_movementMaxSpeed, m_movementMaxSpeed);

	move(m_velocity * Time::deltaTime);
}
void Ship::handleShoot()
{
	const Vector2 position = Vector2(m_shape->getPosition().x, m_shape->getPosition().y);
	if (InputSystem::getKey(sf::Keyboard::Space)) 
	{
		new Bullet(position, Math::angleToVector(m_shape->getRotation()));
	}
}
