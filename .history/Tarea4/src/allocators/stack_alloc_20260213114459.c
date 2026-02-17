#include <stdint.h>
#include <stddef.h>
#include <stdio.h>

#include "stack_alloc.h"


void* init_stack(s_mem_stack_list *pool) {
    // Revisa si pool está vacío para inicilizarlo
    if (!pool) {
        pool->freeList = (s_mem_block_stack *)pool->pool; // Ponemos todo el pool en la lista
        s_mem_block_stack *current = pool->freeList; // se usará para iterar y que se divida exactamente en los bloques definidos

        // creamos la lista
        for (int i = 0; i < (STACK_POOL_SIZE / sizeof(s_mem_block_stack)) - 1; i++) {
            // Si estamos en el índice 0, no guardamos nada en prev
            if (i) {
                current->prev = (s_mem_block_stack *)((unsigned char *)current - sizeof(s_mem_block_stack));
            } else {
                current->prev = NULL;
            }
            current->next = (s_mem_block_stack *)((unsigned char *)current + sizeof(s_mem_block_stack));
            current = current->next;
        }

        current->next = NULL; // El último bloque será un nullptr para tener idea de dónde finaliza la alocación
    }
}

void *stack_free(s_mem_stack_list *pool, void *ptr) {
    s_mem_block_stack *block = (s_mem_block_stack *) ptr; // El void *ptr será el bloque que estaremos liberando
    block->next = pool->freeList; // El bloque que sigue al que estamos liberando lo apuntamos a la lista de bloques libres
    pool->freeList = block; // Ahora añadimos el bloque en sí a la lista de libres
}

void *push(s_mem_stack_list *pool) {
    // Chequeamos si hay memoria disponible
    if (!pool->freeList) {
        printf("¡Se agotó la memoria!\n");
        return NULL;
    }
    s_mem_block_stack *block = pool->freeList;
    pool->freeList = pool->freeList->next;
}

void *pop(s_mem_stack_list *pool) {
    if (!pool || !pool->freeList) { // Chequeamos que el pool esté reservado y que tenga espacio
        return NULL;
    }

    s_mem_block_stack *block = pool->freeList->prev; // guardaremos el bloque que se quitará del pool
    pool->freeList = pool->freeList->prev; // Restauramos el espacio libre de la memoria
    return (void *) block;
}