section .text
global ft_strlen

ft_strlen:
    xor rax, rax;
    xor rcx, rcx ;esto es como declarar el valor a la variable en 0, i=0;

.loop:
    mov al, [rdi + rcx]
    cmp al, 0
    je .done
    inc rcx
    jmp .loop

.done:
    mov rax, rcx; esto es como res = count
    ret 