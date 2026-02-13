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
            current = pool->start_block->next;
        } else {
            current = current->next; // seleccionamos el próximo bloque y repetimos hasta asignar una dirección a cada bloque
        }
    }

    current->next = NULL; // Cuando agotamos el pool, apuntamos a null
}

void *allocate(s_mem_list *pool) {
    if (!pool->freeList) { // Chequeamos que freeList sea distinto de NULL
        printf("No hay más memoria\n");
        return NULL;
    }

    // se reserva el primer bloque
    s_mem_block *block = pool->freeList;
    pool->freeList = block->next; // Ahora el bloque libre es el siguiente

    return (void *) block;
}

void *deallocate(s_mem_list *pool) {
    if (pool->start_block) { // Si hay un start block distinto de null, podemos vaciar la memoria
        s_mem_block *temp = pool->start_block->next; // Seguimos la convención de arenas y cambiamos nuestro start al siguiente bloque
        pool->start_block = NULL; // Borramos el contenido de start_block
        pool->start_block = temp; // recuperamos el apuntador
    }
}

void *destructor(s_mem_list *pool) {
    for (int i = 0; (MEMORY_POOL_SIZE / sizeof(s_mem_block)) - 1; i++) { // Se divide el segmento de memoria estático en bloques
        deallocate(&pool);
    }
}