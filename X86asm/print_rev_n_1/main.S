.global main
main:
    call readi32
    
    rol %eax
    jc end
    rcr %eax
loop:
    call  writei32
    dec %eax
    jns loop

end:
    call finish