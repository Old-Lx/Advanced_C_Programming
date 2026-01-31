#include <stdio.h>

#include "pos.h"

s_position * ptr_position;

sensor_print position_print(uint8_t * current_position ) {
    printf("x: %u, y: %u, z: %u \n", ptr_position->pos_x, ptr_position->pos_y, ptr_position->pos_z);
}