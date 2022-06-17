/**
 * Lame ghost game
 * José Pablo Martínez Valdivia
 * A01275676
 * 17/06/2022
 * 
 * Este programa es un simulador de caminar en 2d donde escapas de un fantasma, 
 * tienes que sobrebibir hasta que te toque el fantasma o te aburras de la falta
 * de gameplay y objetivos.
 * En el caso de que este te toque: EL JUEGO SE VA A CERRAR!!!  
 * La modelación de este proyecto incluye clases para el juego, las entidades y 
 * el mapa.
 * 
 * La interfás gráfica corre gracias a SFML que es una librería multiplataforma
 * que simplifica la taréa del renderizado y las ventanas. La introducción a 
 * esta librería viene del canal de Suraj Sharma y su curso básico de juegos en 
 * SFML https://www.youtube.com/playlist?list=PL6xSOsbVA1eb_QqMTTcql_3PdOiE928up
 * 
 * Link a la documentación de SFML https://www.sfml-dev.org/documentation/2.5.1/
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
    std::cout<<"Que mal, has muerto\n";
    std::cin.get();
    return 0;
}