#pragma once
#include <glad/glad.h>
#include <iostream>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "SpriteRenderer.h"
#include "texture.h"

using Vector2f = glm::vec2;

struct Box
{
    float x, y;
    float width, height;


    Box(float x = 0, float y = 0, float width = 0, float height = 0)
        : x(x), y(y), width(width), height(height) { }
    float right() const { return x + width; }

    float bottom() const { return y + height; }

    bool intersects(const Box& other) const
    {
        return x < other.right() && right() > other.x && y < other.bottom() && bottom() > other.y;
    }
    Vector2f center() const
    {
        return Vector2f(x + width / 2.0f, y + height / 2.0f);
    }
};


class Sprite
{
public:
	Sprite(Texture2D texture, glm::vec2 position, glm::vec2 size, GLfloat rotate, glm::vec3 color);
    Sprite() : texture(Texture2D()), position(glm::vec2(0, 0)), size(glm::vec2(0, 0)), rotate(0), color(glm::vec3(0, 0, 0)) { }
	void draw(SpriteRenderer& renderer);

    Texture2D getTexture() const { return texture; }
    glm::vec2 getPosition() const { return position; }
    Box getBoundingBox() const;
    glm::vec2 getSize() const { return size; }
    GLfloat getRotate() const { return rotate; }
    glm::vec3 getColor() const { return color; }

    void setTexture(const Texture2D& texture) { this->texture = texture; }
    void setPosition(const glm::vec2& position) { this->position = position; }
    void setSize(const glm::vec2& size) { this->size = size; }
    void setRotate(GLfloat rotate) { this->rotate = rotate; }
    void setColor(const glm::vec3& color) { this->color = color; }
    void printProperties();

	
private:
	Texture2D texture;
	glm::vec2 position;
	glm::vec2 size;
	GLfloat rotate;
	glm::vec3 color;
};