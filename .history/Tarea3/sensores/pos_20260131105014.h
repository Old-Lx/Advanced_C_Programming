#ifndef POS_H
#define POS_H
#include <stdint.h>

#include "sensor.h"

typedef struct position {
    union {
        uint8_t tap:1;
        uint8_t doble_tap:1;
        uint8_t haptic_pres:1;
        uint8_t saved_for_anything:5;        
    };
};

print_sensor gest_print(uint8_t* selected_gest);

typedef struct position {};

#endif 