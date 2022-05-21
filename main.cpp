#include <iostream>
#include <Game.h>

int main()
{
    // Engine
    Game game;

    // Game loop
    while(game.getWindowIsOpen())
    {
        // Update
        game.onUpdate();
        // Render
        game.onRender();
            // Color(r,g,b,transparency)
    }
    return 0;
}