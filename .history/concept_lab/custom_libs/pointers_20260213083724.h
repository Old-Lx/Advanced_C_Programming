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

// Acá es donde se complica la cosa, porque estamos apuntando a un lugar de memoria que tiene dos apuntadores distintos
void test(s_ptr_eg *struct_ptr_example, s_ptr_eg ptr_example_dereferenced) {
    my_number = 7;
    my_number_ptr = &my_number;
    my_character = 'e';
    my_character_ptr = &my_character;

    // Las dos siguientes líneas son análogas en operación, la diferencia es que con la primera estamos guardando
    // el espacio de memoria que apunta a una estructura que contiene los ptr definidos
    // Mientras que en la segunda línea sólo estamos tomando una variable común de la estructura
    // el operador -> dereferencia el apuntador a su izquierda y provee los miembros del struct al que se apuntó
    // por otro lado, el operador . en este contexto accede a los miembros de una variable struct definida
    struct_ptr_example->first_element = my_number_ptr;
    ptr_example_dereferenced.first_element = my_number_ptr;

    // ocurre análogo con los char
    struct_ptr_example->second_element[0] = my_character_ptr; // acá hay otra capa de complejidad porque el segundo elemento lo definimos como un array de characters
    ptr_example_dereferenced.second_element[0] = my_character_ptr;
}

#endif