#ifndef POS_H
#define POS_H
#include <stdint.h>

#include "sensor.h"

typedef struct S_POSITION {
    uint16_t pos_x: 1;
    uint16_t pos_y: 1;
    uint16_t pos_z: 1;
} s_position;

print_sensor pos_print(uint8_t* current_position);

#endif 