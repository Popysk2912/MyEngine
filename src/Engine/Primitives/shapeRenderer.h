#ifndef SHAPE_RENDERER_H
#define SHAPE_RENDERER_H

#include <glad/glad.h>
#include "../shader.h"


class ShapeRenderer
{
public:
    explicit ShapeRenderer(const Shader& shader);
    ~ShapeRenderer();

    void DrawLine(glm::vec2 start, glm::vec2 end, glm::vec3 color, float width);

private:
    Shader       shader;
    unsigned int VAO{}, VBO{};

    void initRenderData();
};



#endif