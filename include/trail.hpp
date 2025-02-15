#ifndef TRAIL_HPP
#define TRAIL_HPP

#include <SFML/Graphics.hpp>

#include <vector>
#include "cell.hpp"

class TrailMap {
private:
    int width;
    int height;

    std::vector<Cell> cells;

    sf::Image   image;
    sf::Texture texture;
    sf::Sprite  sprite;

public:
    TrailMap(int w, int h);

    void addTrail(int x, int y, float amount);
    void decay(float factor);
    void updateTexture();
    float getTrailValue(float fx, float fy) const;
    sf::Sprite getSprite() const;
};

#endif // TRAIL_HPP