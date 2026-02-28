#ifndef PARTICLE_H
#define PARTICLE_H

#include <stdint.h>
#include <stdbool.h>

#include "../vector/vector.h"
#include "particle_common.h"

/* Modelo de sistema de partículas (un apuntador de partículas que por su analogía a la implementación de vector decidí llamar así) */

/* Crear y eliminar apuntador a partícula */
// Crea un nuevo apuntador de partículas
s_particle* particle_new(size_t item_size, e_vector_type pos_type, e_vector_type vel_type, size_t initial_size);
// Elimina apuntador de partículas
void particle_delete(s_particle* particle);

/* Inserción, consulta y borrado de elementos */
// Agrega partícula al apuntador de partículas en su última posición O(1)
bool particle_push(s_particle* particle, s_vector* pos, s_vector* vel); // Posición y velocidad en lugar de la data en vector.h
// Saca la última partícula del apuntador de partículas O(1)
bool particle_pop(s_particle* particle, void* storage);
// Agrega partícula al apuntador de partículas en la posición position O(n)
bool particle_insert(s_particle* particle, s_vector* pos, s_vector* vel, size_t position);
// Muestra la partícula en la posición position O(1)
void* particle_at(s_particle* particle, size_t position);
// Elimina partícula del apuntador de partículas en la posición position O(n)
bool particle_erase(s_particle* particle, size_t position);  

/* Extra operations */
// Muestra el tamaño del apuntador de partículas
size_t particle_size(s_particle* particle);
// Vacía el apuntador de partículas
bool particle_empty(s_particle* particle);

#endif
