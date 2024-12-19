#include <iostream>
#include "Game.h"

int main()
{
    #ifdef NDEBUG
    std::cout << "Build type: Release" << std::endl;
    #else
    std::cout << "Build type: Debug" << std::endl;
    #endif

    Game game(800, 600);
    game.run();

    return 0;
}