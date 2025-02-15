#ifndef SENSOR_HPP
#define SENSOR_HPP

#include <SFML/Graphics.hpp>

class Sensor {
private:
    sf::Vector2f position;
    float angle;
    float distance;

public:
    Sensor(float angle, float distance);

    void update(float x, float y, float angle);

    sf::Vector2f getPosition() const;
};

#endif // SENSOR_HPP