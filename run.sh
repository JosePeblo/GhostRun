#!/usr/bin/bash
g++ main.cpp ./src/clases/Game.cpp ./src/clases/Enemy.cpp ./src/clases/Entity.cpp ./src/clases/Map.cpp ./src/clases/Player.cpp -Isrc/clases/ -Isrc/include -o main -lsfml-graphics -lsfml-window -lsfml-system
./main