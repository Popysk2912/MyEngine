#pragma once
#include <iostream>

#include "spriteRenderer.h"
#include "sprite.h"
#include "shader.h"
#include "Managers/ResourceManager.h"
#include "Managers/InputManager.h"
#include "Primitives/shapeRenderer.h"

class Program
{
public:
    Program(int width, int height); 
    virtual ~Program() = default;
    void run();

private:
    bool running = true;
    Shader shader;
    Shader primitive_shader;
    sf::RenderWindow window;

protected:
    int width, height; 
    sf::Clock clock;
    float time = 0;

    std::unique_ptr<SpriteRenderer> spriteRenderer;
    std::unique_ptr<ShapeRenderer> shapeRenderer;

    virtual void loadResources();
    virtual void init() = 0;
    virtual void update(float dt) = 0;
    virtual void render() = 0;
    void setFrameRate(int frameRate);
    void Draw(Sprite sprite) const;
};
