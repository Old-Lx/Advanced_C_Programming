#ifndef STACK_ALLOC_H
#define STACK_ALLOC_H

#include <stdint.h>

typedef struct s_mem_ptr {
    uint8_t next;
   uint8_t prev;
} s_mem_pt;

typedef struct s_mem_block {
    
} s_mem_block;

#endif