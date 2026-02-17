#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "stack.h"
#include "sort.h"
#include "merge_sort.h"
#include "fileio.h"

static Stack copy_stack(Stack* src) {
    Stack tmp;
    Stack dst;

    init_stack(&tmp);
    init_stack(&dst);

    while (!is_empty(src)) {
        push(&tmp, pop(src));
    }

    while (!is_empty(&tmp)) {
        int x = pop(&tmp);
        push(src, x);
        push(&dst, x);
    }

    return dst;
}

int main() {
    Stack orig;
    init_stack(&orig);

    int x;
    while (scanf("%d", &x) == 1) {
        push(&orig, x);
    }

    printf("Size read = %d\n", size(&orig));

    Stack sorted1 = copy_stack(&orig);
    Stack sorted2 = copy_stack(&orig);

    clock_t start1 = clock();
    sort_stack(&sorted1);
    clock_t end1 = clock();

    clock_t start2 = clock();
    merge_sort_stack(&sorted2);
    clock_t end2 = clock();

    double time1 = (double)(end1 - start1) / CLOCKS_PER_SEC;
    double time2 = (double)(end2 - start2) / CLOCKS_PER_SEC;

    printf("Insertion sort time: %f seconds\n", time1);
    printf("Merge sort time: %f seconds\n", time2);

    return 0;
}