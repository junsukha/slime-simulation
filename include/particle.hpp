#ifndef PARTICLE_HPP
#define PARTICLE_HPP

#include <SFML/Graphics.hpp>

#include "trail.hpp"

class Particle {
private:
    sf::CircleShape shape;

    sf::Vector2f position;
    sf::Vector2f velocity;
    float angle_radians;
    float step_size;

public:
    Particle(float x, float y, float agnle, float step);

    void draw(sf::RenderWindow &window);
    void update(TrailMap & trail);

    sf::Vector2f getPosition() const;
};

#endif // PARTICLE_HPP