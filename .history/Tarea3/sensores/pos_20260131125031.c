#include <stdio.h>

#include "pos.h"

s_position * ptr_position;

sensor_print position_print(uint8_t *  ) {
    switch (*selected_gest)
    {
    case tap:
        return printf("Tap\n");
        break;
    case double_tap:
        return printf("Double tap\n");
        break;
    case haptic_press:
        return printf("Haptic press\n");
        break;

    default:
        break;
    }
}