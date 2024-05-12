.global main

main:
    xor %ecx, %ecx
l:
    call readi32
    jc L
    push %eax
    inc %ecx
    jmp l

L:
    cmp $0, %ecx
    jle end
    pop %eax
    call writei32
    loop L
end:
    call finish