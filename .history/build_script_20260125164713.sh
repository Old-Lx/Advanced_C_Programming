Project="Tarea1" # Aquí va el nombre del proyecto a compilar, en general, acá se usará el directorio de cada tarea
Debug="$Project/debug.mk"
Build="$Project/Makefile"

echo "Clear the Debug mode compilation"
if [ -f $Debug ]; then make -f $Project/debug.mk clean; else echo "No hay make para el debug"; fi;

echo "Build debug mode"
if [ -f $Debug ]; then make -f debug.mk; fi;

echo "Clear the Prod mode compilation"
if [ -f $Build ]; then make -f Makefile clean; else echo "No se encontróel archivo Makefile"; fi;

echo "Build Prod mode"
if [ -f $Build ]; then make -f Makefile; fi;