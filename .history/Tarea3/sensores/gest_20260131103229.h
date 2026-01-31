#ifndef GEST_H
#define GEST_H
#include <stdint.h>

#include "sensor.h"

typedef struct gesture {
    union {
        uint16_t tap;
        uint16_t doble_tap;
        uint16_t haptic_pres;
        uint16_t saved_for_anything;        
    };
};

#endif 