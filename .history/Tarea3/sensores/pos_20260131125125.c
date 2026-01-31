#include <stdio.h>

#include "pos.h"

s_position * ptr_position;

sensor_print position_print(uint8_t * current_position ) {
    printf("x: %u, y: %u, z: %u \n");
}