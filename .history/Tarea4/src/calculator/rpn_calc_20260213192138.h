#ifndef RPN_CALC_H
#define RPN_CALC_H

#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

#include "../allocators/stack_alloc.h"

#define ADD 1
#define SUB 2
#define MUL 3
#define DIV 4
#define REM 5
#define SQR 6
#define POT 7
#define SIN 8
#define COS 9

void *init_calc();

void *get_char(s_mem_stack_list *stack_calc);

void *parse_char(s_mem_stack_list *stack_calc);

int *parse_int(char *selected_char);

int *parse_op(char* selectec_char);

void *run_calc();


#endif