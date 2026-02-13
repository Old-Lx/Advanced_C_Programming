#ifndef STACK_ALLOC_H
#define STACK_ALLOC_H

#include <stdint.h>

#define HEAP_SIZE 1024

typedef struct s_mem_ptr {
    uint8_t next;
   uint8_t prev;
} s_mem_ptr;

typedef struct s_mem_block {
    
} s_mem_block;

#endif