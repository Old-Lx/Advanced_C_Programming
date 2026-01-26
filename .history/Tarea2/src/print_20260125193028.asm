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
    string_buf resb  100 ; Buffer para la string
    welcome db "Ingresa una palabra para imprimir en pantalla: ", 0
    newline db 10

section .text
    global print

    print:
        ; Cálculo de la longitud de la string welcome
        mov rdi, welcome ; se selecciona el mensaje de bienvenida
        xor rcx, rcx ; se hace cero el registro rcx
        not rcx ; se vuelve -1 
        xor al, al ; cero el registro al
        cld ; se limpia el flag de dirección
        repnz scasb ; esto obtiene la longitud de la string
        not rcx ; aplica valor absoluto para obtener la distancia recorrida (esto me confundió)
        dec rcx ; se resta uno para quitarnos el null terminator
        mov rdx, rcx ; ponemos la longitud en rdx

        ; Impresión de la string welcome en stdout
        mov rsi, welcome ; apuntamos rsi al inicio del texto
        mov rax, 1 ; syscall de escritura en stdout
        syscall

        ; Lectura de la string
        mov rax, 0  ; sys_read
        mov rdi, 0 ; stdin
        mov rsi, string_buf ; pone los caracteres en el buffer
        mov rdx, 100 ; Número máximo de bytes a leer
        syscall ; Llamada al kernel

        ; Cálculo de la longitud de la string que ingresó el usuario (análogo a lo que se hizo con welcome)
        mov rdi, string_buf ; se selecciona el buffer
        xor rcx, rcx 
        not rcx 
        xor al, al 
        cld 
        repnz scasb 
        not rcx 
        dec rcx 
        mov rdx, rcx 

        ; Impresión de la string ingresada por el usuario
        mov rsi, string_buf ; apuntamos rsi al inicio del texto
        mov rax, 1 ; syscall de escritura en stdout
        syscall




%ifidn OUTPUT_FORMAT,elf64 
    section .note,GNU-stack noalloc noexe nowrite progbits 
%endif