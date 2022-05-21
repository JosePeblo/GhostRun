g++ -c main.cpp -Isrc/clases -Isrc/include 
g++ main.o -o main -Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system
.\main.exe