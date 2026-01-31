#ifndef POS_H
#define POS_H
#include <stdint.h>

#include "sensor.h" 

typedef struct S_POSITION {
    uint16_t pos_x;
    uint16_t pos_y;
    uint16_t pos_z;
} s_position;


sensor_print pos_print(uint8_t * current_position);

#endif