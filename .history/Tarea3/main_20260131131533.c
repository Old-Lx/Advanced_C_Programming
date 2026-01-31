#include <stddef.h>

#include "sensores/sensor.h"
#include "sensores/gest.h"
#include "sensores/pos.h"

int main() {
    uint8_t sensor_read[] = {
        0xB7,
    }; 

    sensor_print print_data;

    switch (sensor_read[0]) {
        case pos_id:
            print_data = pos_print(sensor_read + 1);
            break;
        case gest_id:
            print_data = gest_print(sensor_read + 1);
            break;
            
        default:
            return -1;
            break;
    }

    if (print_data != NULL) {}
}