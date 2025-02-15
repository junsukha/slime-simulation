#include <cmath>

#include "particle.hpp"
#include "trail.hpp"
#include "sensor.hpp"
#include "const.hpp"

Particle::Particle(float x, float y, float angle, float step)
    : position(x, y), step_size(step),  
    left_sensor(-SENSOR_ANGLE, SENSOR_DISTANCE),
    center_sensor(0.0f, SENSOR_DISTANCE),
    right_sensor(SENSOR_ANGLE, SENSOR_DISTANCE) {

    shape.setRadius(PARTICLE_RADIUS);
    shape.setFillColor(sf::Color::White);
    shape.setOrigin(PARTICLE_RADIUS, PARTICLE_RADIUS);

    angle_radians = angle * M_PI / 180.0f;

    update_sensors();

    velocity.x = std::sin(angle_radians) * step_size;
    velocity.y = -std::cos(angle_radians) * step_size;
}

void Particle::draw(sf::RenderWindow &window) {
    shape.setPosition(position);
    window.draw(shape);
}

void Particle::update(TrailMap& trail) {
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

    update_sensors();

    int px = static_cast<int>(position.x);
    int py = static_cast<int>(position.y);
    trail.addTrail(px, py, DEPOSIT_AMOUNT);
}

void Particle::senseAndTurn(const TrailMap& trail) {
    sf::Vector2f left_position = left_sensor.getPosition();
    sf::Vector2f center_position = center_sensor.getPosition();
    sf::Vector2f right_position = right_sensor.getPosition();

    float val_left   = trail.getTrailValue(left_position.x, left_position.y);
    float val_front  = trail.getTrailValue(center_position.x, center_position.y);
    float val_right  = trail.getTrailValue(right_position.x, right_position.y);

    if (val_front > val_left && val_front > val_right) {
        // go straight
    }
    else if (val_left > val_right) {
        angle_radians -= ROTATION_ANGLE;
    }
    else if (val_right > val_left) {
        angle_radians += ROTATION_ANGLE;
    } 
    else if (val_left == val_right) {
        // Random turn
        if (rand() % 2 == 0) {
            angle_radians -= ROTATION_ANGLE;
        } 
        else {
            angle_radians += ROTATION_ANGLE;
        }
    }
    
    velocity.x = std::sin(angle_radians) * step_size;
    velocity.y = -std::cos(angle_radians) * step_size;
}

void Particle::update_sensors() {
    left_sensor.update(position.x, position.y, angle_radians);
    center_sensor.update(position.x, position.y, angle_radians);
    right_sensor.update(position.x, position.y, angle_radians);
}

sf::Vector2f Particle::getPosition() const {
    return position;
}