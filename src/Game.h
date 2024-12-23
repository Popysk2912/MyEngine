#ifndef GAME_H
#define GAME_H

#include "Engine/Program.h"
#include "Grid.h"

class Game final : public Program
{
public:
    Game(int width, int height);

private:
    Grid grid;
    Texture2D frameT;

protected:
    void init() override;

    void loadResources() override;

    void update(float deltaTime) override;

    void render() override;
};

#endif
