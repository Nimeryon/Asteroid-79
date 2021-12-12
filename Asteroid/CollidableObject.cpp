#include "CollidableObject.h"

extern bool DEBUG_MODE;

CollidableObject::CollidableObject(sf::Shape* shape, const float& size, const Vector2& velocity, const float& speed) : GameObject(shape, size, velocity, speed), m_collision(new sf::CircleShape(size))
{
	// Set different values of the collision circle
	m_collision->setOrigin(Vector2(m_size));
	m_collision->setOutlineColor(sf::Color::Red);
	m_collision->setFillColor(sf::Color::Transparent);
	m_collision->setOutlineThickness(1.f);
}
CollidableObject::CollidableObject(sf::Shape* shape, const float& size) : CollidableObject(shape, size, Vector2::zero() ,0.f) {}
CollidableObject::CollidableObject(sf::Shape* shape) : CollidableObject(shape, 1.f) {}
CollidableObject::~CollidableObject()
{
	delete m_collision;
}

bool CollidableObject::isColliding(const CollidableObject& obj1, const CollidableObject& obj2)
{
	const sf::Shape* shape1 = obj1.getShape();
	const sf::Shape* shape2 = obj2.getShape();
	const float powX = std::pow(shape1->getPosition().x - shape2->getPosition().x, 2);
	const float powY = std::pow(shape1->getPosition().y - shape2->getPosition().y, 2);

	if (std::sqrt(powX + powY) >=
		obj1.getSize() + obj2.getSize()) {
		return false;
	}
	return true;
}
bool CollidableObject::isColliding(const CollidableObject& obj) const
{
	return isColliding(*this, obj);
}

void CollidableObject::draw(sf::RenderWindow& window)
{
	if (DEBUG_MODE) window.draw(*m_collision);
}

// Transfrom setters
void CollidableObject::setPosition(const Vector2& pos)
{
	GameObject::setPosition(pos);
	m_collision->setPosition(pos);
}
void CollidableObject::setRotation(const float& rotation)
{
	GameObject::setRotation(rotation);
	m_collision->setRotation(rotation);
}
void CollidableObject::setOrigin(const Vector2& origin)
{
	GameObject::setOrigin(origin);
	m_collision->setOrigin(origin);
}
void CollidableObject::setScale(const Vector2& scale)
{
	GameObject::setScale(scale);
	m_collision->setScale(scale);
}

// Transform properties
void CollidableObject::move(const Vector2& offset)
{
	GameObject::move(offset);
	m_collision->move(offset);
}
void CollidableObject::rotate(const float& offset)
{
	GameObject::rotate(offset);
	m_collision->rotate(offset);
}