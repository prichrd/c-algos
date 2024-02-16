#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "node.h"
#include "singly_linked_list.h"

SinglyLinkedList *singlyLinkedList_new() {
  SinglyLinkedList *l = malloc(sizeof(SinglyLinkedList));
  if (l == NULL) {
    perror("failed to allocate singly linked list");
    abort();
  }
  l->len = 0;
  return l;
}

int singlyLinkedList_length(SinglyLinkedList *l) { return l->len; }

Node *singlyLinkedList_head(SinglyLinkedList *l) { return l->head; }

Node *singlyLinkedList_tail(SinglyLinkedList *l) { return l->tail; }

void singlyLinkedList_destroy(SinglyLinkedList *l) {
  Node *n = l->head;
  while (n != NULL) {
    node_destroy(n, false);
    n = n->next;
  }
  free(l);
}

Node *singlyLinkedList_pushFront(SinglyLinkedList *l, VAL_T v) {
  Node *n = node_new();
  n->val = v;
  if (l->head == NULL) {
    l->head = n;
    l->tail = n;
    l->len++;
    return n;
  }
  n->next = l->head;
  l->head = n;
  l->len++;
  return n;
}

Node *singlyLinkedList_pushBack(SinglyLinkedList *l, VAL_T v) {
  Node *n = node_new();
  n->val = v;
  if (l->tail == NULL) {
    l->head = n;
    l->tail = n;
    l->len++;
    return n;
  }
  l->tail->next = n;
  l->tail = n;
  l->len++;
  return n;
}

Node *singlyLinkedList_findNode(SinglyLinkedList *l, Node *from, VAL_T v) {
  Node *searchFrom = from;
  if (from == NULL) {
    searchFrom = l->head;
  }
  if (searchFrom == NULL) {
    return NULL;
  }
  return node_findNext(searchFrom, v);
}

void singlyLinkedList_deleteNode(SinglyLinkedList *l, Node *n) {
  if (l->head == NULL) {
    return;
  }
  if (l->head == n) {
    l->head = n->next;
    l->len--;
    node_destroy(n, false);
  }
  Node *parent = l->head;
  Node *next = l->head->next;
  while (next != NULL) {
    if (next == n) {
      parent->next = parent->next->next;
      l->len--;
      node_destroy(n, false);
      break;
    }
    parent = parent->next;
    next = next->next;
  }
}
