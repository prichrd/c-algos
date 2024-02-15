#pragma once

#define VAL_T int

typedef struct Node {
  VAL_T val;
  struct Node* next;
} Node;

Node* node_new();
void  node_destroy(Node*, bool);

typedef struct Stack {
  Node* head;
  int len;
} Stack;

Stack* stack_new();
void   stack_destroy(Stack*);
VAL_T  stack_pop(Stack*);
void   stack_push(Stack*, VAL_T);
int    stack_length(Stack*);
