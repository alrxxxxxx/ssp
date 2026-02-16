#include <stdio.h>
#include <string.h>
#include "stack.h"
#include "sort_stack.h"
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

int main(int argc, char *argv[]) {

    if (argc == 3 && strcmp(argv[1], "--file") == 0) {
        if (!print_from_file(argv[2])) { 
            printf("Cannot read file.\n");
        }
        return 0;
    }

    while (1) {
        printf("enter numbers separated by space (end with 0):\n");

        Stack orig;
        init_stack(&orig);

        int x;
        while (scanf("%d", &x) == 1 && x != 0) {
            push(&orig, x);
        }

        Stack sorted = copy_stack(&orig);
        sort_stack(&sorted);

        if (!save_two_stacks("output.txt", &orig, &sorted)) {
            printf("Cannot write file.\n");
        } else {
            printf("Saved to output.txt\n");
        }

        int choice;
        printf("Do you want to repeat? (1-yes, 0-no): ");
        scanf("%d", &choice);

        if (choice == 0) break;
    }

    return 0;
}