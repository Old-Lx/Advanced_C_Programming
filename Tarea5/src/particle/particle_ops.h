#ifndef PARTICLE_OPS_H
#define PARTICLE_OPS_H

#include <stddef.h>
#include <stdarg.h>

#include "particle_common.h"

// Implementación de funciones variádicas en https://www.geeksforgeeks.org/c/variadic-functions-in-c/

// Genera un vector con n partículas, recibe pointers en los argumentos después de la n
s_vector* n_particles_vector(size_t n, ...); // Donde n es el número de partículas

// Distancia entre partículas en valor absoluto
size_t particle_absolute_distance(s_vector* pos1, s_vector* pos2);

// Distancia entre partículas en forma vectorial
void particle_vectorial_distance(s_vector* vector_a, s_vector* vector_b, s_vector* result);


#endif