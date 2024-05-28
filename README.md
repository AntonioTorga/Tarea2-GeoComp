Para compilar abrir terminal en directorio build. 
Correr cmake
```bash
cmake ..
```
En Windows, abrimos la solución creada por Cmake en Visual Studio 2022. Luego, desde Visual Studio compilamos.
Para ejecutar ingresamos a Build/Debug:
```bash
cd Build/Debug
```
Y ejecutamos el archivo main.exe
```bash
./main.exe
```
El resultado mostrado en pantalla son las pruebas ejecutadas con Cassert.
Para mayor claridad puede revisarse el código.

El archivo main es el archivo de tests.
Los archivos \*.cpp que no sean main.cpp están vacios, ya que, la implementación se encuentra en los archivos \*.h