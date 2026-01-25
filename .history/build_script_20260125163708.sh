PROJECT="Tarea1" # Aquí va el nombre del proyecto a compilar, en general, acá se usará el directorio de cada tarea

echo "Clear the Debug mode compilation"
make -f debug.mk clean

echo "Build debug mode"
make -f debug.mk

echo "Clear the Prod mode compilation"
make -f Makefile clean

echo "Build Prod mode"
make -f Makefile