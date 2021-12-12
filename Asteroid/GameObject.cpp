#include "GameObject.h"
#include "GameHandler.h"

extern int SCREEN_WIDTH;
extern int SCREEN_HEIGHT;

GameObject::GameObject(sf::Shape* shape, const float& size, const Vector2& velocity, const float& speed) : m_shape(shape), m_size(size), m_velocity(velocity), m_speed(speed)
{
	setScale(Vector2(m_size));

	GameHandler::onStart += EventHandler::bind(&GameObject::start, this);
	GameHandler::onUpdate += EventHandler::bind(&GameObject::update, this);
	GameHandler::onDraw += EventHandler::bind<sf::RenderWindow&, GameObject>(&GameObject::draw, this);
}
GameObject::GameObject(sf::Shape* shape, const float& size, const float& speed) : GameObject(shape, size, Vector2::zero(), speed) {}
GameObject::GameObject(sf::Shape* shape, const float& size, const Vector2& velocity) : GameObject(shape, size, velocity, 0.f) {}
GameObject::GameObject(sf::Shape* shape, const float& size) : GameObject(shape, size, 0.f) {}
GameObject::GameObject(sf::Shape* shape) : GameObject(shape, 1.f) {}

GameObject::~GameObject()
{
	GameHandler::onStart -= EventHandler::bind(&GameObject::start, this);
	GameHandler::onUpdate -= EventHandler::bind(&GameObject::update, this);
	GameHandler::onDraw -= EventHandler::bind<sf::RenderWindow&, GameObject>(&GameObject::draw, this);
}

// Setters
void GameObject::setVelocity(const Vector2& velocity) { m_velocity = velocity; }
void GameObject::setSize(const float& size)
{
	m_size = size;
	setScale(Vector2(m_size));
}
void GameObject::setSpeed(const float& speed) { m_speed = speed; }

// Getters
sf::Shape* GameObject::getShape() const { return m_shape; }
Vector2 GameObject::getVelocity() const { return m_velocity; }
float GameObject::getSize() const { return m_size; }
float GameObject::getSpeed() const { return m_speed; }

// Methods
void GameObject::clampPositionToScreen()
{
	if (m_shape->getPosition().x < -m_size) move(Vector2(SCREEN_WIDTH + m_size, 0));
	if (m_shape->getPosition().x > SCREEN_WIDTH + m_size) move(Vector2(-(SCREEN_WIDTH + m_size), 0));
	if (m_shape->getPosition().y < -m_size) move(Vector2(0, SCREEN_HEIGHT + m_size));
	if (m_shape->getPosition().y > SCREEN_HEIGHT + m_size) move(Vector2(0, -(SCREEN_HEIGHT + m_size)));
}

// Transfrom setters
void GameObject::setPosition(const Vector2& pos) { m_shape->setPosition(pos); }
void GameObject::setRotation(const float& rotation) { m_shape->setRotation(rotation); }
void GameObject::setOrigin(const Vector2& origin) { m_shape->setOrigin(origin); }
void GameObject::setScale(const Vector2& scale) { m_shape->setScale(scale); }

// Transform properties
void GameObject::move(const Vector2& offset) { m_shape->move(offset); }
void GameObject::rotate(const float& offset) { m_shape->rotate(offset); }