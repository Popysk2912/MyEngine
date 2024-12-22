#include "shapeRenderer.h"

ShapeRenderer::ShapeRenderer(const Shader &shader)
{
    this->shader = shader;
    this->initRenderData();
}

ShapeRenderer::~ShapeRenderer()
{
    glDeleteVertexArrays(1, &this->VAO);
    glDeleteBuffers(1, &this->VBO);
}

void ShapeRenderer::DrawLine(glm::vec2 start, glm::vec2 end, glm::vec3 color, float width)
{
    shader.Use();

    glLineWidth(width);
    float vertices[] = {
        start.x, start.y, 0.0f,
        end.x, end.y, 0.0f
    };


    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_DYNAMIC_DRAW);

    constexpr auto model = glm::mat4(1.0f);

    shader.SetMatrix4("model", model);
    shader.SetVector3f("Color", color);

    glBindVertexArray(VAO);
    glDrawArrays(GL_LINES, 0, 2);
    glBindVertexArray(0);

    glLineWidth(1.0f);
}

void ShapeRenderer::initRenderData()
{

    glGenVertexArrays(1, &this->VAO);
    glGenBuffers(1, &this->VBO);

    glBindVertexArray(this->VAO);
    glBindBuffer(GL_ARRAY_BUFFER, this->VBO);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}
