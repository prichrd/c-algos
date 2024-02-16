#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

Stack *stack_new() {
  Stack *s = malloc(sizeof(Stack));
  if (s == NULL) {
    perror("failed to allocate stack");
    abort();
  }
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
  s->len--;
  node_destroy(popped, false);
  return val;
}

int stack_length(Stack *s) { return s->len; }
