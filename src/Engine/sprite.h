#pragma once
#include <glad/glad.h>

#include <glm/gtc/matrix_transform.hpp>

#include "SpriteRenderer.h"
#include "texture.h"

struct Box
{
    float x, y;
    float width, height;

    explicit Box(float x = 0, float y = 0, float width = 0, float height = 0);

	float left() const;
    float right() const;

	float top() const;
    float bottom() const;

    bool intersects(const Box& other) const;

    glm::vec2 center() const;
};


class Sprite
{
public:
	Sprite(const Texture2D &texture, glm::vec2 position, glm::vec2 size, GLfloat rotate, glm::vec3 color);
    Sprite();

	void draw(SpriteRenderer& renderer);

    Texture2D getTexture() const;

	glm::vec2 getPosition() const;

	Box getBoundingBox() const;

    glm::vec2 getSize() const;

	glm::vec2 getVelocity() const;

	GLfloat getRotate() const;

	glm::vec3 getColor() const;

	bool getCollision() const;

	void setTexture(const Texture2D& texture);

	void setPosition(const glm::vec2& position);

	void setSize(const glm::vec2& size);

	void setVelocity(const glm::vec2& velocity);

	void setRotate(GLfloat rotate);

	void setColor(const glm::vec3& color);

	void setCollision(bool collision);
	
private:
	Texture2D texture;
	glm::vec2 position;
	glm::vec2 size;
	GLfloat rotate;
	glm::vec3 color;
	glm::vec2 velocity;
	bool collision;
};