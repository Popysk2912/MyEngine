#include "Grid.h"

Grid::Grid(unsigned int size_x, unsigned int size_y, float offset_X, float offset_Y)
{
    grid.resize(size_x);
    for (unsigned int x = 0; x < size_x; x++) {
        for (unsigned int y = 0; y < size_y; y++) {
            grid[x].emplace_back(std::make_unique<Tile>(32 * x, 32 * y, offset_X, offset_Y));
        }
    }
    this->setNums();
}

Grid::Grid() : Grid(0, 0,0,0) {  }

bool Grid::isOnRange(int x, int y)
{
    return (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size());
}

int Grid::getFlags()
{
    int count = 0;
    for (const auto& row : grid) {
        for (const auto& tile : row) {
            if (tile->isFlagged())
            {
                count++;
            }
        }
    }
    return count;
}

void Grid::setNums()
{
    for (unsigned int x = 0; x < grid.size(); x++)
    {
        for (unsigned int y = 0; y < grid[x].size(); y++)
        {
            if (grid[x][y]->getNum() == -1)
            {
                continue;
            }
            else
            {
                int num = checkBombs(x, y);
                grid[x][y]->setNum(num);
                grid[x][y]->setImage();
            }
        }
    }
}

int Grid::checkBombs(int x, int y)
{
    int count = 0;
    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            if (i == 0 && j == 0)
            {
                continue;
            }
            int newX = x + i;
            int newY = y + j;
            if (newX >= 0 && newX < grid.size() && newY >= 0 && newY < grid[0].size())
            {
                if (grid[newX][newY]->getNum() == -1)
                {
                    count++;
                }
            }
        }
    }
    return count;
}

void Grid::checkWonState()
{
    int count = 0;
    for (const auto& row : grid) 
    {
        for (const auto& tile : row) 
        {
            if (tile->getNum() == -1 && tile->isFlagged())
            {
                count++;
            }
        }
    }
    if (count == this->getMines())
    {
        delete this;
    }
}

int Grid::openCell(int x, int y)
{
    if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size())
    {
        return 0;
    }
    if (grid[x][y]->isOpen())
    {
        return 0;
    }
    if (grid[x][y]->isFlagged())
    {
        return 0;
    }
    grid[x][y]->open();
    if (grid[x][y]->getNum() != 0)
    {
        return grid[x][y]->getNum();
    }
    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            
            if (i == 0 && j == 0)
            {
                continue;
            }
            openCell(x + i, y + j);
        }
    }
    return 0;
}

void Grid::setFlag(int x, int y)
{
    if (this->isOnRange(x, y) && !grid[x][y]->isOpen())
    {
        grid[x][y]->flag();
    }
    checkWonState();
}

void Grid::openAll()
{
    for (const auto& row : grid) {
        for (const auto& tile : row) {
            tile->open();
        }
    }
}

int Grid::getMines()
{
    int count = 0;
    for (const auto& row : grid) {
        for (const auto& tile : row) {
            if(tile->getNum() == -1)
            {
                count++;
            }
        }
    }
    return count;
}

void Grid::draw(SpriteRenderer& renderer)
{
    
    for (const auto& row : grid) {
        for (const auto& tile : row) {
            tile->draw(renderer);
        }
    }
}