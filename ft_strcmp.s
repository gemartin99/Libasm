section .text
global ft_strcmp
extern printf

ft_strcmp:
    xor rax, rax
    xor rcx, rcx

.loop:
    mov al, [rdi + rcx]
    mov bl, [rsi + rcx]
    
    cmp al, bl
    jne .calc_diff
    cmp al, 0
    je .done
    inc rcx
    jmp .loop

.calc_diff:
    sub al, bl; hacer sub es hacer una resta y el res de la operacion se guarda en al
    movsx rax, al; ahora igualamos el valor de al y rax el zx es para que sea un registro de 64 bits
    ret

.done:
    mov rax, 0
    ret
