#include "CollisionTag.h"
#include "Event.h"
#include "Time.h"
#include "GameHandler.h"
#include "TickSystem.h"
#include "Bullet.h"

Bullet::Bullet(const Vector2& position, const Vector2& direction) : CollidableObject(new sf::CircleShape(2.f), CollisionTag::BulletTag, 2.f,4.f, direction, 420.f)
{
	setOrigin(Vector2(m_size));
	setPosition(position);
	TickSystem::onMiniEvent += EventHandler::bind(&Bullet::tickUpdate, this);
}
Bullet::~Bullet()
{
	TickSystem::onMiniEvent -= EventHandler::bind(&Bullet::tickUpdate, this);
}

void Bullet::start() {}
void Bullet::update()
{
	move(m_velocity * m_speed * Time::deltaTime);
	clampPositionToScreen();

	auto asteroids = GameHandler::getObjectsOfTag(CollisionTag::AsteroidTag);
	for (auto asteroid : asteroids)
	{
		if (isColliding(*asteroid))
		{
			asteroid->destroy();
			destroy();
			break;
		}
	}
}
void Bullet::tickUpdate()
{
	m_tickBeforeDeath--;
	if (m_tickBeforeDeath == 0) destroy();
}
void Bullet::draw(sf::RenderWindow& window)
{
	window.draw(*m_shape);
	CollidableObject::draw(window);
}
void Bullet::destroy()
{
	GameHandler::destroyObject(this);
}