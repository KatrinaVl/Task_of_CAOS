.text

.global main

.data

pred: .space 4 * 1002
arr: .space 4 * 1002

.text
main: 

    xor %ecx, %ecx // счетчик

    movl $(0), pred(, %ecx, 4)
    movl $(-1), arr(, %ecx, 4)
    inc %ecx

cicle:
    call readi32
    jc end

    cmp $0, %eax
    jz push_for_command

pop:
    call readi32
    xor %edx, %edx // версия, с которой попаем
    xor %ebx, %ebx // предыдущая версия, версии, с которой попаем
    mov %eax, %edx // запомнили версию
    mov arr(, %edx, 4), %eax
    call writei32
    mov pred(, %edx, 4), %ebx

    cmp $(-1), %eax
    jz cicle


    jmp push_
    

push_for_command:
    call readi32
    mov %eax, pred(, %ecx, 4)
    
    call readi32
    mov %eax, arr(, %ecx, 4)

    inc %ecx

    jmp cicle


push_:
    mov pred(, %ebx, 4),  %eax // вытащили версию
    mov arr(, %ebx, 4), %edx // вытащили значение


    mov %eax, pred(, %ecx, 4)
    mov %edx, arr(, %ecx, 4)

    inc %ecx
    jmp cicle

end:
    call finish