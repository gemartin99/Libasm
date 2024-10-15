section .text
global ft_strdup
global ft_strlen
extern malloc

ft_strlen:
    xor rcx, rcx

ft_strdup:
    xor rax, rax
    xor rcx, rcx

    call ft_strlen
    mov rsi, rax
    inc rsi; aumentamos porque hay que tener en cuenta el nulo
    call malloc
    test rax, rax; esto comprueba si malloc da nulo
    jz .error; si es nulo tirams error
    mov rbx, rax
    mov rcx, 0

.copy_loop:
    mov al, [rdi + rcx]
    mov [rbx + rcx], al
    cmp al, 0
    je .copy_done
    inc rcx
    jmp .copy_loop

.copy_done:
    mov rax, rbx
    ret

.error:
    mov rax, 0
    ret