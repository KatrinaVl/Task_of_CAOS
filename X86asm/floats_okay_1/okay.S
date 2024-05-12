.text

.global okay

okay:
    push %ebp
    mov %esp, %ebp
    movsd 8(%ebp), %xmm0 // 1
    movsd 16(%ebp), %xmm1 // 2
    mulsd %xmm0, %xmm0 // x^2
    mulsd %xmm0, %xmm0 //x^4
    mulsd %xmm1, %xmm1
    mulsd %xmm1, %xmm1
    addsd %xmm0, %xmm1 // 1 - x^4 + y^4
    sqrtsd %xmm1, %xmm0 // 0 - sqrt
    mov 24(%ebp), %ecx // adress
    movsd %xmm0, (%ecx)
    movl %ebp, %esp
    pop %ebp
    ret