#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class TileMap : public sf::Drawable, public sf::Transformable {
public:
    void load(sf::Vector2u tileSize, int width, int height);
    sf::Vector2f getSize() const;

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    sf::VertexArray _vertices;
    sf::Texture _tileset;

    sf::Vector2u _tileSize;
    int _width = 0;
    int _height = 0;
};
