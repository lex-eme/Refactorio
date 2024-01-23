#pragma once

#include <SFML/Graphics.hpp>
#include <map>

class TextureHolder {
public:
    TextureHolder();
    static sf::Texture& getTexture(std::string const& filename);
    static sf::Texture& getTexture(std::string const& filename, sf::IntRect frame);

private:
    std::map<std::string, sf::Texture> _textures;
    static TextureHolder* _instance;
};
