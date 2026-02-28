#include <math.h>

#include "particle_ops.h"
#include "../asm/avx/avx.h"
#include "../vector/vector.h"
#include "../vector/vector_math.h"

// Genera un vector con n partículas
s_vector* n_particles_vector(size_t n, ...) {
    
    va_list particles;
    va_start(particles, n);

    s_vector* particles_vector = vector_new(sizeof(void *), sizeof(void *), n);
    
    for (int i = 0; i < n; i++) {
        vector_push(particles_vector, va_arg(particles, void *));
    }
    va_end(particles);

    return particles_vector;
}

// Distancia entre partículas en valor absoluto
size_t particle_absolute_distance(s_vector* pos1, s_vector* pos2) {
    
    // La distancia en forma vectorial es por definición la resta de vectores
    s_vector* distance_vector = vector_new(sizeof(void *), sizeof(void *), 1);

    vector_sub(pos1, pos2, distance_vector);

    // Por definición, el valor absoluto de la distancia entre dos vectores es la raíz cuadrada de la suma de las restas de cada una de sus coordenadas al cuadrado
    size_t distance = sqrt(pow(*(size_t *)vector_at(distance_vector, 0), 2) + pow(*(size_t *)vector_at(distance_vector, 1), 2) + pow(*(size_t *)vector_at(distance_vector, 0), 2));

    return distance;
}
