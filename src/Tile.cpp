#include "Tile.h"

const int BOMB_CHANCE = 10;

Tile::Tile(float x, float y, float offset_X, float offset_Y)
{
    position = glm::vec2(x, y);

    sprite.setPosition({position.x + offset_X, position.y + offset_Y});
    sprite.setSize({32, 32});

    flagSprite.setPosition({position.x + offset_X, position.y + offset_Y});
    flagSprite.setSize({32, 32});
    hiddenTexture = ResourceManager::GetTexture("metal");
    flagTexture = ResourceManager::GetTexture("flag");

    int rn = Randomizer<int>::generate(1, 100);
    if(rn >= 100-BOMB_CHANCE)
    {
        num = -1;
    }
    else
    {
        num = 0;
    }
    this->setImage();
}

void Tile::draw(SpriteRenderer& renderer)
{
    renderer.DrawSprite(texture, sprite.getPosition(), sprite.getSize(), sprite.getRotate(), sprite.getColor());
    if (hidden)
        renderer.DrawSprite(hiddenTexture, sprite.getPosition(), sprite.getSize(), sprite.getRotate(), sprite.getColor());
    if (flagged)
        renderer.DrawSprite(flagTexture, sprite.getPosition(), sprite.getSize(), sprite.getRotate(), sprite.getColor());
}

void Tile::flag()
{
    flagged = !flagged;
}

void Tile::open()
{
    flagged = false;
    hidden = false;
}

void Tile::setImage()
{
    switch (num)
    {
    default:
        break;
    case -1:
        texture = ResourceManager::GetTexture("bomb");
        break;
    case 0:
        texture = ResourceManager::GetTexture("empty");
        break;
    case 1:
        texture = ResourceManager::GetTexture("1");
        break;
    case 2:
        texture = ResourceManager::GetTexture("2");
        break;
    case 3:
        texture = ResourceManager::GetTexture("3");
        break;
    case 4:
        texture = ResourceManager::GetTexture("4");
        break;
    case 5:
        texture = ResourceManager::GetTexture("5");
        break;
    case 6:
        texture = ResourceManager::GetTexture("6");
        break;
    case 7:
        texture = ResourceManager::GetTexture("7");
        break;
    case 8:
        texture = ResourceManager::GetTexture("8");
        break;
    }
}

int Tile::getNum() const {
    return num;
}

bool Tile::isOpen() const {
    return !hidden;
}

bool Tile::isFlagged() const {
    return flagged;
}

void Tile::setNum(int num)
{
    this->num = num;   
}