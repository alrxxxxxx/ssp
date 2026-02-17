#include <stdlib.h>
#include "merge_sort.h"

static Node* merge(Node* a, Node* b) {
    if (!a) return b;
    if (!b) return a;

    Node* result = NULL;

    if (a->data <= b->data) {
        result = a;
        result->next = merge(a->next, b);
    } else {
        result = b;
        result->next = merge(a, b->next);
    }

    return result;
}

static void split(Node* source, Node** front, Node** back) {
    Node* slow = source;
    Node* fast = source->next;

    while (fast) {
        fast = fast->next;
        if (fast) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *front = source;
    *back = slow->next;
    slow->next = NULL;
}

static void merge_sort(Node** headRef) {
    Node* head = *headRef;
    if (!head || !head->next) return;

    Node* a;
    Node* b;

    split(head, &a, &b);

    merge_sort(&a);
    merge_sort(&b);

    *headRef = merge(a, b);
}

void merge_sort_stack(Stack *s) {
    merge_sort(&s->top);
}