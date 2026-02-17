#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../allocators/stack_alloc.h"
#include "rpn_calc.h"

s_mem_stack_list stack_calc;
    
// Para un ejemplo de RPN Calculator puedes ver https://breder.org/rpn-calculator
// Acá usaré el stack que definí para ejecutar la calculadora

// Inicializamos el stack en la variable que predefinimos para que sea el stack de la calculadora
void *init_calc() {
    init_stack(&stack_calc);

    return &stack_calc;
}

// Acá leemos el número u operación
void *get_char(char *c) {
    printf("> ");
    scanf("%s", c);
    assert(c != NULL); // Una aserción es una especie de if
    return NULL;
}

// Con esta función verifico que la string contenga un número sin caracteres raros
bool is_a_number(char *c) {
    for (int i = 0; i < (int)strlen(c); i++) {
        char checker = c[i];
        if (checker < '0' || checker > '9') {
            return false;
        }
    }
    return true;
}

// No era necesaria esta función, pero para que se vea más homogéneo xd
bool is_an_op(char *c) {
    if (!(strcmp(c, "+") && strcmp(c, "-") && strcmp(c, "*") && strcmp(c, "/") && strcmp(c, "%%"))) {
        return true;
    }
    return false;
}

// Procesamos lo que recibió el buffer, se llama char, pero al final usé string, sólo que me dió flojera cambiar el nombre de la función xd
void *parse_char(s_mem_stack_list *stack_calc) {
    char c[4] ; // Un buffer que admite hasta 3 caracteres para dígitos
    get_char(c);
    printf("Pressed: %s\n", c);

    // Verificamos si lo que recibimos fue una operación, un número o un caracter que no nos interesa
    if (is_an_op(c)) {
        parse_op(c, stack_calc);
    } else if (is_a_number(c)) {
        parse_int(c, stack_calc);
    } else{
        printf("Operación no definida\n");
        parse_char(stack_calc);
    }
}

void push_int(int selected_number, s_mem_stack_list *stack_calc) {
    printf("stack_calc %p\n", stack_calc->freeList);
    void *stack_number = push(stack_calc); // Creamos el bloque en el stack
    int *ptr_selected_number = (int *)stack_number; // Creamos un apuntador para guardar el número // Nótese que stack_number y ptr_selected_number ahora apuntan al mismo espacio que está en nuestra stack_calc
    *ptr_selected_number = selected_number; // Hacemos que el contenido del apuntador sea el mismo que del número  
    printf("stack_calc %p\n", stack_calc->freeList);
}

// Registra el número recibido en el stack
int *parse_int(char *selected_char, s_mem_stack_list *stack_calc) {
    int selected_number = atoi(selected_char); // Convertimos la string a int
    push_int(selected_number, stack_calc);  
    return NULL; // No es necesario retornar, sólo que la función está definida así en el .h me da flojera modificarlo, además de que aumenta mi tasa de errores
}

int which_op(char *c) {
    if (!(strcmp(c, "+"))) {
        return ADD;
    } else if (!strcmp(c, "-")) {
        return SUB;
    } else if (!(strcmp(c, "*"))) {
        return MUL;
    } else if (!(strcmp(c, "/"))) {
        return DIV;
    } else if (!(strcmp(c, "%%"))) {
        return REM;
    }
}

// Ejecuta la operación con los dos números anteriores
int *parse_op(char* selectec_char, s_mem_stack_list *stack_calc) {
    int *first_number_block = (int *)pop(stack_calc);
    int *second_number_block = (int *)pop(stack_calc);
    
    if (first_number_block && second_number_block) {
        switch (which_op(selectec_char)) {
            case ADD:
                int sum = (*first_number_block) + (*second_number_block);
                push_int(sum, stack_calc);
                break;
            case SUB:
                int sub = (*first_number_block) - (*second_number_block);
                push_int(sub, stack_calc);
                break;
            case MUL:
                int mul = (*first_number_block) * (*second_number_block);
                push_int(mul, stack_calc);
                break;
            case DIV:
                int div = (*first_number_block) / (*second_number_block);
                push_int(div, stack_calc);
                break;
            case REM:
                int rem = (*first_number_block) % (*second_number_block);
                push_int(rem, stack_calc);
                break;
            default:
                break;
        }
    } else if (first_number_block) {
        switch (which_op(selectec_char)) {
            case SUB:
                int opposite_sign = (*first_number_block) * (-1);
                push_int(opposite_sign, stack_calc);
                break;
            default:
                printf("La operación no es aplicable para un sólo número\n");
                break;
        }
    } else {
        printf("No hay números suficientes para esa operación\n");
    }
}

// Ejecución de la calculadora
void *run_calc() {
    s_mem_stack_list *stack_calc = init_calc();

    while (true) {
        parse_char(stack_calc);
    }

    return NULL;
}