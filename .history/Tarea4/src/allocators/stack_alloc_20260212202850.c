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
            // Si estamos en el índice 0, no guardamos nada en prev
            if (i) {
                current->prev = (s_mem_block *)((unsigned char *)current - sizeof(s_mem_block));
            }
            current->next = (s_mem_block *)((unsigned char *)current + sizeof(s_mem_block));
            current = current->next;
        }

        current->next = NULL; // El último bloque será un nullptr para tener idea de dónde finaliza la alocación
    }
}

void *free(s_mem_free_list *pool, void *ptr) {
    s_mem_block *block = (s_mem_block *) ptr; // El void *ptr será el bloque que estaremos liberando
    block->next = pool->freeList; // El bloque que sigue al que estamos liberando lo apuntamos a la lista de bloques libres
    pool->freeList = block; // Ahora añadimos el bloque en sí a la lista de libres
}

void *push(s_mem_free_list *pool, s_mem_block *block) {
    // Chequeamos si hay memoria disponible
    if (!pool->freeList) {
        printf("¡Se agotó la memoria!\n");
        return NULL;
    }
    block->next = pool->freeList->next;
    pool->freeList = block;\
    pool->freeList->prev = block;
}

void *pop(s_mem_free_list *pool) {
    if (pool->freeList) {
        s_mem_block *block = pool->freeList;
        pool->freeList = block->next;
        return (void *) block;
    }
}