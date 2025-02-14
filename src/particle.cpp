#include <cmath>

#include "particle.hpp"
#include "const.hpp"

Particle::Particle(float x, float y, float angle, float step)
    : position(x, y), step_size(step) {

    shape.setRadius(PARTICLE_RADIUS);
    shape.setFillColor(sf::Color::White);
    shape.setOrigin(PARTICLE_RADIUS, PARTICLE_RADIUS);

    angle_radians = angle * M_PI / 180.0f;

    velocity.x = std::sin(angle_radians) * step_size;
    velocity.y = -std::cos(angle_radians) * step_size;
}

void Particle::draw(sf::RenderWindow &window) {
    shape.setPosition(position);
    window.draw(shape);
}

void Particle::update() {
    position += velocity;

    // wrapping on the edges
    if (position.x < 0)
        position.x += WINDOW_WIDTH;
    else if (position.x >= WINDOW_WIDTH)
        position.x -= WINDOW_WIDTH;
    else if (position.y < 0)
        position.y += WINDOW_HEIGHT;
    else if (position.y >= WINDOW_HEIGHT)
        position.y -= WINDOW_HEIGHT;
}

sf::Vector2f Particle::getPosition() const {
    return position;
}