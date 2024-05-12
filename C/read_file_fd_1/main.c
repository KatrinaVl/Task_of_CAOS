#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

enum { BUF = 4096 };

struct FileContent {
    ssize_t size;
    char *data;
};

struct FileContent read_file(int fd) {
    struct FileContent f = {.size = -1, .data = NULL};
    char buf[BUF];
    ssize_t result;
    size_t sum = 0;
    size_t use = 0;
    size_t last = BUF;
    char *dif = NULL;
    size_t dif_size = 0;
    ssize_t write = 0;
    int j = 0;
    char *it = buf + use;
    while ((result = read(fd, it, last)) > 0) {
        ++j;
        // printf("%d cicle\n", j);
        use += result;
        last -= result;
        // printf("use: %ld last: %ld\n", use, last);
        if (use == BUF && last == 0) {
            dif_size += BUF;
            // printf("use: %ld last: %ld dif_size: %ld\n", use, last,
            // dif_size);
            char *cur = realloc(dif, dif_size);
            if (!cur) {
                free(dif);
                return f;
            }
            dif = cur;
            // printf("buf\n");
            // for (size_t i = 0; i < use; ++i) {
            //     printf("%c", *(buf + i));
            // }
            // printf("\n");

            // printf("%ld\n", *dif);
            // printf("write: %ld\n", write);
            memcpy(dif + write, buf, use);

            // printf("dif\n");
            // for (size_t i = 0; i < use * j; ++i) {
            //     printf("%c", *(dif + i));
            // }
            // printf("\n");

            write += BUF;
            // for (size_t i = 0; i < use; ++i) {
            //     printf("%c", *(dif + i));
            // }
            // printf("\n");
            use = 0;
            last = BUF;
        }
        sum += result;
        it = buf + use;
        // printf("summ: %ld\n", sum);
        // printf("\n");
        // printf("\n");
    }
    // printf("res: %ld\n", result);

    if (result == -1) {
        free(dif);
        return f;
    }
    if (use > 0) {
        // printf("res: %ld\n", result);
        // printf("size: %ld\n", dif_size);
        // printf("use: %ld\n", use);
        // printf("write: %ld\n", write);
        char *cur = realloc(dif, dif_size + use + 1);
        if (!cur) {
            free(dif);
            return f;
        }
        dif = cur;
        // printf("size: %ld\n", dif_size + use + 1);
        memcpy(dif + write, buf, use);
        dif[dif_size + use] = '\0';
        f.data = dif;
        f.size = dif_size + use;
        // for (size_t i = 0; i < f.size; ++i) {
        //     printf("%c", *(f.data + i));
        // }
        // printf("\n");
        return f;
    }
    // printf("res: %ld\n", result);
    char *cur = realloc(dif, dif_size + 1);
    if (!cur) {
        free(dif);
        return f;
    }
    dif = cur;
    // printf("size: %ld\n", dif_size);
    dif[dif_size] = '\0';
    f.data = dif;
    f.size = dif_size;
    // for (size_t i = 0; i < f.size; ++i) {
    //     printf("%c", *(f.data + i));
    // }
    // printf("\n");
    return f;
}

// int main() {
//     FILE *file = fopen("test1.txt", "r");
//     struct FileContent f = read_file(fileno(file));
//     printf("%ld\n", f.size);
//     for (size_t i = 0; i < f.size; ++i) {
//             printf("%c", *(f.data + i));
//     }
//     // printf("\n");
//     return 0;
// }