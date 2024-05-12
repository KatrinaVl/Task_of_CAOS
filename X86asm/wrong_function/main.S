.global main

.data
d: .string "%d\n"
c: .string "%c\n"
s: .string "%s\n"
width: .int 2
comp: .string "comp"
ee: .string "end"

.text

main:
    push %ebp
    mov %esp, %ebp
    push %eax


    mov $my_func, %eax
    push %eax
    push %ebp
    mov %esp, %ebp
    jmp process

my_func:
    push %eax
    push $d
    call printf
    add $8, %esp

    pop %eax
    mov %ebp, %esp
    pop %ebp

    mov $0, %eax
    ret
