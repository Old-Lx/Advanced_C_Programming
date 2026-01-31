#ifndef POS_H
#define POS_H
#include <stdint.h>

#include "sensor.h"

typedef struct position {
    uint16_t pos_x;
};

print_sensor gest_print(uint8_t* selected_gest);

#endif 