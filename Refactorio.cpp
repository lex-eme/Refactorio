#include <SFML/Graphics.hpp>

#include "TextureHolder.h"
#include "Engine.h"

int main() {
    TextureHolder th;
    TextureHolder::getTexture("graphics/idle.png");
    TextureHolder::getTexture("graphics/running.png");

    Engine engine;
    engine.run();
    
    return 0;
}