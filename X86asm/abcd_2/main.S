    .global process
    .global A
    .global B
    .global R

    .data
A: .int 0
B: .int 0   
R: .int 0

    .text

process:
    push %ebx
    // call readi32
    mov A, %ebx // a

    // call readi32
    mov B, %ecx // b

    xor %edx, %edx // res

_loop:
    // shl $1, %ecx
    cmp $0, %ecx
    jz end
    // shr $1, %ecx
    test $1, %ecx
    jnz odd
    shl $1, %ebx
    shr $1, %ecx
    jmp _loop

odd:
    add %ebx, %edx
    shl $1, %ebx
    shr $1, %ecx
    jmp _loop

end:
    mov %edx, R
    // call writei32
    pop %ebx
    // call finish
    ret