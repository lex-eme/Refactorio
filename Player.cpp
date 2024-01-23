#include "Player.h"
#include "TextureHolder.h"

void Player::init(sf::Vector2f position) {
    _position = position;
    _sprite.setPosition(_position);
    _animations[1].init(TextureHolder::getTexture("graphics/running.png"), 0.04f, 22, 8, _sprite);
    _animations[0].init(TextureHolder::getTexture("graphics/idle.png"), 0.1f, 22, 8, _sprite);
    _animations[0].start(true);
    _animations[1].start(true);
}

void Player::handleInput() {
    bool up = sf::Keyboard::isKeyPressed(sf::Keyboard::Z);
    bool left = sf::Keyboard::isKeyPressed(sf::Keyboard::Q);
    bool right = sf::Keyboard::isKeyPressed(sf::Keyboard::D);
    bool down = sf::Keyboard::isKeyPressed(sf::Keyboard::S);

    if (up && down) {
        up = false;
        down = false;
    }

    if (left && right) {
        left = false;
        right = false;
    }
    
    _moving = true;

    if (up) {
        if (left) {
            _direction = Direction::NORTH_WEST;
        } else if (right) {
            _direction = Direction::NORTH_EAST;
        } else {
            _direction = Direction::NORTH;
        }
    } else if (down) {
        if (left) {
            _direction = Direction::SOUTH_WEST;
        } else if (right) {
            _direction = Direction::SOUTH_EAST;
        } else {
            _direction = Direction::SOUTH;
        }
    } else if (left) {
        _direction = Direction::WEST;
    } else if (right) {
        _direction = Direction::EAST;
    } else {
        _moving = false;
    }
}

void Player::update(float dt) {
    if (_moving) {
        if (!_wasMoving) {
            _animIndex = 1;
            _animations[_animIndex].applyTexture(_sprite);
        }

        switch (_direction) {
            case Direction::NORTH:
                _position.y -= _speed * dt;
                break;
            case Direction::NORTH_EAST:
                _position.x += _speed * 0.8f * dt;
                _position.y -= _speed * 0.8f * dt;
                break;
            case Direction::EAST:
                _position.x += _speed * dt;
                break;
            case Direction::SOUTH_EAST:
                _position.x += _speed * 0.8f * dt;
                _position.y += _speed * 0.8f * dt;
                break;
            case Direction::SOUTH:
                _position.y += _speed * dt;
                break;
            case Direction::SOUTH_WEST:
                _position.x -= _speed * 0.8f * dt;
                _position.y += _speed * 0.8f * dt;
                break;
            case Direction::WEST:
                _position.x -= _speed * dt;
                break;
            case Direction::NORTH_WEST:
                _position.x -= _speed * 0.8f * dt;
                _position.y -= _speed * 0.8f * dt;
                break;
        }

        _sprite.setPosition(_position);
    } else {
        if (_wasMoving) {
            _animIndex = 0;
            _animations[_animIndex].applyTexture(_sprite);
        }
    }

    _animations[_animIndex].update(dt, _sprite);
    _animations[_animIndex].setDirection(_direction, _sprite);
    _wasMoving = _moving;
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(_sprite);
}

sf::Vector2f Player::getCenter() const {
    return sf::Vector2f(_position.x, _position.y);
}
