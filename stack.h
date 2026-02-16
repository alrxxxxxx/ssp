
#ifndef STACK_H
#define STACK_H

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* top;
} Stack;

void init_stack(Stack* s);
void free_stack(Stack* s);
void push(Stack* s, int value);
int pop(Stack* s);
int peek(const Stack* s);
int is_empty(const Stack* s);
int size(const Stack* s);

#endif