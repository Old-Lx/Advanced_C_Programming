#include <stdio.h>

#include "gest.h"

s_gesture * ptr_gesture;

// Verificación e impresión del gesto
void gesture_print() {
    uint8_t * selected_gest;
    switch (*selected_gest) {
        case tap:
            printf("Tap\n");
            break;
        case double_tap:
            printf("Double tap\n");
            break;
        case haptic_press:
            printf("Haptic press\n");
            break;

        default:
            break;
    }
}

// Por si alguien no se sabe los format specifiers como yo https://www.tutorialspoint.com/cprogramming/c_format_specifiers.htm
// Es necesario retornar una void function debido al typedef que hicimos en sensor.h
sensor_print gest_print(uint8_t * selected_gest) {
    ptr_gesture = (s_gesture*) selected_gest;
    printf("tap %u double tap %u haptic %u \n", ptr_gesture->data.double_tap);
    return gesture_print;
}
