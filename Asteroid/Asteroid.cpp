#include "Asteroid.h"
#include "Random.h"
#include "Time.h"
#include "vector"
#include "iostream"

extern int SCREEN_WIDTH;
extern int SCREEN_HEIGHT;

std::vector<std::vector<Vector2>> asteroidShapes = 
{
    { // Asteroid shape 1 
        Vector2(0.447f, 0.99f),
        Vector2(-0.493f, 0.908f),
        Vector2(-0.888f, 0.607f),
        Vector2(-0.995f, -0.226f),
        Vector2(-0.403f, -0.544f),
        Vector2(0.068f, -0.974f),
        Vector2(0.819f, -0.596f),
        Vector2(0.896f, 0.371f)
    },
    { // Asteroid shape 2
        Vector2(-0.255f, -0.995f),
		Vector2(-0.75f, -0.524f),
		Vector2(-0.988f, 0.089f),
		Vector2(-0.608f, 0.418f),
		Vector2(-0.221f, 0.966f),
		Vector2(0.464f, 0.945f),
		Vector2(0.957f, 0.582f),
		Vector2(0.837f, 0.14f),
		Vector2(0.926f, -0.483f),
		Vector2(0.447f, -0.925f)
    },
    { // Asteroid shape 3
		Vector2(-0.454f, -0.976f),
		Vector2(0.512f, -0.877f),
		Vector2(0.995f, 0.031f),
		Vector2(0.683f, 0.839f),
		Vector2(-0.259f, 0.986f),
		Vector2(-0.957f, 0.664f),
		Vector2(-0.985f, -0.401f)
    },
    { // Asteroid shape 4
        Vector2(-0.125f, -0.969f),
        Vector2(0.409f, -0.603f),
        Vector2(0.978f, -0.418f),
        Vector2(0.741f, 0.291f),
        Vector2(0.738f, 0.993f),
        Vector2(-0.034f, 0.702f),
        Vector2(-0.707f, 0.976f),
        Vector2(-0.985f, 0.216f),
        Vector2(-0.745f, -0.411f),
        Vector2(-0.659f, -0.866f)
    }
};

Asteroid::Asteroid() : CollidableObject(
    new sf::ConvexShape(),
    Random::randomf(10.f, 40.f),
    Vector2(Random::randomf(-1.f, 1.f), Random::randomf(-1.f, 1.f)),
    Random::randomf(20.f, 100.f)
),
m_rotationSpeed(Random::randomf(10.f, 60.f))
{
    // Set rotation direction
    m_rotationSpeed *= Random::randomb() ? -1 : 1;

    // Set points of Asteroid
    auto shape = dynamic_cast<sf::ConvexShape*>(m_shape);
    const int shapeForm = Random::random(0, asteroidShapes.size());
    shape->setPointCount(asteroidShapes[shapeForm].size());
    for (int i = 0; i < asteroidShapes[shapeForm].size(); ++i)
		shape->setPoint(i, asteroidShapes[shapeForm][i]);

    // Set different values of the shape
    m_shape->setFillColor(sf::Color::Transparent);
    m_shape->setOutlineThickness(0.05f);
    setPosition(
        Vector2(
	        Random::randomf(0.f, SCREEN_WIDTH),
	        Random::randomf(0.f, SCREEN_HEIGHT)
        )
    );

    m_velocity = Vector2(
        Random::randomf(-1.f, 1.f),
        Random::randomf(-1.f, 1.f)
    );
}
Asteroid::~Asteroid()
{
    delete m_shape;
};

void Asteroid::start() {}
void Asteroid::update()
{
    rotate(-m_rotationSpeed * Time::deltaTime);
    move(m_velocity * m_speed * Time::deltaTime);

    clampPositionToScreen();
}
void Asteroid::draw(sf::RenderWindow& window)
{
    window.draw(*m_shape);
    CollidableObject::draw(window);
}
void Asteroid::destroy()
{
    delete this;
}
