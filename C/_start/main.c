#include <stdio.h>
#include <sys/syscall.h>  
#include <unistd.h>

// int main(int a, char **b, char **c){
//     // for (int i = 0; i < 6; ++i) {
//     //     printf("%s\n", c[i]);
//     // }
//     return a;
// }

// extern int main(int argc, char* argv[], char *envp[]);

int _start(void) {
    int a;
    char** b;
    char** c;
    asm (
        "int $0x80 \n"
        "mov (%%esp), %%eax\n"
        "xor %%ecx, %%ecx\n"
        "add %%esp, %%ecx\n"
        "add $32, %%ecx\n"
        :"=a"(a), "=c"(b)
        : 
        :
    );
    c = b + a + 1;
    int res = main(a, b, c);
    asm volatile ("int $0x80" : : "a"(SYS_exit), "b"(res));
}