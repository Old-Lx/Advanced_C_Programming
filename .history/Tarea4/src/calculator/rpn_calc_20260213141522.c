#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

#include "../allocators/stack_alloc.h"

// Para un ejemplo de RPN Calculator puedes ver https://breder.org/rpn-calculator
// Acá usaré el stack que definí para ejecutar la calculadora
s_mem_stack_list stack_calc;