#ifndef POS_H
#define POS_H
#include <stdint.h>

#include "sensor.h" 

typedef struct S_POSITION {
    union { // la unión permite leer distintos tipos de datos en un sólo espacio de memoria 
        uint8_t tap:1; // el bitfield guarda un "field" (campo) del tamaño de la variable escogida
        uint8_t double_tap:1;
        uint8_t haptic_press:1;
        uint8_t saved:5; // Acá se reservan
    };
} s_position;


sensor_print pos_print(uint8_t * current_position);

#endif