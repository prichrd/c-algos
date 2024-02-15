#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "node.h"

Node *node_new() {
  Node *n = malloc(sizeof(Node));
  n->prev = NULL;
  n->next = NULL;
  return n;
}

void node_destroy(Node *n, bool recursive) {
  if (recursive && n->next != NULL) {
    node_destroy(n->next, recursive);
  }
  if (recursive && n->prev != NULL) {
    node_destroy(n->prev, recursive);
  }
  free(n);
}

Node *node_findPrev(Node *n, VAL_T v) {
  if (n == NULL) {
    return NULL;
  }
  if (n->val == v) {
    return n;
  }
  return node_findPrev(n->prev, v);
}

Node *node_findNext(Node *n, VAL_T v) {
  if (n == NULL) {
    return NULL;
  }
  if (n->val == v) {
    return n;
  }
  return node_findNext(n->next, v);
}