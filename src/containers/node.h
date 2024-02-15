#pragma once

#include <stdbool.h>

#include "../generics.h"

typedef struct Node {
  VAL_T val;
  struct Node *prev;
  struct Node *next;
} Node;

Node *node_new();
void node_destroy(Node *, bool);
Node *node_findPrev(Node *n, VAL_T v);
Node *node_findNext(Node *n, VAL_T v);
