// SFML_Setup.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#define SFML_STATIC
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(600, 600), "SFML Setup Demo");

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
        window.clear(sf::Color::Magenta);

        // make the stuff to draw first
        // define a circle & a triangle
        sf::CircleShape circle(80.f);
        sf::CircleShape triangle(80.f, 3);
        circle.setPosition(40, 40);
        triangle.setPosition(40, 40);

        // set the shape color to green
        circle.setFillColor(sf::Color(100, 250, 50));
        triangle.setFillColor(sf::Color::Yellow);

        // draw everything here...
        // window.draw(...);
        window.draw(circle);
        window.draw(triangle);

        // end the current frame
        window.display();
    }

    return 0;
}
