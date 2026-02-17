#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

#include "../allocators/stack_alloc.h"
#include "rpn_calc.h"

s_mem_stack_list stack_calc;
    
// Para un ejemplo de RPN Calculator puedes ver https://breder.org/rpn-calculator
// Acá usaré el stack que definí para ejecutar la calculadora
void *init_calc() {
    init_stack(&stack_calc);

    return &stack_calc;
}

// Acá leemos el número u operación
void *get_char(char *c) {
    printf("> ");
    scanf("%s", c);
    assert(c != NULL); // Una aserción es similar a un if pero con motivos de debugging y diseño
    return NULL;
}

bool is_a_number(char *c) {
    printf("hello2");
    for (int i = 0; i < strlen(c); i++) {
        char checker = c[0];
        printf("%c", checker);
    }
}

void *parse_char(s_mem_stack_list *stack_calc) {
    char c[2] ; // Un buffer que admite hasta 3  caracteres
    get_char(c);
    printf("Pressed: %s\n", c);

    if (strcmp(*c, "+") || strcmp(*c, "-") || strcmp(*c, "*") || strcmp(*c, "/") || strcmp(*c, "%")) {
        printf("hello");
        parse_op(c);
    } else if (is_a_number(c)) {
        

    } else{
        printf("Operación no definida\n");
        parse_char(stack_calc);
    }
}

// Chequea si lo que se recibió fue int o char
int *parse_int(char *selected_char, s_mem_stack_list *stack_calc) {
    int selected_number;
    // Conversor de ASCII a decimal
    while (selected_char != '\0' && selected_char != '\r' && selected_char != '\n') {
        assert((selected_char) >= '0' && (selected_char) <= '9');
        selected_number *= 10;
        selected_number += (int) selected_char - '0';
        
        void *character_block = push(stack_calc);
        int *selected_number = (int *)character_block;
        selected_number;
        
        selected_char++;
    }
    return (int *)selected_number;
}

int *parse_op(char* selectec_char) {}

// Ejecución de la calculadora
void *run_calc() {
    s_mem_stack_list *stack_calc = init_calc();

    parse_char(stack_calc);

    return NULL;
}