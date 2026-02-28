#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "../vector/vector.h"
#include "particle_common.h"

/* Como verán, la implementación acá es análoga a la de vector con algunos casos, por lo tanto, podemos llamar al apuntador de partículas "Sistema de Partículas" y queda brutal */

// Crea un nuevo apuntador de partículas
s_particle* particle_new(size_t pos_size, size_t vel_size, e_vector_type pos_type, e_vector_type vel_type, size_t initial_size) {
    
    size_t item_size = pos_size + vel_size;

    // Si el tamaño inicial es cero no tiene sentido la creación
    if(!initial_size){
        return NULL;
    }

    // Alocamos la memoria WOOOOO
    s_particle* particle = (s_particle*) malloc(sizeof(s_particle));

    // Si la memoria no aguanta la locura, no se puede hacer nada
    if(!particle){
        return NULL;
    }

    // Definimos parámetros críticos de las características del struct particle
    particle->item_count = initial_size;
    particle->item_used = 0;
    particle->pos_type = pos_type;
    particle->vel_type = vel_type;

    // En esta parte definimos el tamaño del vector posición y velocidad
    switch(pos_type){
        // Chequeamos los tipos predefinidos para la posición, así nos aseguramos de su tamaño
        case u8:
        case u16:
        case u32:
        case u64:
        case f32:
        case f64:
            particle->pos_size = 0x0f & pos_type; // Tamaño del vector de posición
            particle->item_size = 0x0f & pos_type; // Con una máscara añadimos el tamaño de la posición al tamaño de nuestro item
            break;

        // Si estamos trabajando con otro tipo de dato
        default:
            particle->pos_size = pos_size;
            particle->item_size = pos_size;
            break;
    };

    // La posición es quien define si tenemos partícula, sin posición, no hay derivada de la posición, ergo, no velocidad
    if (pos_type) {
        switch(vel_type){
            // Chequeamos los tipos predefinidos para la velocidad
            case u8:
            case u16:
            case u32:
            case u64:
            case f32:
            case f64:
                particle->vel_size =  0x0f & vel_type; // Tamaño del vector velocidad
                particle->item_size += 0x0f & vel_type; // Con una máscara sumamos el tamaño de la velocidad
                break;

            // Si estamos trabajando con otro tipo de dato
            default:
                particle->vel_size = vel_size;
                particle->item_size += vel_size;
                break;
        };
    }

    // Reservamos la memoria necesaria para nuestra partícula
    particle->memory = malloc(item_size * initial_size);

    // Nos aseguramos de que la memoria no tenga nada raro
    memset(particle->memory, 0x00, initial_size);

    // Si no pudimos reservar suficiente memorias, retornamos NULL
    if(!particle->memory){
        free(particle);
        return NULL;
    }

    return particle;
}
// Elimina apuntador de partículas
void particle_delete(s_particle* particle) {
    
    // Verificamos que haya partícula para borrar, es decir, que el apuntador no sea NULL
    if(particle){

        // Liberamos la memoria si está resercada
        if(particle->memory){
            free(particle->memory);
        }

        // Liberamos el apuntador de partícula
        free(particle);
    }
}

// Agrega partícula al apuntador de partículas en su última posición O(1)
bool particle_push(s_particle* particle, s_vector* pos, s_vector* vel) {
    
    // Evitemos posibles seg fault
    if(!(particle && particle->memory && pos && vel)){
        return false;
    }

    // Si no hay espacio suficiente para la nueva partícula, reservamos más
    if(particle->item_count == particle->item_used){
        particle->item_count <<= 1;

        // realocamos la memoria por si la posición del pointer cambia, hay que evitar seg faults
        particle->memory = realloc(particle->memory, particle->item_count);
    }

    // Hacemos casting de la referencia para liberar la memoria a usar
    void* reference_ptr = (void*)((uint8_t*)particle->memory + (particle->item_used * (particle->item_size)));

    // Acá es que varía respecto a la implementación de vector porque necesitamos copiar tanto posición como velocidad
    if (particle->item_size == particle->pos_size + particle->vel_size) {
        memcpy(reference_ptr, pos, particle->pos_size);
        memcpy(reference_ptr, vel, particle->vel_size);
    } else {
        // Si el tamaño del item es distinto al tamaño de la posición más el tamaño de la velocidad, hicimos algo mal
        return false;
    }
    particle->item_used++;

    return true;
} // Posición y velocidad en lugar de la data en vector.h

