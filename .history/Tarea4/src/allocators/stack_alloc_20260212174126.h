#ifndef STACK_ALLOC_H
#define STACK_ALLOC_H

#include <stdint.h>
#include <stddef.h>

#define MEMORY_POOL_SIZE 96 // (96 bytes porque esa es la ram aproximada de un PIC16)

// Apuntador de espacios de memoria
extern typedef struct s_mem_block {
    s_mem_block *next;
   s_mem_block *prev;
} s_mem_block;

// Bloque de memoria
extern typedef struct s_mem_free_list {
    s_mem_block *freeList;
    unsigned char pool[MEMORY_POOL_SIZE]; // Se usó el ejemplo de memory pool para reservar estáticamente la memoria que se use
} s_mem_free_list;

extern void* allocate(s_mem_free_list *pool);

extern void* free(s_mem_free_list *pool, void *ptr);

extern void* push(s_mem_free_list *pool, s_mem_block *block);

extern void* pop(s_mem_free_list *pool);

#endif