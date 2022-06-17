# TC1030_Jose_Pablo

## _Lame ghost game_ 
Es un simulador de caminar en 2d donde escapas de un fantasma, 
tienes que sobrevivir hasta que te toque el fantasma o te aburras de la falta de gameplay y objetivos.
En el caso de que este te toque: EL JUEGO SE VA A CERRAR!!! (Puede que el fantasma spawnee al lado tuyo, una disculpa)

La modelación de este proyecto incluye clases para el juego, las entidades y el mapa.

## Código
La función main solo crea el objeto juego y entra a un bucle de actualización y renderizado hasta que la ventana cierre. **Mi código** y clases modeladas se encuentran en los archivos del folder:

>/src/clases


## Dependencias
La interfaz gráfica está manejada por la librería de 
[SFML](https://www.sfml-dev.org/) e incluye las dependencias y códigos fuente 
para que sea compilada, estas se encuentran como los ".dll" en el main y código en las siguientes rutas:

>/src/include/SFML\
>/src/lib


## Para compilar y correr el programa
El comando para compilar y enlazar todos los archivos se encuentra en formato ".bat" para Windows y en ".sh" para linux.
### En windows
Compilar y correr el programa en el directorio del main con los siguientes comandos de g++:
```
g++ main.cpp ./src/clases/Game.cpp ./src/clases/Enemy.cpp ./src/clases/Entity.cpp ./src/clases/Map.cpp ./src/clases/Player.cpp -Isrc/clases/ -Isrc/include -o main -Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system

.\main.exe
```
ó alternativamente correr usando el ".bat"
```
./run.bat
```
### En linux
En linux es necesario incluir previamente la librería de SFML con los siguientes comandos.
```
sudo apt-get install libsfml-dev
```
Posteriormente se puede correr el programa con los siguientes comandos 
```
g++ main.cpp ./src/clases/Game.cpp ./src/clases/Enemy.cpp ./src/clases/Entity.cpp ./src/clases/Map.cpp ./src/clases/Player.cpp -Isrc/clases/ -Isrc/include -o main -lsfml-graphics -lsfml-window -lsfml-system
./main
```
### En MacOS 
Para no utilizar Xcode se recomienda instalar SFML desde el gestor de paquetes Homebrew con los siguientes comandos desde la terminal.
```
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
brew install sfml
```
Una vez instalados los paquetes, se compila y corre el código en su directorio con los siguientes comandos.
```
g++ main.cpp -I ./src/clases/ -I /usr/local/Cellar/sfml/2.5.1_1/ -o main -lsfml-graphics -lsfml-window -lsfml-system
./main
```
#### Consideraciones
* Es probable que se solicite autorizar a la terminal el permiso de obtener input de teclado, el programa solo la usa para mover al jugador con las flechas.
* Es probable que la ruta en la que se instale SFML cambie, en ese caso usar el comando `brew info sfml` y reeplazar la ruta en el comando de compilado.


