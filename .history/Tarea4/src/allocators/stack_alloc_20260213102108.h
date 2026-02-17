#ifndef STACK_ALLOC_H
#define STACK_ALLOC_H

#include <stdint.h>
#include <stddef.h>

#define STACK_POOL_SIZE 96 // (96 bytes porque esa es la ram aproximada de un PIC16)

// Apuntador de espacios de memoria
typedef struct s_mem_block_stack {
    s_mem_block_stack *next;
   s_mem_block_stack *prev;
} s_mem_block_stack;

// Bloque de memoria
typedef struct s_mem_stack_list {
    s_mem_block_stack *freeList;
    unsigned char pool[STACK_POOL_SIZE]; // Se usó el ejemplo de STACK pool para reservar estáticamente la memoria que se use
} s_mem_stack_list;

void* init_stack(s_mem_stack_list *pool);

void* free(s_mem_stack_list *pool, void *ptr);

void* push(s_mem_stack_list *pool, s_mem_block_stack *block);

void* pop(s_mem_stack_list *pool);

#endif