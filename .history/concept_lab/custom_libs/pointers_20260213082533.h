#ifndef POINTERS_H
#define POINTERS_H

// eg = example given or exemplai gratia (del latín pero mal traducido)
typedef struct s_ptr_eg {
    int *first_element;
    char *second_element[60];
} s_ptr_eg;

int my_number;
int *my_number_ptr;

char my_character;
char *my_character_ptr;

s_ptr_eg *struc_ptr_example;

#endif