.text

.global okay

okay:
    push %ebp
    mov %esp, %ebp
    push %ax
    flds 12(%ebp) //st2 - y
    flds 16(%ebp) //st1 - z
    flds 8(%ebp) // st0 - x

    // fcom st1 // сравнение           
    fcom %st(2)         //; сравниваем ST(0) и ST(2)
    fstsw %ax       // ; данные регистра состояния загружаем в AX
    sahf
    

    jb sin_xy

log_xz:
    fprem // st0 - x%z st1 - z st2 - y
    fxch %st(2) // st0 - y st1 - z st2 - x%z
    fxch %st(1) // st0 - z st1 - y st2 - x%z
    fxch %st(2) //st0 - x%z st1 - y st2 - z
    fyl2x
    ffree %st(1)
    ffree %st(2)
    mov %ebp, %esp
    pop %ebp
    ret




sin_xy:
    fxch %st(2) //st0 - y st2 - x
    fadd %st(1), %st(0) //st0 - y + z
    fsin
    ffree %st(1)
    ffree %st(2)
    pop %ax
    mov %ebp, %esp
    pop %ebp
    ret


