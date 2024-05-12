.global sort_by_abs

.data
d: .string "%hd\n"
c: .string "%c\n"
s: .string "%s\n"
width: .int 2
comp: .string "comp"
ee: .string "end"

.bss
arr: .skip 5 * 2

.text

comparator:
    push %ebp
    mov %esp, %ebp
    
    mov 8(%ebp), %eax

    movw (%eax), %ax

    cmpw $0, %ax
    jnl after1
    negw %ax
after1:

    movw %ax, %dx // 1 number

    mov 12(%ebp), %eax 
    movw (%eax), %ax

    cmpw $0, %ax
    jnl after2
    negw %ax

after2:

    movw %ax, %cx //2 number

    subw %cx, %dx
    cmpw $0, %dx
    jl l
    jg g
    je e



l:
    mov $(-1), %eax
    
    mov %ebp, %esp
    pop %ebp
    ret


g:
    mov $(1), %eax
    
    mov %ebp, %esp
    pop %ebp
    ret

e:
    mov $(0), %eax
    
    mov %ebp, %esp
    pop %ebp
    ret


sort_by_abs:
    push %ebp
    mov %esp, %ebp
    push %eax
  
    push $comparator

    mov $2, %eax
    push %eax

    mov 12(%ebp), %eax
    push %eax

    mov 8(%ebp), %eax
    push %eax

    call qsort

    pop %eax
    mov %ebp, %esp
    pop %ebp
    ret