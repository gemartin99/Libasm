section .text
global ft_strdup
extern malloc

ft_strdup:
    xor rax, rax
    xor rcx, rcx

    call ft_strlen
    mov rsi, rax
    inc rsi; aumentamos porque hay que tener en cuenta el nulo
    call malloc
    test rax, rax; esto comprueba si malloc da nulo
    jz .error; si es nulo tirams error

.error:
    mov rax, 0
    ret