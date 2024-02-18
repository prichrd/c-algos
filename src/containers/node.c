#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "node.h"

Node *node_new() {
  Node *n = malloc(sizeof(Node));
  if (n == NULL) {
    perror("failed to allocate node");
    abort();
  }
  n->left = NULL;
  n->right = NULL;
  return n;
}

void node_destroy(Node *n, bool recursive) {
  if (n == NULL) {
    return;
  }
  if (recursive) {
    node_destroy(n->right, recursive);
    node_destroy(n->left, recursive);
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
  return node_findPrev(n->left, v);
}

Node *node_findNext(Node *n, VAL_T v) {
  if (n == NULL) {
    return NULL;
  }
  if (n->val == v) {
    return n;
  }
  return node_findNext(n->right, v);
}
