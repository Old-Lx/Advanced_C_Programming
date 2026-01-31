#include <stdio.h>

#include "pos.h"

s_position * ptr_position;

// Impresión de la posición
void position_print() {
    printf("x: %u, y: %u, z: %u \n", ptr_position->pos_x, ptr_position->pos_y, ptr_position->pos_z);
}

// Definición del pointer y return de la función para evitar segmentation fault
sensor_print pos_print(uint8_t * current_position ) {
    ptr_position = (s_position*) current_position;

    return position_print;
}