#ifndef SENSOR_H
#define SENSOR_H

enum e_sensor_type {
    POS = 0xB7,
    GEST = 0xA7,
};

typedef int (*print_sensor)();

#endif 