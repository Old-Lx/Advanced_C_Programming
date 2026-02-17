#include <stdint.h>

#include "./allocators/stack_alloc.h"
#include "./allocators/linear_alloc.h"

/*
    EP5801 - Tarea 4 - Lartrax
    Memory allocators - Linear and Stack

    Hay que implementar ambos y hacer una calculadora RPN con el de stack

    Información útil sobre memory allocation: https://www.geeksforgeeks.org/c/static-and-dynamic-memory-allocation-in-c/\
    
    Como inspiración para esta implementación me basé en las clases y los siguientes links:

    https://dev.to/trish_07/writing-your-own-memory-pool-allocator-in-c-17l3
    https://github.com/dimonomid/umm_malloc/blob/master/umm_malloc.c
    https://github.com/johanofverstedt/stack_allocator/blob/master/sa.c
    https://dev.to/jonahgoldsmith/temporary-allocations-in-cc-oi8
    https://medium.com/@sgn00/high-performance-memory-management-arena-allocators-c685c81ee338
*/

int main() {
    s_mem_linear_list linear_pool;
    s_mem_stack_list stack_pool;

    init_memory(&linear_pool);
    init_stack(&stack_pool);
}