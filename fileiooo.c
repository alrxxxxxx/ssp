#include "fileio.h"
#include <stdio.h>

static void write_stack_in_input_order(FILE* f, Stack* s) {
    Stack tmp = create_stack(s->capacity);

    while (!is_empty(s)) push(&tmp, pop(s));

    while (!is_empty(&tmp)) {
        int x = pop(&tmp);
        fprintf(f, "%d ", x);
        push(s, x);
    }

    free_stack(&tmp);
}

int save_two_stacks(const char* filename, Stack* orig, Stack* sorted) {
    FILE* f = fopen(filename, "w");
    if (!f) return 0;

    int n = size(orig);
    fprintf(f, "%d\n", n);

    write_stack_in_input_order(f, orig);
    fprintf(f, "\n");

    write_stack_in_input_order(f, sorted);
    fprintf(f, "\n");

    fclose(f);
    return 1;
}
 int print_from_file(const char *filename) {
    FILE *f = fopen(filename, "r");
    if (!f) return 0;

    char line[1024];
    while (fgets(line, sizeof(line), f)) {
        printf("%s", line);
    }

    fclose(f);
    return 1;
}


