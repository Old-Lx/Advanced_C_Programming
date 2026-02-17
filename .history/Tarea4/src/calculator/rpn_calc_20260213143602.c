#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

#include "../allocators/stack_alloc.h"

// Para un ejemplo de RPN Calculator puedes ver https://breder.org/rpn-calculator
// Acá usaré el stack que definí para ejecutar la calculadora
void *init_calc() {
    s_mem_stack_list *stack_calc;

    init_stack(stack_calc);

    return (void *)stack_calc;
}

void *get_char_op() {
    char* c = readline("> ");
    assert(c != NULL);
    printf("Pressed: %s\n", c);
}