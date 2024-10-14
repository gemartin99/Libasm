section .text
global ft_strcpy

ft_strcpy:
    xor rax, rax

.loop:
    mov al, [rdi + rax]
    mov [rsi + rax], al
    cmp al, 0
    je .done
    inc rax
    jmp .loop

.done:
    ret