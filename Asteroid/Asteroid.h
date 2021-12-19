#pragma once
namespace sf { class RenderWindow; }
struct Vector2;

#include "CollidableObject.h"

class Asteroid : public CollidableObject
{
public:
    Asteroid(const float& size, const Vector2& position);
    Asteroid(const float& size);
    Asteroid();
    ~Asteroid() override;

    void start() override;
    void update() override;
    void draw(sf::RenderWindow& window) override;
    void destroy() override;

private:
    float m_rotationSpeed;
    float m_minBreakSize = 15.f;
};