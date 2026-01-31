#ifndef GEST_H
#define GEST_H
#include <stdint.h>

typedef struct gest {
    union {
        uint8_t tap:1;
        uint8_t double_tap:1;
        uint8_t haptic_press:1;
        uint8_t saved:5;
    };
};

#endif