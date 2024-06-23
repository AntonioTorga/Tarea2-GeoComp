Para clonar e incluir el submódulo Google Test
```bash
git clone --recurse-submodules <URL-DE-REPO>
```

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
El resultado mostrado en pantalla son las pruebas de tiempo utilizadas para crear ANALISIS.pdf
Para correr los tests hechos con Google Test abrimos la consola en el directorio Build/test/Debug y ejecutamos GeoTests.exe
```bash
cd Build/test/Debug
./GeoTests.exe
```
Los resultados de estos tests apareceran en la consola.