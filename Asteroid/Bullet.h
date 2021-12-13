#pragma once
#include "Vector2.h"
#include "Time.h"
#include "CollidableObject.h"
#include "GameHandler.h"
#include "TickSystem.h"

class Bullet : public CollidableObject
{
public:
	Bullet(const Vector2& position, const Vector2& direction) : CollidableObject(new sf::CircleShape(2.f), 2.f, direction, 420.f)
	{
		setOrigin(Vector2(m_size));
		setPosition(position);
		TickSystem::onMiniEvent += EventHandler::bind(&Bullet::tickUpdate, this);
	}
	~Bullet() override
	{
		TickSystem::onMiniEvent -= EventHandler::bind(&Bullet::tickUpdate, this);
	}

	void start() override {}
	void update() override
	{
		move(m_velocity * m_speed * Time::deltaTime);
		clampPositionToScreen();
	}
	void tickUpdate()
	{
		m_tickBeforeDeath--;
		if (m_tickBeforeDeath == 0) GameHandler::destroyObject(this);
	}
	void draw(sf::RenderWindow& window) override
	{
		window.draw(*m_shape);
		CollidableObject::draw(window);
	}
	void destroy() override {}

private:
	int m_tickBeforeDeath = 20; // 2 Second from instantiation
};