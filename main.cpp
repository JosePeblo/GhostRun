/**
 * /////////////pon el nombre del proyecto//////////////////////
 * José Pablo Martínez Valdivia
 * A01275676
 * 10/06/2022
 * 
 * Este programa es un juego en 2d 
 * 
 * 
 */
#include <iostream>
#include <time.h>
#include <Game.h>

int main()
{
    // Iniciar semilla random
    srand(time(NULL));
    // Engine
    Game game;

    // Game loop
    while(game.getWindowIsOpen())
    {
        // Update
        game.onUpdate();
        // Render
        game.onRender();
    }
    return 0;
}