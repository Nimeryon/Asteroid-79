#include <SFML/Graphics.hpp>
#include <iostream>

#include "ResourceManager.h"
#include "GameHandler.h"
#include "InputSystem.h"
#include "TickSystem.h"
#include "Time.h"
#include "Asteroid.h"
#include "Ship.h"

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
    // Set seed of random
    std::srand(std::time(nullptr));
    
    // Initialize systems
    if (!ResourceManager::load()) return 1;
    Time time;
    GameHandler gameHandler;
    InputSystem inputSystem;
    TickSystem tickSystem;

    // GameObject test
    new Ship();
    for (int i = 0; i < 20; ++i)
        new Asteroid();

    sf::Font font;
	font.loadFromFile("./Fonts/Minecraft.ttf");

    sf::Text text;
    //text.setFont(ResourceManager::getFont());
    text.setFont(font);
    text.setString("Hello world");
    text.setCharacterSize(24);

    // Call start event
    gameHandler.start();

    // Start loop
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Asteroid");
    sf::Clock clock;
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
        time.setTime(clock.restart().asSeconds());
        gameHandler.update(window);

        // Set debug mode
        if (InputSystem::getKeyDown(sf::Keyboard::F3)) DEBUG_MODE = !DEBUG_MODE;

        window.draw(text);

        window.display();
    }

    return 0;
}