#pragma once
#include <vector>

#include <SFML/Graphics.hpp>

#include "Tile.h"

class Grid {
public:
    Grid(unsigned int size_x, unsigned int size_y, float offset_X, float offset_Y);
    Grid();
    void draw(SpriteRenderer& renderer);

    int openCell(int x, int y);
    void setFlag(int x, int y);

    int getMines();
    int getFlags();

    void openAll();
    

private:
    std::vector<std::vector<std::unique_ptr<Tile>>> grid;

    bool isOnRange(int x, int y);
    void setNums();
    int checkBombs(int x, int y);
    void checkWonState();
};


