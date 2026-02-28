#ifndef PARTICLE_COMMON_H
#define PARTICLE_COMMON_H

#include <stddef.h>

#include "../vector/vector_common.h"

// Definimos el struct particle que consta de dos vectores, uno para posición y otro para velocidad
typedef struct S_PARTICLE {
    s_vector* pos;
    s_vector* vel;

    size_t item_size;
    size_t pos_size;
    size_t vel_size;
    size_t item_count;
    size_t item_used;
    e_vector_type pos_type;
    e_vector_type vel_type;

    void* memory;
} s_particle;

#endif