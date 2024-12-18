#ifndef GAME_H
#define GAME_H

#include "Engine/Program.h"

class Game final : public Program
{
public:
    // Constructor
    Game(int width, int height) : Program(width, height) {}

protected:
    void init() override
    {
        const GLubyte* vendor = glGetString(GL_VENDOR);
        const GLubyte* renderer = glGetString(GL_RENDERER);
        const GLubyte* version = glGetString(GL_VERSION);
        const GLubyte* glslVersion = glGetString(GL_SHADING_LANGUAGE_VERSION);
        std::cout << renderer << "; ";
        std::cout << "OpenGL Version: " << version << "; ";
        std::cout << "GLSL Version: " << glslVersion << ";\n";
        loadResources();
    }
    void loadResources() override
    {

    }
    void update(float deltaTime) override
    {

    }
    void render() override
    {

    }
};

#endif
