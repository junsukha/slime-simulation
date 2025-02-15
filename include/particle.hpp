#ifndef PARTICLE_HPP
#define PARTICLE_HPP

#include <SFML/Graphics.hpp>

#include "trail.hpp"
#include "sensor.hpp"

class Particle {
private:
    sf::CircleShape shape;

    sf::Vector2f position;
    sf::Vector2f velocity;
    float angle_radians;
    float step_size;

    Sensor left_sensor;
    Sensor center_sensor;
    Sensor right_sensor;

    void update_sensors();

public:
    Particle(float x, float y, float agnle, float step);

    void draw(sf::RenderWindow &window);
    void update(TrailMap & trail);
    void senseAndTurn(const TrailMap& trail);

    sf::Vector2f getPosition() const;
};

#endif // PARTICLE_HPP