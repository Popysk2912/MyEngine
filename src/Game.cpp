#include "Game.h"


Game::Game(const int width, const int height): Program(width, height) {}

void Game::init() {
    loadResources();
    grid = Grid(16, 16,64,64);
    frameT = ResourceManager::GetTexture("frame");
}

void Game::loadResources()
{
    for (int i = 1; i <= 8; i++)
    {
        ResourceManager::LoadTexture((std::to_string(i) + ".png").c_str(), std::to_string(i));
    }
    ResourceManager::LoadTexture("empty.png", "empty");
    ResourceManager::LoadTexture("flag.png", "flag");
    ResourceManager::LoadTexture("metal.png", "metal");
    ResourceManager::LoadTexture("bomb.png", "bomb");
    ResourceManager::LoadTexture("frame.png", "frame");
}

void Game::update(const float deltaTime)
{
    const int mPos_x = (static_cast<int>(InputManager::getMousePosition(window).x) - 64) / 32;
    const int mPos_y = (height - (static_cast<int>(InputManager::getMousePosition(window).y) + 64)) / 32;
    if (InputManager::isMouseClicked(sf::Mouse::Left))
    {
        if (grid.openCell(mPos_x, mPos_y) == -1)
        {
            grid.openAll();
        }
    }
    else if (InputManager::isMouseClicked(sf::Mouse::Right))
    {
        grid.setFlag(mPos_x, mPos_y);
    }
    if (InputManager::isKeyDown(sf::Keyboard::R))
        grid = Grid(16, 16,64,64);
}

void Game::render() {
    grid.draw(*spriteRenderer);
    spriteRenderer->DrawSprite(frameT, {0, 0}, {640, 640}, 0, {1,1,1});
}


