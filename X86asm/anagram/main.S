.global main

.data
N: .string "NO"
Y: .string "YES"

.bss
arr1: .skip 128 * 4
.bss
arr2: .skip 128 * 4

.text

main:
    push %ebp
    mov %esp, %ebp
    push %ebx

write1:
    call getchar

    cmp $'\n', %eax
    jz write2

    cmp $' ', %eax
    jz write1

    push %eax
    call tolower
    add $4, %esp

    incl arr1(, %eax, 4)

    jmp write1

write2:
    call getchar

    cmp $'\n', %eax
    jz end

    cmp $' ', %eax
    jz write2

    push %eax
    call tolower
    add $4, %esp
    
    incl arr2(, %eax, 4)
    
    jmp write2


end:
    xor %ebx, %ebx
    

check:
    mov arr1(, %ebx, 4), %ecx

    cmp %ecx, arr2(, %ebx, 4)
    jne No
    mov %ecx, arr1(, %ebx, 4)

    cmp $128, %ebx
    jz Yes
    inc %ebx
    jmp check

Yes:
    push $Y
    call puts
    add $8, %esp
    
    pop %ebx
    mov %ebp, %esp
    pop %ebp
    mov $0, %eax
    ret

No:
    push $N
    call puts
    add $8, %esp

    pop %ebx
    mov %ebp, %esp
    pop %ebp

    mov $0, %eax
    ret
