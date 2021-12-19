#pragma once
namespace sf { class RenderWindow; }
struct Vector2;

#include "CollidableObject.h"

class Bullet : public CollidableObject
{
public:
	Bullet(const Vector2& position, const Vector2& direction);
	~Bullet() override;

	void start() override;
	void update() override;
	void tickUpdate();
	void draw(sf::RenderWindow& window);
	void destroy() override;

private:
	int m_tickBeforeDeath = 20; // 2 Second from instantiation
};