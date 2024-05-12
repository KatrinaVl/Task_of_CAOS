#include <stdio.h>
#include <sys/syscall.h>

struct FileWriteState {
    int fd;
    unsigned char *buf;  // указатель на буфер
    int bufsize;         // размер буфера
    // здесь потребуется добавить поля для реализации буферизованной записи
    int it;  // количество
};

enum { SIZE = 4096 };

unsigned char buf_out[SIZE] = {0};
struct FileWriteState data = {
    .fd = 1, .buf = buf_out, .bufsize = SIZE, .it = 0};

struct FileWriteState *stout = &data;

void flush(struct FileWriteState *out) {
    asm volatile("int $0x80 \n"
                 :
                 : "a"(SYS_write), "b"(out->fd), "c"(out->buf), "d"(out->it));
}

void writechar(int c, struct FileWriteState *out) {
    // printf("%d\n", out->it);
    // printf("%c\n", c);
    if (out->it < out->bufsize) {
        out->buf[out->it] = c;
        ++out->it;
    } else {
        // for (int i = 0; i < out->bufsize; ++i){
        //     printf("%c\n", *(out->buf + i));
        // }
        // printf("\n");
        out->buf[out->it] = c;
        ++out->it;
        flush(out);
        out->it = 0;
    }
}

// int main() {
//     for (int i = 0; i < 2; ++i){
//         writechar('a', stout);
//     }
//     for (int i = 0; i < 2; ++i){
//         writechar('b', stout);
//     }
//     for (int i = 0; i < 2; ++i){
//         writechar('c', stout);
//     }
//     writechar('d', stout);
//     writechar('y', stout);
//     writechar('r', stout);
//     writechar('a', stout);
//     flush(stout);
//     return 0;
// }