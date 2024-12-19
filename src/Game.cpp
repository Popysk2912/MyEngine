#include "Game.h"

Game::Game(const int width, const int height): Program(width, height) {}

void Game::init() {
    loadResources();
    sprite.setTexture(ResourceManager::GetTexture("texture"));
    sprite.setColor(glm::vec3(1.0f, 1.0f, 1.0f));
    sprite.setSize(glm::vec2(100.0f, 100.0f));
    sprite.setPosition(glm::vec2(100.0f, 100.0f));
}

void Game::loadResources()
{
    ResourceManager::LoadTexture("texture.jpg", "texture");
}

void Game::update(float deltaTime)
{

}

void Game::render()
{
    sprite.draw(*spriteRenderer);
}
