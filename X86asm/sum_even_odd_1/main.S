.global main
main:
    xor %edx, %edx // четные
    xor %ecx, %ecx // нечетные
loop:
    call readi32
    jc end
    test $1, %eax
    jnz odd
    jz even

odd:
    add %eax, %ecx
    jmp loop
even:
    add %eax, %edx
    jmp loop

end:
    mov %edx, %eax
    call writei32
    mov %ecx, %eax
    call writei32
    call finish