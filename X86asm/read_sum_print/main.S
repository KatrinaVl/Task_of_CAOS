.global main
main:
    call readi32 // ecx - A - res
    mov %eax, %ecx

    call readi32 // eax - B
    sal $1, %eax

    sub %eax, %ecx
    
    call readi32  // eax - C
    add %eax, %ecx
    sal $4, %eax
    add %eax, %ecx

    call readi32
    call writei32;

    mov %ecx, %eax
    call writei32;
    

    call finish 