section .text
global ft_strcmp

ft_strcmp:
    xor rax, rax

.calc_diff:
    sub al, bl; hacer sub es hacer una resta y el res de la operacion se guarda en al
    movzx rax, al; ahora igualamos el valor de al y rax el zx es para que sea un registro de 64 bits
    ret

.loop:
    mov al, [rdi]
    mov bl, [rsi]
    cmp al, bl
    jne .calc_diff
    cmp al, 0
    je .done
    inc rdi
    inc rsi
    jmp .loop

.done:
    xor rax, rax
    ret