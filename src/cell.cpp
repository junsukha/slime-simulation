#include "cell.hpp"

Cell::Cell() : trail_intensity(0.0f) {}

void Cell::addTrail(float amount) {
    trail_intensity = std::min(trail_intensity + amount, 255.0f);
}

float Cell::getIntensity() const {
    return trail_intensity;
}

void Cell::decay(float factor) {
        trail_intensity *= factor;
}
