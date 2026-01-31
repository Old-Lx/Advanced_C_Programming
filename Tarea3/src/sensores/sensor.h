#ifndef SENSOR_H
#define SENSOR_H

// Identificación de cada sensor
enum sensor_type {
    pos_id = 0xB7,
    gest_id = 0xA7,
}; // Ejemplos de enums: https://www.geeksforgeeks.org/c/enumeration-enum-c/

typedef void (*sensor_print)();

#endif