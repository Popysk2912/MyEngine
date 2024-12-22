#include "Sprite.h"

Box::Box(const float x, const float y, const float width, const float height): x(x), y(y), width(width), height(height) { }

float Box::left() const { return x; }

float Box::right() const { return x + width; }

float Box::top() const { return y + height; }

float Box::bottom() const { return y; }

bool Box::intersects(const Box &other) const { return x < other.right() && right() > other.left() && y < other.top() && top() > other.bottom(); }

glm::vec2 Box::center() const { return {x + width / 2.0f, y + height / 2.0f}; }



Sprite::Sprite() :
texture(Texture2D()), position(glm::vec2(0, 0)), size(glm::vec2(0, 0)), rotate(0), color(glm::vec3(0, 0, 0)),
velocity(glm::vec2(0, 0)), collision(false) { }

Sprite::Sprite(const Texture2D &texture, const glm::vec2 position, const glm::vec2 size, const GLfloat rotate, const glm::vec3 color) :
texture(texture), position(position), size(size), rotate(rotate), color(color), velocity(glm::vec2(0, 0)), collision(false) { }

Texture2D Sprite::getTexture() const { return texture; }

glm::vec2 Sprite::getPosition() const { return position; }

glm::vec2 Sprite::getSize() const { return size; }

glm::vec2 Sprite::getVelocity() const { return velocity; }

GLfloat Sprite::getRotate() const { return rotate; }

glm::vec3 Sprite::getColor() const { return color; }

bool Sprite::getCollision() const { return collision; }

void Sprite::setTexture(const Texture2D &texture) { this->texture = texture; }

void Sprite::setPosition(const glm::vec2 &position) { this->position = position; }

void Sprite::setSize(const glm::vec2 &size) { this->size = size; }

void Sprite::setVelocity(const glm::vec2 &velocity) { this->velocity = velocity; }

void Sprite::setRotate(const GLfloat rotate) { this->rotate = rotate; }

void Sprite::setColor(const glm::vec3 &color) { this->color = color; }

void Sprite::setCollision(const bool collision) { this->collision = collision; }

Box Sprite::getBoundingBox() const { return Box(position.x, position.y, size.x, size.y); }

void Sprite::draw(SpriteRenderer& renderer) { renderer.DrawSprite(texture, position, size, rotate, color); }
