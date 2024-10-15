section .text
global ft_write
extern  __errno_location


ft_write:
    mov rax, 1
    syscall
    cmp rax, 0
    jl .error ; rax < 0 
    ret

.error:
    call    __errno_location
    mov [rax], rdi

    mov rax, -1
    ret
