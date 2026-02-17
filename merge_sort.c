#include <stdlib.h>
#include "merge_sort.h"

static void merge_stacks(Stack *s1, Stack *s2, Stack *dest) {
    Stack temp;
    init_stack(&temp);

    while (!is_empty(s1) && !is_empty(s2)) {
        int v1 = peek(s1);
        int v2 = peek(s2);

        if (v1 <= v2) {              
            push(&temp, pop(s1));
        } else {
            push(&temp, pop(s2));
        }
    }

    while (!is_empty(s1)) {
        push(&temp, pop(s1));
    }

    while (!is_empty(s2)) {
        push(&temp, pop(s2));
    }
    while (!is_empty(&temp)) {
        push(dest, pop(&temp));
    }

    free_stack(&temp);
}

static void sort_recursive(Stack *s, int n) {
    if (n <= 1) return;

    Stack left, right;
    init_stack(&left);
    init_stack(&right);

    int half = n / 2;

    for (int i = 0; i < half; i++) {
        push(&left, pop(s));
    }

    while (!is_empty(s)) {
        push(&right, pop(s));
    }

    sort_recursive(&left, half);
    sort_recursive(&right, n - half);

    merge_stacks(&left, &right, s);

    free_stack(&left);
    free_stack(&right);
}

void merge_sort_stack(Stack *s) {
    if (s == NULL) return;

    int n = size(s);
    sort_recursive(s, n);
}
