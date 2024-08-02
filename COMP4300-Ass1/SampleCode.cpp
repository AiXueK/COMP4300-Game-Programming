#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>

int main()
{
    // Create a window
    const int wWeight = 640;
    const int wHeight = 480;
    sf::RenderWindow window(sf::VideoMode(wWeight, wHeight), "SFML Works"); // render a window in video type
    window.setFramerateLimit(60); // limit the screen frame rate at 60 per second

    int r = 0;
    int g = 255;
    int b = 255;

    // Draw shapes
    sf::CircleShape circle(50); // circle with radius of 50
    circle.setFillColor(sf::Color(r, g, b));
    circle.setPosition(300.0f, 300.0f); // set top left position of the shape
    float circleSpeed = 1.0f; // 1.0f per frame

    sf::Font font;
    if (!font.loadFromFile("fonts/FreshMulberryDemoRegular.ttf")) // if it returns true, nothing happens
    {
        std::cerr << "Could not load font." << std::endl;
        exit(-1);
    }

    // Set up text object
    sf::Text text("Sample Text", font, 24); // set up text string, font and character size
    text.setPosition(0, wHeight - (float)text.getCharacterSize());

    // Set up the main loop to keep the window open
    while (window.isOpen())
    {
        // Set up the supervision of the window event
        sf::Event event;
        while (window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            if (event.type == sf::Event::KeyPressed)
            {
                std::cout << "Key pressed with code = " << event.key.code << std::endl;

                if (event.key.code == sf::Keyboard::D)
                {
                    circleSpeed *= -1.0F;
                }
            }
        }

        // Update new shape position per frame
        float speedX = 0.5;
        float speedY = 2.0;
        circle.setPosition(circle.getPosition().x + circleSpeed, circle.getPosition().y + speedY);

        // Draw & Render window
        window.clear(); // clear what's left in the previous frame
        window.draw(circle);
        window.draw(text);
        window.display();
    }

    return 0;
}