// Saca la última partícula del apuntador de partículas O(1)
bool particle_pop(s_particle* particle, void* storage) {

    // Evitemos posibles seg fault
    if(!(particle && particle->memory && storage)){
        return false;
    }

    // Si no hay partículas en nuestra lista
    if(!particle->item_count){
        return false;
    }

    // Tomamos el último elemento de nuestro apuntador a partículas
    void* reference_ptr = (void*)((uint8_t*)particle->memory + ((particle->item_used - 1) * (particle->item_size)));

    // El tamaño del item debe ser la suma de posición y velocidad
    if (particle->item_size == particle->pos_size + particle->vel_size) {
        // Copiamos la partícula
        memcpy(storage, reference_ptr, particle->item_size);

        /* zero the memory*/
        memset(reference_ptr,0x00, particle->item_size);

        particle->item_used--;
    } else {
        return false;
    }

    return true;
}
// Agrega partícula al apuntador de partículas en la posición position O(n)
bool particle_insert(s_particle* particle, s_vector* pos, s_vector* vel, size_t position) {
    
    // Evitemos posibles seg fault
    if(!(particle && particle->memory && pos && vel)){
        return false;
    }

    // // Si la posición está por encima de la última posición usada, no se puede proceder
    if(position > particle->item_used){
        return NULL;
    }

    // Reservar más memoria si no hay suficiente
    if(particle->item_count == particle->item_used){
        particle->item_count <<= 1;
        particle->memory = realloc(particle->memory, particle->item_count << 1);
    }

    // Movemos todos las las partículas desde la posición donde queremos poner nuestra partícula
    for(size_t index = particle->item_used + 1; index > position; index--){ 
        void* destination_reference_ptr = (void*)((uint8_t*)particle->memory + (index * (particle->item_size)));
        void* copy_reference_ptr = (void*)((uint8_t*)particle->memory + ((index - 1) * (particle->item_size)));
        memcpy(destination_reference_ptr, copy_reference_ptr, particle->item_size);
        memset(copy_reference_ptr, 0x00, particle->item_size);
    }

    // Tomamos la referencia de la posición donde queremos poner la data
    void* reference_ptr = (void*)((uint8_t*)particle->memory + (position * (particle->item_size)));

    // Igual que antes, nos aseguramos que el tamaño de la posición más la velocidad no exceda el tamaño de la partícula
    if (particle->item_size == particle->pos_size + particle->vel_size) {
        memcpy(reference_ptr, pos, particle->pos_size);
        memcpy(reference_ptr, vel, particle->vel_size);
        particle->item_used++;
    } else {
        return false;
    }

    return true;
}

// Muestra la partícula en la posición position O(1)
void* particle_at(s_particle* particle, size_t position) {
    
    // Verificamos la memoria
    if(!(particle && particle->memory)){
        return NULL;
    }
    
    // Si es un elemento del apuntador de partículas sin uso, no podemos hacer nada
    if(position >= particle->item_used){
        return NULL;
    }

    // Retornamos la referencia al elemento
    return (void*) ((uint8_t*)particle->memory + (position * (particle->item_size)));
}

// Elimina partícula del apuntador de partículas en la posición position O(n)
bool particle_erase(s_particle* particle, size_t position) {


    // Verificamos memoria
    if(!(particle && particle->memory)){
        return false;
    }

    // Verificamos que la posición esté ocupada
    if(position >= particle->item_used){
        return false;
    }

    // Limpiamos la posición deseada y luego  reajustamos los apuntadores
    for(size_t index = position; index < particle->item_used; index++){ 
        void* copy_reference_ptr = (void*)((uint8_t*)particle->memory + ((index + 1) * (particle->item_size)));
        void* destination_reference_ptr = (void*)((uint8_t*)particle->memory + (index * (particle->item_size)));
        memset(destination_reference_ptr, 0x00, particle->item_size);
        memcpy(destination_reference_ptr, copy_reference_ptr, particle->item_size);
    }

    particle->item_used--;

    return true;
}  

// Muestra el tamaño del apuntador de partículas
size_t particle_size(s_particle* particle) {

    if(!(particle && particle->memory)) {
        return 0;
    }

    return particle->item_count;
}
// Vacía el apuntador de partículas
bool particle_empty(s_particle* particle) {

}