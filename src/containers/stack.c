#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

Stack *stack_new() {
  Stack *s = malloc(sizeof(Stack));
  s->len = 0;
  s->head = NULL;
  return s;
}

void stack_destroy(Stack *s) {
  if (s->head != NULL) {
    node_destroy(s->head, true);
  }
  free(s);
}

void stack_push(Stack *s, VAL_T v) {
  Node *n = node_new();
  if (n == NULL) {
    perror("failed to allocate new node for stack");
    abort();
  }
  n->val = v;
  if (s->head != NULL) {
    n->next = s->head;
  }
  s->head = n;
  s->len++;
}

VAL_T stack_pop(Stack *s) {
  if (s->head == NULL) {
    perror("failed to pop on an empty stack");
    abort();
  }
  Node *popped = s->head;
  VAL_T val = popped->val;
  s->head = popped->next;
  node_destroy(popped, false);
  return val;
}

int stack_length(Stack *s) { return s->len; }
