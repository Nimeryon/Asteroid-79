#include <SFML/Graphics.hpp>

#include "Vector2.h"

/*
 * Class:
 * - Entity
 *  . Position
 *  . Velocity
 *  . Rotation
 *  . Health
 *
 * - SpaceShip : Entity
 *  . Keyboard
 *  . Upgrade[]
 *
 * - Ovni : Entity
 *
 * - Asteroid : Entity
 *  . Size
 *
 * - Bullet : Entity
 *  . LifeTime
 *  . Power
 *
 *  - Particules : Entity
 *
 * - Upgrade
 *
 * - Keyboard
 *
 * - UI
 *
 * - SoundPlayer
 *
 * - Level
 *  - NbrAsteroid
 *  - NbrOvni
 *
 * - Game
 *  . Level
 *  . Score
*/

int main()
{
    sf::RenderWindow window(sf::VideoMode(1080, 720), "Asteroid");

    sf::ConvexShape shape(10);
    shape.setPoint(0, Vector2(-1.62035, -2.0139));
    shape.setPoint(1, Vector2(0.2685, -2.5972));
    shape.setPoint(2, Vector2(1.2685, -2.2361));
    shape.setPoint(3, Vector2(2, -1.56945));
    shape.setPoint(4, Vector2(2.37965, -0.30555));
    shape.setPoint(5, Vector2(2.03705, 1.625));
    shape.setPoint(6, Vector2(0.3426, 2.4028));
    shape.setPoint(7, Vector2(-1.07405, 1.68055));
    shape.setPoint(8, Vector2(-2.0463, 0.80555));
    shape.setPoint(9, Vector2(-1.6389, -0.70835));
    shape.setScale(Vector2(20, 20));
    shape.setPosition(540, 360);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }
}