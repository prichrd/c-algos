#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "binary_search_tree.h"
#include "node.h"

BinarySearchTree *binarySearchTree_new() {
  BinarySearchTree *t = malloc(sizeof(BinarySearchTree));
  if (t == NULL) {
    perror("failed to allocate singly linked list");
    abort();
  }
  return t;
}

void binarySearchTree_destroy(BinarySearchTree *t) {
  if (t->root != NULL) {
    node_destroy(t->root, true);
  }
  free(t);
}

void insert(Node *n, Node *nt) {
  if (nt->key == n->key) {
    n->val = nt->val;
    return;
  }

  if (nt->key < n->key && n->left == NULL) {
    n->left = nt;
    return;
  }

  if (nt->key > n->key && n->right == NULL) {
    n->right = nt;
    return;
  }

  if (nt->key < n->key) {
    return insert(n->left, nt);
  }

  return insert(n->right, nt);
}

Node *binarySearchTree_insert(BinarySearchTree *t, KEY_T k, VAL_T v) {
  Node *n = node_new();
  n->key = k;
  n->val = v;
  if (t->root == NULL) {
    t->root = n;
  } else {
    insert(t->root, n);
  }
  return n;
}

Node *find(Node *n, KEY_T k) {
  if (n == NULL) {
    return NULL;
  }

  if (n->key == k) {
    return n;
  }

  if (n->key < k) {
    return find(n->right, k);
  }

  return find(n->left, k);
}

Node *binarySearchTree_find(BinarySearchTree *t, KEY_T k) {
  return find(t->root, k);
}

Node *max(Node *n) {
  if (n->right != NULL) {
    return max(n->right);
  }
  return n;
}

Node *del(Node *n, KEY_T k) {
  if (n == NULL) {
    return NULL;
  }
  if (k < n->key) {
    n->left = del(n->left, k);
    return n;
  }
  if (k > n->key) {
    n->right = del(n->right, k);
    return n;
  }

  if (n->left == NULL && n->right == NULL) { // Leaf node
    node_destroy(n, false);
    return NULL;
  }

  if (n->left != NULL) { // Node with one child
    Node* tmp = n->left;
    node_destroy(n, false);
    return tmp;
  } else if (n->right != NULL) {
    Node* tmp = n->right;
    node_destroy(n, false);
    return tmp;
  }

  return n;
}

void walk(Node *n, void (*fx)(KEY_T, VAL_T)) {
  if (n == NULL) {
    return;
  }
  walk(n->left, fx);
  fx(n->key, n->val);
  walk(n->right, fx);
}

void binarySearchTree_walk(BinarySearchTree *t, void (*fx)(KEY_T, VAL_T)) {
  walk(t->root, fx);
}

void binarySearchTree_delete(BinarySearchTree *t, KEY_T k) {
  t->root = del(t->root, k);
}
