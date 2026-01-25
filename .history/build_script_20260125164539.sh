Project="Tarea1" # Aquí va el nombre del proyecto a compilar, en general, acá se usará el directorio de cada tarea
Debug="$Project/debug.mk"
Build="$Project/Makefile"

echo "Clear the Debug mode compilation"
if [ -f $Debug ]; then make -f $Project/debug.mk clean; else echo "No hay make para el debug"; fi;

echo "Build debug mode"
make -f debug.mk

echo "Clear the Prod mode compilation"
make -f Makefile clean

echo "Build Prod mode"
make -f Makefile