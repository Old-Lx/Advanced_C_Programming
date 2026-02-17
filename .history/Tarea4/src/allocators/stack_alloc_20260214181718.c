#include <stdint.h>
#include <stddef.h>
#include <stdio.h>

#include "stack_alloc.h"


void* init_stack(s_mem_stack_list *pool) {
    pool->freeList = (s_mem_block_stack *)pool->pool; // Ponemos todo el pool en la lista
    s_mem_block_stack *current = pool->freeList; // se usará para iterar y que se divida exactamente en los bloques definidos

    int block_qtty = STACK_POOL_SIZE / sizeof(s_mem_block_stack); // Cantidad de bloques en nuestro stack
    pool->qtty = 0;

    // creamos la lista
    for (int i = 0; i < block_qtty - 1; i++) {
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
    return NULL;
}

void *stack_free(s_mem_stack_list *pool) {
    pool->freeList = NULL;
    pool->qtty = 0;
    return NULL;
}

void *push(s_mem_stack_list *pool) {
    // Chequeamos si hay memoria disponible
    if (!pool->freeList) {
        printf("¡Se agotó la memoria!\n");
        return NULL;
    }
    s_mem_block_stack *block = pool->freeList; // Apartamos el espacio para nuestro bloque
    pool->freeList = block->next; // direccionamos el espacio libre al siguiente espacio
    block->next = NULL; // Le quitamos la referencia al próximo bloque para ser consistente con las operaciones de stack

    return (void *) block;
}

void *pop(s_mem_stack_list *pool) {
    if (!pool || !pool->freeList) { // Chequeamos que el pool esté reservado y que tenga espacio
        return NULL;
    }

    s_mem_block_stack *block = pool->freeList->prev; // guardaremos el bloque que se quitará del pool
    s_mem_block_stack *next_block = pool->freeList->next->prev; // Si no hago esto, por alguna razón el apuntador next se perdía
    pool->freeList = pool->freeList->prev; // Restauramos el espacio libre de la memoria
    pool->freeList->next = next_block;
    return (void *) block;
}