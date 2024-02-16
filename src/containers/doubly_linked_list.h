#pragma once

#include "node.h"

typedef struct DoublyLinkedList {
  Node *head;
  Node *tail;
  int len;
} DoublyLinkedList;

DoublyLinkedList *doublyLinkedList_new();
void doublyLinkedList_destroy(DoublyLinkedList *);
int doublyLinkedList_length(DoublyLinkedList *);
Node *doublyLinkedList_head(DoublyLinkedList *);
Node *doublyLinkedList_tail(DoublyLinkedList *);
Node *doublyLinkedList_pushFront(DoublyLinkedList *, VAL_T);
Node *doublyLinkedList_pushBack(DoublyLinkedList *, VAL_T);
Node *doublyLinkedList_findNodeForward(DoublyLinkedList *, Node *, VAL_T);
Node *doublyLinkedList_findNodeBackward(DoublyLinkedList *, Node *, VAL_T);
Node *doublyLinkedList_insertForward(DoublyLinkedList *, Node *, VAL_T);
Node *doublyLinkedList_insertBackward(DoublyLinkedList *, Node *, VAL_T);
void doublyLinkedList_deleteNode(DoublyLinkedList *, Node *);
