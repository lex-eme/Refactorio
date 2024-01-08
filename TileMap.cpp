#include "TileMap.h"
#include "TextureHolder.h"

void TileMap::load(sf::Vector2u tileSize, int width, int height) {
    _tileset = TextureHolder::getTexture("graphics/grass-1.png");

    _width = width;
    _height = height;
    _tileSize = tileSize;

    _vertices.setPrimitiveType(sf::Triangles);
    _vertices.resize(width * height * 6);
    srand((int)time(0));

    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            int tileNumber = 0;

            if ((rand() % 4) < 3) {
                tileNumber = rand() % 4;
            } else {
                tileNumber = (rand() % 12) + 4;
            }

            int tu = tileNumber % (_tileset.getSize().x / tileSize.x);
            int tv = tileNumber / (_tileset.getSize().x / tileSize.x);

            sf::Vertex* triangles = &_vertices[(i + j * width) * 6];

            float tsx = (float)tileSize.x;
            float tsy = (float)tileSize.y;

            triangles[0].position = sf::Vector2f(i * tsx, j * tsy);
            triangles[1].position = sf::Vector2f((i + 1) * tsx, j * tsy);
            triangles[2].position = sf::Vector2f(i * tsx, (j + 1) * tsy);
            triangles[3].position = sf::Vector2f(i * tsx, (j + 1) * tsy);
            triangles[4].position = sf::Vector2f((i + 1) * tsx, j * tsy);
            triangles[5].position = sf::Vector2f((i + 1) * tsx, (j + 1) * tsy);

            triangles[0].texCoords = sf::Vector2f(tu * tsx, tv * tsy + 160);
            triangles[1].texCoords = sf::Vector2f((tu + 1) * tsx, tv * tsy + 160);
            triangles[2].texCoords = sf::Vector2f(tu * tsx, (tv + 1) * tsy + 160);
            triangles[3].texCoords = sf::Vector2f(tu * tsx, (tv + 1) * tsy + 160);
            triangles[4].texCoords = sf::Vector2f((tu + 1) * tsx, tv * tsy + 160);
            triangles[5].texCoords = sf::Vector2f((tu + 1) * tsx, (tv + 1) * tsy + 160);
        }
    }
}

sf::Vector2f TileMap::getSize() const {
    return sf::Vector2f((float)_width * _tileSize.x, (float)_height * _tileSize.y);
}

void TileMap::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();
    states.texture = &_tileset;
    target.draw(_vertices, states);
}
