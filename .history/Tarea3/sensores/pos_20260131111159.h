#ifndef POS_H
#define POS_H
#include <stdint.h>

#include "sensor.h"

typedef struct position {
    uint16_t pos_x: 1;
    uint16_t pos_y: 1;
    uint16_t pos_z: 1;
};

print_sensor gest_print(uint8_t* selected_gest);

#endif 