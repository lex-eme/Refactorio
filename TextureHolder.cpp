#include <assert.h>

#include "TextureHolder.h"

TextureHolder* TextureHolder::_instance = nullptr;

TextureHolder::TextureHolder() {
    assert(_instance == nullptr);
    _instance = this;
}

sf::Texture& TextureHolder::getTexture(std::string const& filename) {
    auto& m = _instance->_textures;
    auto keyValuePair = m.find(filename);

    if (keyValuePair != m.end()) {
        return keyValuePair->second;
    }

    auto& texture = m[filename];

    if (!texture.loadFromFile(filename)) {
        exit(EXIT_FAILURE);
    }

    return texture;
}

sf::Texture& TextureHolder::getTexture(std::string const& filename, sf::IntRect frame) {
    auto& m = _instance->_textures;
    auto keyValuePair = m.find(filename);

    if (keyValuePair != m.end()) {
        return keyValuePair->second;
    }

    auto& texture = m[filename];

    if (!texture.loadFromFile(filename, frame)) {
        exit(EXIT_FAILURE);
    }

    return texture;
}
