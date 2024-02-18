#pragma once

#include "node.h"

typedef struct BinarySearchTree {
  Node *root;
} BinarySearchTree;

BinarySearchTree *binarySearchTree_new();
void binarySearchTree_destroy(BinarySearchTree *);
Node *binarySearchTree_insert(BinarySearchTree *, KEY_T, VAL_T);
Node *binarySearchTree_find(BinarySearchTree *, KEY_T);
void binarySearchTree_walk(BinarySearchTree *, void (*fx)(KEY_T, VAL_T));
void binarySearchTree_delete(BinarySearchTree *, KEY_T);
