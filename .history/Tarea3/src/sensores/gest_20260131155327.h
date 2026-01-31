#ifndef GEST_H
#define GEST_H
#include <stdint.h>

#include "sensor.h" 

// Union explanation: https://www.geeksforgeeks.org/c/c-unions/
// Bitfield explanation: https://www.geeksforgeeks.org/c/bit-fields-c/

// Estructura con los gestos definidos
typedef struct S_GESTURE {
    // la unión permite leer distintos tipos de datos en un sólo espacio de memoria, cuando lo usé acá me
    uint8_t tap:1; // el bitfield limita los bits a usar de un espacio allocated de memoria, este usa el primer bit
    uint8_t double_tap:1; // este usa el segundo bit
    uint8_t haptic_press:1;
    uint8_t saved:5; // Acá se reservan
} s_gesture;

// Usamos la signature para definir la función correspondiente
sensor_print gest_print(uint8_t * selected_gest);

// Un enum para verificar el gesto
enum GESTURE_TYPE {
    tap = 1 << 0,
    double_tap = 1 << 1,
    haptic_press = 1 << 2,
};

#endif