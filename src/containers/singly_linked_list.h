#pragma once

#include "node.h"

typedef struct SinglyLinkedList {
  Node *head;
  Node *tail;
  int len;
} SinglyLinkedList;

SinglyLinkedList *singlyLinkedList_new();
void singlyLinkedList_destroy(SinglyLinkedList *);
int singlyLinkedList_length(SinglyLinkedList *);
Node *singlyLinkedList_head(SinglyLinkedList *);
Node *singlyLinkedList_tail(SinglyLinkedList *);
Node *singlyLinkedList_pushFront(SinglyLinkedList *, VAL_T);
Node *singlyLinkedList_pushBack(SinglyLinkedList *, VAL_T);
Node *singlyLinkedList_findNode(SinglyLinkedList *, Node *, VAL_T);
void singlyLinkedList_deleteNode(SinglyLinkedList *, Node *);
