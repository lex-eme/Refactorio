#pragma once

#include <SFML/Graphics.hpp>

#include "Direction.h"
#include "Animation.h"

class Player : public sf::Drawable {
private:
    sf::Sprite _sprite;
    sf::Vector2f _position;
    
    float _speed = 200.0f;
    bool _moving = false;
    bool _wasMoving = false;
    Direction _direction = Direction::SOUTH;
    int _animIndex = 0;
    Animation _animations[2];

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

public:
    Player();
    void init(sf::Vector2f position);
    void handleInput();
    void update(float dt);
    sf::Vector2f getCenter() const;
};
