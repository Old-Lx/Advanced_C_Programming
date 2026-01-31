#include <stdio.h>

#include "pos.h"

s_position * ptr_position;

void position_print() {
    printf("x: %u, y: %u, z: %u \n", ptr_position->pos_x, ptr_position->pos_y, ptr_position->pos_z);
}

sensor_print pos_print(uint8_t * current_position ) {
    ptr_position = (s_position*) current_position;

    return position_print;
}