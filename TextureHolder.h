#pragma once

#include <SFML/Graphics.hpp>
#include <map>

class TextureHolder {
private:
    std::map<std::string, sf::Texture> _textures;
    static TextureHolder* _instance;

public:
    TextureHolder();
    static sf::Texture& getTexture(std::string const& filename);
    static sf::Texture& getTexture(std::string const& filename, sf::IntRect frame);
};
