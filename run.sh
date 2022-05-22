#!/usr/bin/bash
g++ main.cpp -Isrc/clases -Isrc/include -o main -lsfml-graphics -lsfml-window -lsfml-system
./main