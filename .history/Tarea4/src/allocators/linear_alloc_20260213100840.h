#ifndef STACK_ALLOC_H
#define STACK_ALLOC_H

#include <stdint.h>
#include <stddef.h>

#define LINEAR_POOL_SIZE 96 // (96 bytes porque esa es la ram aproximada de un PIC16)

// Apuntador de espacios de memoria
typedef struct s_mem_block {
   s_mem_block *next;
} s_mem_block;

// Bloque de memoria
typedef struct s_mem_list {
    s_mem_block *start_block;
    s_mem_block *freeList;
    unsigned char pool[LINEAR_POOL_SIZE]; // Se usó el ejemplo de linear pool para reservar estáticamente la memoria que se use
} s_mem_list;

void *init_memory(s_mem_list *pool);

void* allocate(s_mem_list *pool);

void* deallocate(s_mem_list *pool);

void *destructor(s_mem_list *pool);

#endif