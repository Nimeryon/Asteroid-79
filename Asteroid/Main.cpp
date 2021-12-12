#include <SFML/Graphics.hpp>
#include <iostream>

#include "GameHandler.h"
#include "InputSystem.h"
#include "TickSystem.h"
#include "Time.h"
#include "Asteroid.h"
#include "Random.h"

int SCREEN_WIDTH = 1080;
int SCREEN_HEIGHT = 720;
bool DEBUG_MODE = false;

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
 * - Keyboard | X
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
    sf::Clock clock;

    // Set seed of random
    std::srand(std::time(nullptr));

    // Initialize systems
    Time time;
    GameHandler gameHandler;
    InputSystem inputSystem;
    TickSystem tickSystem;

    // GameObject test
    for (int i = 0; i < 50; ++i)
        new Asteroid();

    // Call start event
    GameHandler::onStart();

    // Start loop
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Asteroid");
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        // Update Systems
        time.setTime(clock.restart());
        gameHandler.update(window);

        if (InputSystem::getKeyDown(sf::Keyboard::F3)) DEBUG_MODE = !DEBUG_MODE;

        window.display();
    }

    return 0;
}