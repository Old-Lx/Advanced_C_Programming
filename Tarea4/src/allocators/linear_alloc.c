#include <stdint.h>
#include <stddef.h>
#include <stdio.h>

#include "linear_alloc.h"

void *init_memory(s_mem_linear_list *pool) {
    pool->freeList = (s_mem_block_linear *) pool->pool; // La dirección de la lista libre será la misma dirección de todo el pool en principio
    s_mem_block_linear *current = pool->freeList; // Guardamos la dirección inicial de la lista libre

    int pool_division = LINEAR_POOL_SIZE / sizeof(s_mem_block_linear);

    pool->start_block = current; // Guardamos la posición del primer elemento

    // Es acá donde se crea la lista como tal
    for (int i = 0; i < pool_division - 1; i++) { // Se divide el segmento de memoria estático en bloques
        current->next = (s_mem_block_linear *)((unsigned char *)current + sizeof(s_mem_block_linear)); // Se asigna el espacio del próximo bloque        
        current = current->next; // seleccionamos el próximo bloque y repetimos hasta asignar una dirección a cada bloque
        
    }

    current->next = NULL; // Cuando agotamos el pool, apuntamos a null
}

void *linear_allocate(s_mem_linear_list *pool) {
    if (!pool->freeList) { // Chequeamos que freeList sea distinto de NULL
        printf("No hay más memoria\n");
        return NULL;
    }

    // se reserva el primer bloque
    s_mem_block_linear *block = pool->freeList;
    pool->freeList = block->next; // Ahora el bloque libre es el siguiente

    return (void *) block;
}

// Libera el primer bloque de memoria pero sin poder reutilizarlo
void *deallocate(s_mem_linear_list *pool) {
    if (pool->start_block) { // Si hay un start block distinto de null, podemos vaciar la memoria
        s_mem_block_linear *temp = pool->start_block->next; // Seguimos la convención de arenas y cambiamos nuestro start al siguiente bloque
        pool->start_block = NULL; // Borramos el contenido de start_block
        pool->start_block = temp; // recuperamos el apuntador
    }
}

// libera toda la memoria
void *destructor(s_mem_linear_list *pool) {
    init_memory(pool);
}