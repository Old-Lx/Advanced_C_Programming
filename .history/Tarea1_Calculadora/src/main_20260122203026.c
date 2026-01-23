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

int solver() {
    char op;
    double a, b;

    // Registro de operación a realizar
    printf("Inserte la operación a realizar:\n");
    scanf("%c", &op);

    // Registro de números a utilizar
    printf("Inserte ambos números de la operación, sepárelos con un espacio en blanco:\n");
    scanf("%lf %lf", &a, &b);

    // Ejecución de operaciones:
    switch (op) {
        case '+':
            return a + b;
            break;
        case '-':
            return a - b;
            break;
        case '*':
            return a * b;
            break;
        case '/':
            return a / b;
            break;
        default:
            printf("Operación no definida\n");
            return -9999;
            break;
    }
}

int main() {
    double res;

    // Display del ttulo y explicación
    printf("%s", title);
    printf("Esta es una calculadora sencilla que realiza operaciones sobre dos números, cuenta con las siguientes operaciones:\n"
    "(+) Suma\n (-) Resta\n (*) Multiplicación\n (/) División\n");
    
    // Ejecucin y display del resultado
    res = solver();
    printf("El resultado de su operación es:\n %lf", res);
}