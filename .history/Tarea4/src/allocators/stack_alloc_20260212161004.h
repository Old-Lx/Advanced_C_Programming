#ifndef STACK_ALLOC_H
#define STACK_ALLOC_H

#include <stdint.h>

#define MEMORY_POOL_SIZE 1024

// Apuntador de espacios de memoria
typedef struct s_mem_block {
    uint8_t next;
   uint8_t prev;
} s_mem_block;

// Bloque de memoria
typedef struct s_mem_free_list {
    s_mem_block freeList;
    unsigned char pool[MEMORY_POOL_SIZE]; // Se usó el ejemplo de memory pool para reservar estáticamente la memoria que se use
} s_mem_free_list;

#endif