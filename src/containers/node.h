#pragma once

#include <stdbool.h>

#include "../generics.h"

typedef struct Node {
  KEY_T key;
  VAL_T val;
  struct Node *left;
  struct Node *right;
} Node;

Node *node_new();
void node_destroy(Node *, bool);
Node *node_findPrev(Node *n, VAL_T v);
Node *node_findNext(Node *n, VAL_T v);
