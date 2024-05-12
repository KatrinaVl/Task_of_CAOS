.data
N: .int 0
res: .float 0.0
mask:.float 1.0
    .float -1.0
    .float 1.0
    .float -1.0
sign:  .float 1.0
    .float 0.0
    .float 0.0
    .float 0.0
z: .float -1.0
    .float 0.0
    .float 0.0
    .float 0.0
r: .float 0.0
    .float 0.0
    .float 0.0
    .float 0.0
    
d: .string "%d\n"


.text

.global product

product:
    push %ebp
    mov %esp, %ebp
    push %ebx
    push %esi

    movss r, %xmm3 // res
    movss sign, %xmm4 // sign

    mov 8(%ebp), %eax // size n

    cmp N, %eax
    je end

    mov %eax, N

    mov 12(%ebp), %edx // adress x
    mov 16(%ebp), %ecx // adress y
    xor %ebx, %ebx // ebx - i cicles
    xor %esi, %esi // esi numbers

cicle:
    subl %esi, %eax

    cmp $4, %eax
    jl after2    

    add %esi, %eax

    movups (%edx, %esi, 4), %xmm0 // x
    movups (%ecx, %esi, 4), %xmm1 // y
    movups mask, %xmm2 // mask
    mulps %xmm1, %xmm0 // x * y
    mulps %xmm2, %xmm0 // res * (-1)

    //горизонтальное
    haddps %xmm0, %xmm0
    haddps %xmm0, %xmm0

    addss %xmm0, %xmm3
    add $4, %esi
    jmp cicle

after2:

    cmp %esi, N
    je end

    movss (%edx, %esi, 4), %xmm0 // x
    movss (%ecx, %esi, 4), %xmm1 // y

    mulss %xmm1, %xmm0 // x * y
    mulss %xmm4, %xmm0 // res * (-1)
    addss %xmm0, %xmm3
    mulss z, %xmm4

    inc %esi
    jmp after2
    

end:

    mov 20(%ebp), %eax// СОХРАНИТЬ НА СТЕК // adress result 
    movss %xmm3, (%eax) 

    pop %esi
    pop %ebx
    movl %ebp, %esp
    pop %ebp
    ret
