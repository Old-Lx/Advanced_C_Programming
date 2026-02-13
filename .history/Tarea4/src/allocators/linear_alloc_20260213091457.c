#include <stdint.h>
#include <stddef.h>

#include "linear_alloc.h"

void *init_memory(s_mem_list *pool) {
    pool->freeList = (s_mem_block *) pool->pool; // La dirección de la lista libre será la misma dirección de todo el pool en principio
    s_mem_block *current = pool->freeList; // Guardamos la dirección inicial de la lista libre

    // Es acá donde se crea la lista como tal
    for (int i = 0; (MEMORY_POOL_SIZE / sizeof(s_mem_block)) - 1; i++) { // Se divide el segmento de memoria estático en bloques
        current->next = (s_mem_block *)((unsigned char *)current + sizeof(s_mem_block)); // Se asigna el espacio del próximo bloque
        if (!i) {
            pool->start_block = current; // Guardamos la posición del primer elemento
        }
        current = current->next; // seleccionamos el próximo bloque y repetimos hasta asignar una dirección a cada bloque
    }
}