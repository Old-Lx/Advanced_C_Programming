#include <stdint.h>
#include <stddef.h>

#include "stack_alloc.h"

void* allocate(s_mem_free_list *pool) {

    // Revisa si pool está vacío para inicilizarlo
    if (!pool) {
        pool->freeList = (s_mem_block *)pool->pool; // Ponemos todo el pool en la lista
        s_mem_block *current = pool->freeList;
    }

}