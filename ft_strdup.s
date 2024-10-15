section .text
global ft_strdup
extern malloc
extern ft_strlen
extern ft_strcpy

ft_strdup:
    xor rax, rax
    xor rcx, rcx

    push rdi
    call ft_strlen
    inc rax; incremento para tener en cuenta el nulo para reservar con malloc
    mov rdi, rax
    call malloc
    test rax, rax; esto comprueba si malloc da nulo
    jz .error; si es nulo tirams error
    pop rsi
    mov rdi, rax
    call ft_strcpy
    ret

.error:
    mov rax, 0
    ret