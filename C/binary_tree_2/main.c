#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct Node {
    int32_t key;
    int32_t left_idx;
    int32_t right_idx;
};

void print_tree(int fd, int32_t i) {
    struct Node root[1];
    int check = pread(fd, root, sizeof(*root), sizeof(*root) * i);
    if (check == -1) {
        return;
    }
    if (root->right_idx != 0) {
        print_tree(fd, root->right_idx);
    }
    printf("%d\n", root->key);
    if (root->left_idx != 0) {
        print_tree(fd, root->left_idx);
    }
}

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        return 1;
    }
    int f = open(argv[1], O_RDONLY);
    if (f == -1) {
        return 1;
    }
    print_tree(f, 0);
    printf("\n");
    return 0;
}