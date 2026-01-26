/* 
    EP5801 Programación Avanzada en C
    Luis Becerra a.k.a. Lartrax/Old-Lx
    Código principal de la tarea 2
*/
/* 
    WARNING: No copies y pegues de las referencias si vas a implementar algo similar, leer el contexto siempre ayuda =D
    Referencias:
        - Imprimir strings en assembly: 
        https://stackoverflow.com/questions/27594297/how-to-print-a-string-to-the-terminal-in-x86-64-assembly-nasm-without-syscall
        - Leer strings enviadas por STDIN usando syscalls: 
        https://stackoverflow.com/questions/6780671/how-to-make-string-input-in-assembly-language
        https://askfilo.com/user-question-answers-smart-solutions/write-a-sample-assembly-program-to-read-two-integers-from-3337353038323430
*/
[BITS 64]

section .data
    string_buf: 
        db 255 ; Tamaño del buffer máximo
        db 0 ; Se llena con el tamaño predeterminado del OS instalado
        times 255 db 0 ; La string

section .text
    global print

    print:
        ; Lectura de la string



        ; Cálculo de la longitud de la string




%ifidn OUTPUT_FORMAT,elf64 
    section .note,GNU-stack noalloc noexe nowrite progbits 
%endif