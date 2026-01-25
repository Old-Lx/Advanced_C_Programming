#!/bin/bash
Project="Tarea1"
Debug="$Project/debug.mk"
Build="$Project/Makefile"

# Limpieza y compilación del debug
if [ -f "$Debug" ]; then 
    make -f "$Debug" clean && make -f "$Debug"
else 
    echo "No se encontró $Debug"
fi

# Limpieza y compilación del proyecto
if [ -f "$Build" ]; then 
    cd "$Project" && make clean && make
else 
    echo "No se encontró el archivo Makefile en $Project"
fi