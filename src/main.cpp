#include <SFML/Graphics.hpp>

#include "particle.hpp"
#include "trail.hpp"
#include "const.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
                            "Slime Simulation");
    window.setFramerateLimit(60);

    float step_size = 1.0f;

    TrailMap trailMap(WINDOW_WIDTH, WINDOW_HEIGHT);
    
    std::vector<Particle> particles;
    particles.reserve(NUM_PARTICLES);
    for (int i = 0; i < NUM_PARTICLES; i++) {
        float start_x = WINDOW_WIDTH/2;
        float start_y = WINDOW_HEIGHT/2;

        float heading_angle = static_cast<float>(std::rand() % 360);

        particles.emplace_back(start_x, start_y, heading_angle, step_size);
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        for (auto & p : particles) {
            p.update(trailMap);
        }

        trailMap.decay(DECAY_FACTOR);
        trailMap.updateTexture();

        window.clear(sf::Color::Black);

        window.draw(trailMap.getSprite());
        for (auto & p : particles) {
            p.draw(window);
        }

        window.display();
    }

    return 0;
}