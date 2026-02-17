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

void *get_char_op(s_mem_stack_list *stack_calc) {
    char* c = readline("> "); // Tomamos el caracter
    assert(c != NULL);
    printf("Pressed: %s\n", c);

    void *character_block = push(stack_calc);
    char *selected_char = (char *)character_block;
    *selected_char = c;
}

int *check_int(char *selected_char) {
    int selected_number;
    while (*selected_char != '\0' && *selected_char != '\r' && *selected_char != '\n') {
        assert((*selected_char) >= '0' && (*selected_char) <= '9');
        selected_number *= 10;
        selected_number += (*selected_char) - '0';
        selected_char++;
    }
}