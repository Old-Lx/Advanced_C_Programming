/*  EP5801 Programación Avanzada en C
    Tarea 1
*/

#include <stdio.h>
#include <float.h>

char title[] = 
"  ____      _            _           _                 \n"
" / ___|__ _| | ___ _   _| | __ _  __| | ___  _ __ __ _\n"
"| |   / _` | |/ __| | | | |/ _` |/ _` |/ _ \\| '__/ _` |\n"
"| |__| (_| | | (__| |_| | | (_| | (_| | (_) | | | (_| |\n"
" \\____\\__,_|_|\\___|\\__,_|_|\\__,_|\\__,_|\\___/|_|  \\__,_|\n";

int main() {
    double res;

    printf("%s", title);
    printf("Esta es una calculadora sencilla que realiza operaciones sobre dos números, cuenta con las siguientes operaciones:\n"
    "(+) Suma\n (-) Resta\n (*) Multiplicación\n (/) División\n");
}

int solver() {
    char op;
    double a, b;

    printf("Inserte la operacin a realizar:\n");
    scanf("%c", op);
}