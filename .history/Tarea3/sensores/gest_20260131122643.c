#include <stdio.h>

#include "gest.h"

s_gesture * ptr_gesture;

// Por si alguien no se sabe los format specifiers como yo https://www.tutorialspoint.com/cprogramming/c_format_specifiers.htm
sensor_print gest_print(uint8_t * selected_gest ) {
    switch (gesture_type)
    {
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
};

