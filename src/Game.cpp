#include "Game.h"
#include "Engine/Managers/CollisionManager.h"

Game::Game(const int width, const int height): Program(width, height) {}

void Game::init() {
    loadResources();
    sprite.setTexture(ResourceManager::GetTexture("texture"));
    sprite.setColor(glm::vec3(1.0f, 1.0f, 1.0f));
    sprite.setSize(glm::vec2(100.0f, 100.0f));
    sprite.setPosition(glm::vec2(100.0f, 100.0f));
    sprite.setCollision(true);

    sprite2.setTexture(ResourceManager::GetTexture("texture"));
    sprite2.setColor(glm::vec3(1.0f, 1.0f, 1.0f));
    sprite2.setSize(glm::vec2(100.0f, 100.0f));
    sprite2.setPosition(glm::vec2(300.0f, 200.0f));
    sprite2.setCollision(true);
}

void Game::loadResources()
{
    InputManager::createAxis(sf::Keyboard::Down, sf::Keyboard::Up, "Vertical");
    InputManager::createAxis(sf::Keyboard::Left, sf::Keyboard::Right, "Horizontal");
    ResourceManager::LoadTexture("texture.jpg", "texture");
}

void Game::update(const float deltaTime)
{
    sprite.setVelocity({InputManager::getAxis("Horizontal") * 100.0f, InputManager::getAxis("Vertical") * 100.0f});
    sprite.setPosition(sprite.getPosition() + (sprite.getVelocity() * deltaTime));
    CollisionManager::resolveCollision(sprite, sprite2);
}

void Game::render()
{
    sprite.draw(*spriteRenderer);
    sprite2.draw(*spriteRenderer);
    shapeRenderer->DrawLine({sprite.getBoundingBox().left(), sprite.getBoundingBox().top()},{sprite.getBoundingBox().right(), sprite.getBoundingBox().bottom()}, glm::vec3(1.0f, 0.5f, 1.0f), 5);
}
