#include "stack.h"
#include <stdlib.h>

Stack create_stack() {
    Stack s;
    s.top = NULL;
    return s;
}

void free_stack(Stack* s) {
    while (s->top != NULL) {
        Node* temp = s->top;
        s->top = temp->next;
        free(temp);
    }
}

void push(Stack* s, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) return;

    newNode->data = value;
    newNode->next = s->top;
    s->top = newNode;
}

int pop(Stack* s) {
    if (s->top == NULL) return 0;

    Node* temp = s->top;
    int value = temp->data;

    s->top = temp->next;
    free(temp);

    return value;
}

int peek(const Stack* s) {
    if (s->top == NULL) return 0;
    return s->top->data;
}

int is_empty(const Stack* s) {
    return s->top == NULL;
}

int size(const Stack* s) {
    int count = 0;
    Node* current = s->top;

    while (current != NULL) {
        count++;
        current = current->next;
    }

    return count;
}