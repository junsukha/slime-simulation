#include <SFML/Graphics.hpp>

#include "particle.hpp"
#include "const.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
                            "Slime Simulation");
    window.setFramerateLimit(60);

    Particle particle(WINDOW_WIDTH/2, WINDOW_HEIGHT/2, 0, 0);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        particle.update();

        window.clear(sf::Color::Black);

        particle.draw(window);

        window.display();
    }

    return 0;
}