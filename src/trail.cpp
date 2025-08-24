#include "trail.hpp"
#include "const.hpp"
#include "cell.hpp"

// TrailMap::TrailMap(int w, int h)
//     : width(w), height(h), cells(w * h) {

//     image.create(w, h, sf::Color::Black);
//     texture.loadFromImage(image);
//     sprite.setTexture(texture);
// }

TrailMap::TrailMap(int w, int h)
    : width(w), height(h), cells(w * h), sprite(texture), image({static_cast<unsigned int>(w), static_cast<unsigned int>(h)}, sf::Color::Black) {

    // image({w, h}, sf::Color::Black);
    texture.loadFromImage(image);
    sprite.setTexture(texture);
}
// TrailMap::TrailMap(int w, int h)
// : sprite(texture) // must initialize here in SFML 3
// {
//     image({w, h}, sf::Color::Black);
//     if (!texture.loadFromImage(image)) {
//         throw std::runtime_error("Failed to load texture from image");
//     }
// }

void TrailMap::addTrail(int x, int y, float amount) {
    if (x >= 0 && x < width && y >= 0 && y < height) {
        int index = y * width + x;
        cells[index].addTrail(amount);
    }
}

void TrailMap::decay(float factor) {
    for (auto &cell : cells) {
        cell.decay(factor);
    }
}

void TrailMap::updateTexture() {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int index = y * width + x;
            float val = cells[index].getIntensity();
            // image.setPixel(x, y, sf::Color(val, val, val));
            // image.setPixel({x, y}, sf::Color(val, val, val));
            image.setPixel(sf::Vector2u(static_cast<unsigned>(x),
                            static_cast<unsigned>(y)),
            sf::Color(val, val, val));
        }
    }

    texture.update(image);
}

float TrailMap::getTrailValue(float fx, float fy) const {
    int ix = static_cast<int>(fx);
    int iy = static_cast<int>(fy);
    if (ix < 0 || ix >= width || iy < 0 || iy >= height) {
        return 0.0f;
    }
    return cells[iy * width + ix].getIntensity();
}

sf::Sprite TrailMap::getSprite() const {
    return sprite;
}