section .text
global ft_strcpy

ft_strcpy:
    xor rax, rax
    xor rcx, rcx

.loop:
    mov al, [rsi + rcx]
    mov [rdi + rcx], al
    cmp al, 0
    je .done
    inc rcx
    jmp .loop

.done:
    mov rax, rdi
    ret