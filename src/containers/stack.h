#pragma once

#include "node.h"

typedef struct Stack {
  Node *head;
  int len;
} Stack;

Stack *stack_new();
void stack_destroy(Stack *);
VAL_T stack_pop(Stack *);
void stack_push(Stack *, VAL_T);
int stack_length(Stack *);
