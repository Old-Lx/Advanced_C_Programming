#include <stdint.h>
#include <stdio.h>

#include "./allocators/stack_alloc.h"
#include "./allocators/linear_alloc.h"

/*
    EP5801 - Tarea 4 - Lartrax
    Memory allocators - Linear and Stack

    NOTA IMPORTANTE: Implementé mi propio stack y linear allocs porque no había descargado las arenas y me confundí

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

    // Allocating
    void *linear_block = linear_allocate(&linear_pool);
    void *stack_block1 = push(&stack_pool);

    // storing variables
    int *my_number = (int *)linear_block;
    *my_number = 7;

    int *my_other_number = (int *)stack_block1;
    *my_other_number = 8;

    printf("Linear block: %p\n", linear_block);
    // printf("Linear block: %p\n", my_number); Análogo a la línea anterior, es decir, mismo bloque de memoria
    printf("Linear block number: %d\n\n", *my_number);

    printf("Stack block: %p\n", stack_block1);
    // printf("Stack block: %p\n", my_other_number); Es análogo a la línea anterior
    printf("Stack block number: %d\n", *my_other_number);
    printf("pop the block: %p\n", pop(&stack_pool));
    printf("Next free: %p\n", stack_pool.freeList);
}