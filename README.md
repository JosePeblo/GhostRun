# TC1030_Jose_Pablo
## _nombre por definir_ 
Es un RPG inspirado en "Pokemon" y la serie de juegos para nintendo DS de 
"Mario & Luigi". El proyecto pretende presentar un mapa interactivo con enemigos
y un sistema de batallas por turnos.

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
```
./run.bat
```
En linux es necesario incluir previamente la librería de SFML con los siguientes comandos.
### En linux
```
sudo apt-get install libsfml-dev
chmod +x run.sh
./run.sh
```
