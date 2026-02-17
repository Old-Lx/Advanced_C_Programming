#ifndef STACK_ALLOC_H
#define STACK_ALLOC_H

#include <stdint.h>
#include <stddef.h>

#define STACK_POOL_SIZE 32768 // La HP 50g  tiene 512KB de ram

// Apuntador de espacios de memoria
typedef struct s_mem_block_stack {
   struct s_mem_block_stack *next;
   struct s_mem_block_stack *prev;
} s_mem_block_stack;

// Bloque de memoria
typedef struct s_mem_stack_list {
    s_mem_block_stack *freeList;
    unsigned char pool[STACK_POOL_SIZE]; // Se usó el ejemplo de STACK pool para reservar estáticamente la memoria que se use
    int qtty;
} s_mem_stack_list;

void* init_stack(s_mem_stack_list *pool);

void* stack_free(s_mem_stack_list *pool);

void* push(s_mem_stack_list *pool);

void* pop(s_mem_stack_list *pool);

#endif