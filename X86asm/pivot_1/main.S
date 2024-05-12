.text
.global partition

// ebx - массив
// esi - size
// edi - pivot

partition:
// main:

    push %ebp
    mov %esp, %ebp
    push %esi

    xor %ecx, %ecx // i - сетчик
    xor %edx, %edx // mid

_loop:

    cmp $0, %esi
    jz end


    cmp %di, (%ebx, %ecx, 2)
    jl swap
    inc %ecx
    dec %esi
    jmp _loop

swap:
    xor %eax, %eax
    pushw (%ebx, %ecx, 2)
    pushw (%ebx, %edx, 2)
    popw %ax
    movw %ax, (%ebx, %ecx, 2)
    popw %ax
    movw %ax, (%ebx, %edx, 2)
    inc %edx
    inc %ecx
    dec %esi
    jmp _loop


end:
    pop %esi
    mov %ebp, %esp
    pop %ebp
    ret
    // call finish
