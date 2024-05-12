.global main
main:
    call readi32
    xor %ecx, %ecx // результат
    
loop:
    mov %eax, %ebx 
    and $1, %ebx // посмотрели какой бит на конце
    add %ebx, %ecx

    shr $1, %eax // сдвинули

    jnz loop

    mov %ecx, %eax
    call writei32

    call finish