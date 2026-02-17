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

void *get_char(s_mem_stack_list *stack_calc) {
    char* c;
    scanf("%c", c);
    assert(c != NULL);
    printf("Pressed: %s\n", c);
    return c;
}

void *parse_char(s_mem_stack_list *stack_calc) {
    char *c = get_char(stack_calc);

    int ascii_value = *(int*) c;
    if (ascii_value >= 48 && ascii_value <= 51) {
        parse_int(c);
    } else if (ascii_value == 47 || ascii_value == 42 || ascii_value == 43 || ascii_value == 45) {
        parse_op(c);
    } else{
        printf("Operación no definida\n");
        get_char_op(stack_calc);
    }
}

// Chequea si lo que se recibió fue int o char
int *parse_int(char *selected_char, s_mem_stack_list *stack_calc) {
    int selected_number;
    // Conversor de ASCII a decimal
    while (*selected_char != '\0' && *selected_char != '\r' && *selected_char != '\n') {
        assert((*selected_char) >= '0' && (*selected_char) <= '9');
        selected_number *= 10;
        selected_number += (*selected_char) - '0';
        void *character_block = push(stack_calc);
        char *selected_char = (char *)character_block;
        *selected_char = c;
        selected_char++;
    }
    return selected_number;
}

int *parse_op(char* selectec_char) {}

void run_calc() {

}