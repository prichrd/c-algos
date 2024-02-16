#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "doubly_linked_list.h"
#include "node.h"

DoublyLinkedList *doublyLinkedList_new() {
  DoublyLinkedList *l = malloc(sizeof(DoublyLinkedList));
  if (l == NULL) {
    perror("failed to allocate doubly linked list");
    abort();
  }
  l->len = 0;
  return l;
}

int doublyLinkedList_length(DoublyLinkedList *l) { return l->len; }

Node *doublyLinkedList_head(DoublyLinkedList *l) { return l->head; }

Node *doublyLinkedList_tail(DoublyLinkedList *l) { return l->tail; }

void doublyLinkedList_destroy(DoublyLinkedList *l) {
  Node *n = l->head;
  while (n != NULL) {
    node_destroy(n, false);
    n = n->next;
  }
  free(l);
}

Node *doublyLinkedList_pushFront(DoublyLinkedList *l, VAL_T v) {
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
  l->head->next->prev = l->head;
  l->len++;
  return n;
}

Node *doublyLinkedList_pushBack(DoublyLinkedList *l, VAL_T v) {
  Node *n = node_new();
  n->val = v;
  if (l->tail == NULL) {
    l->head = n;
    l->tail = n;
    l->len++;
    return n;
  }
  n->prev = l->tail;
  l->tail->next = n;
  l->tail = n;
  l->len++;
  return n;
}

Node *doublyLinkedList_findNodeForward(DoublyLinkedList *l, Node *from,
                                       VAL_T v) {
  Node *searchFrom = from;
  if (from == NULL) {
    searchFrom = l->head;
  }
  return node_findNext(searchFrom, v);
}

Node *doublyLinkedList_findNodeBackward(DoublyLinkedList *l, Node *from,
                                        VAL_T v) {
  Node *searchFrom = from;
  if (from == NULL) {
    searchFrom = l->tail;
  }
  return node_findPrev(searchFrom, v);
}

Node *doublyLinkedList_insertForward(DoublyLinkedList *l, Node *from, VAL_T v) {
  if (from == NULL) {
    perror("failed to insert node after NULL node");
    abort();
  }
  Node *n = node_new();
  n->val = v;
  n->next = from->next;
  n->prev = from;
  if (from->next != NULL) {
    from->next->prev = n;
  } else {
    l->tail = n;
  }
  from->next = n;
  l->len++;
  return n;
}

Node *doublyLinkedList_insertBackward(DoublyLinkedList *l, Node *from,
                                      VAL_T v) {
  if (from == NULL) {
    perror("failed to insert node before NULL node");
    abort();
  }
  Node *n = node_new();
  n->val = v;
  n->prev = from->prev;
  n->next = from;
  if (from->prev != NULL) {
    from->prev->next = n;
  } else {
    l->head = n;
  }
  from->prev = n;
  l->len++;
  return n;
}

void doublyLinkedList_deleteNode(DoublyLinkedList *l, Node *n) {
  Node *next = n->next;
  Node *prev = n->prev;
  if (next != NULL) {
    next->prev = prev;
  } else {
    l->tail = n->prev;
  }
  if (prev != NULL) {
    prev->next = next;
  } else {
    l->head = n->next;
  }
  l->len--;
  node_destroy(n, false);
}
