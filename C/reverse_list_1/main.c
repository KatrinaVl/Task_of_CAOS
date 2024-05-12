#include <stdio.h>
#include <stdlib.h>

struct List {
    int data;
    struct List *next;
    struct List *prev;
} list = {0};

int main() {
    struct List *curr = calloc(1, sizeof(*curr));
    struct List *old = curr;
    int n;
    while (scanf("%d", &n) == 1) {
        struct List *curr_next = calloc(1, sizeof(*curr_next));
        curr->data = n;
        curr->next = curr_next;
        curr_next->prev = curr;
        curr = curr_next;
    }
    curr = curr->prev;
    while (curr) {
        printf("%d\n", curr->data);
        curr = curr->prev;
    }
    while (old) {
        struct List *prev_free = old;
        old = old->next;
        free(prev_free);
    }
    return 0;
}