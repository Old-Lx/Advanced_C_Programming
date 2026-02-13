#include <stdint.h>
#include <stddef.h>

#include "stack_alloc.h"

void* allocate(s_mem_free_list *pool) {
    // Revisa si pool está vacío para inicilizarlo
    if (!pool) {
        pool->freeList = (s_mem_block *)pool->pool; // Ponemos todo el pool en la lista
        s_mem_block *current = pool->freeList; // se usará para iterar y que se divida exactamente en los bloques definidos

        // creamos la lista
        for (int i = 0; i < (MEMORY_POOL_SIZE / sizeof(s_mem_block)) - 1; i++) {
            // Si estamos en el índice 0, no uardamos nada en prev
            if (i) {
                current->prev = (s_mem_block *)((unsigned char *)current - sizeof(s_mem_block));
            }
            current->next = (s_mem_block *)((unsigned char *)current + sizeof(s_mem_block));
            current = current->next;
        }

        current->next = NULL; // El último bloque será un nullptr para tener idea de dónde finaliza la alocación
    }

    // Chequeamos si queda espacio en el pool reservado
    if (!pool->freeList) {
        printf("¡Se agotó la memoria!\n");
        return NULL;
    }

    // Buscamos el primer espacio de memoria disponible
    s_mem_block *block = pool->freeList;
    pool->freeList = block->next; // movemos el apuntador de la lista de espacios libres

    return (void *)block;
}

void *free(s_mem_free_list *pool, void *ptr) {
        // Si el pool está vacío, no hace falta liberarlo
        if (pool) {
            // Iteramos sobre todos los elementos Pendiente porque podría dar problemas
            for (int i = 0; i < (MEMORY_POOL_SIZE / sizeof(s_mem_block)) - 1; i++) {
                s_mem_block *block = (s_mem_block *) ptr;
                block->next = pool->freeList;
                block = block->next;
            }
        }
}

void *push(s_mem_free_list *pool, s_mem_block *block) {
    block = pool->freeList;
    pool->freeList = block->next;

    return (void *) block;
}

void *pop(s_mem_free_list *pool) {
    s_mem_block *block = pool->freeList;
}