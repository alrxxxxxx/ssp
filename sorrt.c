
#include "sort_stack.h"

void sort_stack(Stack* s) {
    Stack temp = create_stack(s->capacity);

    while (!is_empty(s)) {
        int x = pop(s);

        while (!is_empty(&temp) && peek(&temp) > x) {
            push(s, pop(&temp));
        }
        push(&temp, x);
    }

    while (!is_empty(&temp)) {
        push(s, pop(&temp));
    }

    free_stack(&temp);
}