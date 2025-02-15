#include "sensor.hpp"

Sensor::Sensor(float angle, float distance)
    : angle(angle), distance(distance) {}

void Sensor::update(float x, float y, float heading_angle) {
    float angle = heading_angle + this->angle;

    position.x = x + std::sin(angle) * distance;
    position.y = y - std::cos(angle) * distance;
}

sf::Vector2f Sensor::getPosition() const {
    return position;
}