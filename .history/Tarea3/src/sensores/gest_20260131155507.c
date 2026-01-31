#include <stdio.h>

#include "gest.h"

s_gesture * ptr_gesture;

// Verificación e impresión del gesto
void gesture_print() {
    if (ptr_gesture->tap) {
        printf("Tap\n");
    } else if (ptr_gesture->double_tap) {
        printf("Double Tap\n");
    } else if (ptr_gesture->haptic_press) {
        printf("Haptic Press\n");
    }
    
}

// Por si alguien no se sabe los format specifiers como yo https://www.tutorialspoint.com/cprogramming/c_format_specifiers.htm
// Es necesario retornar una void function debido al typedef que hicimos en sensor.h
sensor_print gest_print(uint8_t * selected_gest) {
    printf("selected %u \n", *selected_gest);
    ptr_gesture = (s_gesture*) selected_gest;
    printf("tap %u double tap %u haptic %u \n",ptr_gesture->tap, ptr_gesture->double_tap, ptr_gesture->haptic_press);
    return gesture_print;
}
