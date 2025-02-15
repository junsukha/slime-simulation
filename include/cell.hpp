#ifndef CELL_HPP
#define CELL_HPP

#include <SFML/Graphics.hpp>

class Cell {
private:
    float trail_intensity;

public:
    Cell();

    void addTrail(float amount);
    float getIntensity() const;
    void decay(float factor);
};

#endif // CELL_HPP