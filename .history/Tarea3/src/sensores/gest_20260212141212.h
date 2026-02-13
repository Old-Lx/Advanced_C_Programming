#ifndef GEST_H
#define GEST_H
#include <stdint.h>

#include "sensor.h" 

// Union explanation: https://www.geeksforgeeks.org/c/c-unions/
// Bitfield explanation: https://www.geeksforgeeks.org/c/bit-fields-c/
// Nota: si se usa bitfields, union dentro de struct hace que todos los datos se escriban
// desde la misma posición de memoria, si es al revés, usan el mismo espacio de memoria, pero
// no se reescribe desde el bit inicial, por lo que cada bitfield tendrá su espacio fijo con el offset respectivo


// Estructura con los gestos definidos
typedef union S_GESTURE {
    // la unión permite leer distintos tipos de datos en un sólo espacio de memoria, cuando lo usé acá me ponía los 3 bits como
    // el mismo bit, el profesor me dijo que poniéndolo afuera se evita esto y funciona como se necesita acá
    struct {
        uint8_t tap:1; // el bitfield limita los bits a usar de un espacio allocated de memoria, este usa el primer bit
        uint8_t double_tap:1; // este usa el segundo bit
        uint8_t haptic_press:1;
        uint8_t saved:5; // Acá se reservan
    };
} s_gesture;

// Usamos la signature para definir la función correspondiente
sensor_print gest_print(uint8_t * selected_gest);

// Un enum para verificar el gesto, no lo terminé de implementar y recurrí a if-else
enum GESTURE_TYPE {
    tap = 1 << 0,
    double_tap = 1 << 1,
    haptic_press = 1 << 2,
};

#endif