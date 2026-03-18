// SFML_Setup.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#define SFML_STATIC
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(500, 500), "SFML Setup Demo");

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
        window.clear(sf::Color::Cyan);

        // setup shapes
        // ...
        sf::CircleShape face(50.0f);
        face.setFillColor(sf::Color::Magenta);

        sf::CircleShape nose(10.0f, 3);
        nose.setFillColor(sf::Color::Blue);
        nose.setPosition(50.0f - 10.0f, 50.0f);

        // draw everything here...
        // window.draw(...);
        window.draw(face);
        window.draw(nose);

        // end the current frame
        window.display();
    }
}
