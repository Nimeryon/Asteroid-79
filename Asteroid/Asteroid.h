#pragma once
#include "CollidableObject.h"

class Asteroid : public CollidableObject
{
public:
    Asteroid();
    ~Asteroid() override;

    void start() override;
    void update() override;
    void draw(sf::RenderWindow& window) override;
    void destroy() override;

private:
    float m_rotationSpeed;
};