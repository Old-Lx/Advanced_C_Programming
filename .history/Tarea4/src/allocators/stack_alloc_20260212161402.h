#ifndef STACK_ALLOC_H
#define STACK_ALLOC_H

#include <stdint.h>
#include <stddef.h>

#define MEMORY_POOL_SIZE 1024

// Apuntador de espacios de memoria
typedef struct s_mem_block {
    size_t next;
   size_t prev;
} s_mem_block;

// Bloque de memoria
typedef struct s_mem_free_list {
    s_mem_block freeList;
    unsigned char pool[MEMORY_POOL_SIZE]; // Se usó el ejemplo de memory pool para reservar estáticamente la memoria que se use
} s_mem_free_list;

void* allocate();

void* free();

void* push();

void* pop();

#endif