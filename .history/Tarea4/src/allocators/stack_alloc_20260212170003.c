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