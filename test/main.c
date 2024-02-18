#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "../src/containers/binary_search_tree.h"
#include "../src/containers/doubly_linked_list.h"
#include "../src/containers/singly_linked_list.h"
#include "../src/containers/stack.h"
#include "./utils.h"

SUITE({
  DESCRIBE("stack", {
    IT("should push and pop elements", {
      Stack *s = stack_new();
      stack_push(s, 10);
      stack_push(s, 20);
      stack_push(s, 30);
      ASSERT(stack_length(s) == 3);
      ASSERT(stack_pop(s) == 30);
      ASSERT(stack_pop(s) == 20);
      ASSERT(stack_pop(s) == 10);
      ASSERT(stack_length(s) == 0);
      stack_destroy(s);
    });
  })

  DESCRIBE("singlyLinkedList", {
    IT("should respect push order", {
      SinglyLinkedList *l = singlyLinkedList_new();
      singlyLinkedList_pushFront(l, 10);
      singlyLinkedList_pushBack(l, 20);
      singlyLinkedList_pushFront(l, 30);
      ASSERT(singlyLinkedList_length(l) == 3);
      ASSERT(l->head->val == 30)
      ASSERT(l->head->right->val == 10)
      ASSERT(l->head->right->right->val == 20)
      ASSERT(l->head->right->right->right == NULL)
      singlyLinkedList_destroy(l);
    });
    IT("should delete head node", {
      SinglyLinkedList *l = singlyLinkedList_new();
      singlyLinkedList_pushBack(l, 10);
      singlyLinkedList_pushBack(l, 20);
      singlyLinkedList_pushBack(l, 30);
      singlyLinkedList_deleteNode(l, singlyLinkedList_head(l));
      ASSERT(singlyLinkedList_length(l) == 2);
      ASSERT(l->head->val == 20)
      ASSERT(l->head->right->val == 30)
      ASSERT(l->head->right->right == NULL)
      singlyLinkedList_destroy(l);
    });
    IT("should delete mid node", {
      SinglyLinkedList *l = singlyLinkedList_new();
      singlyLinkedList_pushBack(l, 10);
      singlyLinkedList_pushBack(l, 20);
      singlyLinkedList_pushBack(l, 30);
      singlyLinkedList_deleteNode(l, l->head->right->right);
      ASSERT(singlyLinkedList_length(l) == 2);
      ASSERT(l->head->val == 10)
      ASSERT(l->head->right->val == 20)
      ASSERT(l->head->right->right == NULL)
      singlyLinkedList_destroy(l);
    });
    IT("should delete tail node", {
      SinglyLinkedList *l = singlyLinkedList_new();
      singlyLinkedList_pushBack(l, 10);
      singlyLinkedList_pushBack(l, 20);
      singlyLinkedList_pushBack(l, 30);
      singlyLinkedList_deleteNode(l, singlyLinkedList_tail(l));
      ASSERT(singlyLinkedList_length(l) == 2);
      ASSERT(l->head->val == 10)
      ASSERT(l->head->right->val == 20)
      ASSERT(l->head->right->right == NULL)
      singlyLinkedList_destroy(l);
    });
    IT("should find from specified node", {
      SinglyLinkedList *l = singlyLinkedList_new();
      singlyLinkedList_pushBack(l, 10);
      singlyLinkedList_pushBack(l, 20);
      singlyLinkedList_pushBack(l, 30);
      singlyLinkedList_pushBack(l, 10);
      ASSERT(singlyLinkedList_findNode(l, l->head->right, 10) == l->tail);
      singlyLinkedList_destroy(l);
    });
    IT("should find from head when NULL from specified", {
      SinglyLinkedList *l = singlyLinkedList_new();
      singlyLinkedList_pushBack(l, 10);
      singlyLinkedList_pushBack(l, 20);
      singlyLinkedList_pushBack(l, 30);
      singlyLinkedList_pushBack(l, 10);
      ASSERT(singlyLinkedList_findNode(l, NULL, 10) == l->head);
      singlyLinkedList_destroy(l);
    });
  });

  DESCRIBE("doublyLinkedList", {
    IT("should respect push order", {
      DoublyLinkedList *l = doublyLinkedList_new();
      doublyLinkedList_pushFront(l, 10);
      doublyLinkedList_pushBack(l, 20);
      doublyLinkedList_pushFront(l, 30);
      ASSERT(doublyLinkedList_length(l) == 3);
      ASSERT(l->head->val == 30)
      ASSERT(l->head->right->val == 10)
      ASSERT(l->head->right->right->val == 20)
      ASSERT(l->head->right->right->right == NULL)
      ASSERT(l->tail->val == 20)
      ASSERT(l->tail->left->val == 10)
      ASSERT(l->tail->left->left->val == 30)
      ASSERT(l->tail->left->left->left == NULL)
      doublyLinkedList_destroy(l);
    });
    IT("should delete head node", {
      DoublyLinkedList *l = doublyLinkedList_new();
      doublyLinkedList_pushBack(l, 10);
      doublyLinkedList_pushBack(l, 20);
      doublyLinkedList_pushBack(l, 30);
      doublyLinkedList_deleteNode(l, l->head);
      ASSERT(l->head->val == 20)
      ASSERT(l->head->right->val == 30)
      ASSERT(l->head->right->right == NULL)
      ASSERT(l->tail->val == 30)
      ASSERT(l->tail->left->val == 20)
      ASSERT(l->tail->left->left == NULL)
      doublyLinkedList_destroy(l);
    });
    IT("should delete mid node", {
      DoublyLinkedList *l = doublyLinkedList_new();
      doublyLinkedList_pushBack(l, 10);
      doublyLinkedList_pushBack(l, 20);
      doublyLinkedList_pushBack(l, 30);
      doublyLinkedList_deleteNode(l, l->head->right);
      ASSERT(doublyLinkedList_length(l) == 2);
      ASSERT(l->head->val == 10)
      ASSERT(l->head->right->val == 30)
      ASSERT(l->head->right->right == NULL)
      ASSERT(l->tail->val == 30)
      ASSERT(l->tail->left->val == 10)
      ASSERT(l->tail->left->left == NULL)
      doublyLinkedList_destroy(l);
    });
    IT("should delete tail node", {
      DoublyLinkedList *l = doublyLinkedList_new();
      doublyLinkedList_pushBack(l, 10);
      doublyLinkedList_pushBack(l, 20);
      doublyLinkedList_pushBack(l, 30);
      doublyLinkedList_deleteNode(l, l->tail);
      ASSERT(doublyLinkedList_length(l) == 2);
      ASSERT(l->head->val == 10)
      ASSERT(l->head->right->val == 20)
      ASSERT(l->head->right->right == NULL)
      ASSERT(l->tail->val == 20)
      ASSERT(l->tail->left->val == 10)
      ASSERT(l->tail->left->left == NULL)
      doublyLinkedList_destroy(l);
    });
    IT("should find node forward from specified node", {
      DoublyLinkedList *l = doublyLinkedList_new();
      doublyLinkedList_pushBack(l, 10);
      doublyLinkedList_pushBack(l, 20);
      doublyLinkedList_pushBack(l, 30);
      doublyLinkedList_pushBack(l, 10);
      ASSERT(doublyLinkedList_findNodeForward(l, l->head->right, 10) ==
             l->tail);
      doublyLinkedList_destroy(l);
    });
    IT("should find node forward from head when NULL from specified", {
      DoublyLinkedList *l = doublyLinkedList_new();
      doublyLinkedList_pushBack(l, 10);
      doublyLinkedList_pushBack(l, 20);
      doublyLinkedList_pushBack(l, 30);
      doublyLinkedList_pushBack(l, 10);
      ASSERT(doublyLinkedList_findNodeForward(l, NULL, 10) == l->head);
      doublyLinkedList_destroy(l);
    });
    IT("should find node backward from specified node", {
      DoublyLinkedList *l = doublyLinkedList_new();
      doublyLinkedList_pushBack(l, 10);
      doublyLinkedList_pushBack(l, 20);
      doublyLinkedList_pushBack(l, 30);
      doublyLinkedList_pushBack(l, 10);
      ASSERT(doublyLinkedList_findNodeBackward(l, l->tail->left, 10) ==
             l->head);
      doublyLinkedList_destroy(l);
    });
    IT("should find node backward from head when NULL from specified", {
      DoublyLinkedList *l = doublyLinkedList_new();
      doublyLinkedList_pushBack(l, 10);
      doublyLinkedList_pushBack(l, 20);
      doublyLinkedList_pushBack(l, 30);
      doublyLinkedList_pushBack(l, 10);
      ASSERT(doublyLinkedList_findNodeBackward(l, NULL, 10) == l->tail);
      doublyLinkedList_destroy(l);
    });
    IT("should insert forward from tail", {
      DoublyLinkedList *l = doublyLinkedList_new();
      doublyLinkedList_pushBack(l, 10);
      doublyLinkedList_pushBack(l, 20);
      doublyLinkedList_insertForward(l, l->tail, 30);
      ASSERT(doublyLinkedList_length(l) == 3);
      ASSERT(l->head->val == 10)
      ASSERT(l->head->right->val == 20)
      ASSERT(l->head->right->right->val == 30)
      ASSERT(l->head->right->right->right == NULL)
      ASSERT(l->tail->val == 30)
      ASSERT(l->tail->left->val == 20)
      ASSERT(l->tail->left->left->val == 10)
      ASSERT(l->tail->left->left->left == NULL)
      doublyLinkedList_destroy(l);
    });
    IT("should insert backward from tail", {
      DoublyLinkedList *l = doublyLinkedList_new();
      doublyLinkedList_pushBack(l, 10);
      doublyLinkedList_pushBack(l, 30);
      doublyLinkedList_insertBackward(l, l->tail, 20);
      ASSERT(doublyLinkedList_length(l) == 3);
      ASSERT(l->head->val == 10)
      ASSERT(l->head->right->val == 20)
      ASSERT(l->head->right->right->val == 30)
      ASSERT(l->head->right->right->right == NULL)
      ASSERT(l->tail->val == 30)
      ASSERT(l->tail->left->val == 20)
      ASSERT(l->tail->left->left->val == 10)
      ASSERT(l->tail->left->left->left == NULL)
      doublyLinkedList_destroy(l);
    });
    IT("should insert backward from head", {
      DoublyLinkedList *l = doublyLinkedList_new();
      doublyLinkedList_pushBack(l, 20);
      doublyLinkedList_pushBack(l, 30);
      doublyLinkedList_insertBackward(l, l->head, 10);
      ASSERT(doublyLinkedList_length(l) == 3);
      ASSERT(l->head->val == 10)
      ASSERT(l->head->right->val == 20)
      ASSERT(l->head->right->right->val == 30)
      ASSERT(l->head->right->right->right == NULL)
      ASSERT(l->tail->val == 30)
      ASSERT(l->tail->left->val == 20)
      ASSERT(l->tail->left->left->val == 10)
      ASSERT(l->tail->left->left->left == NULL)
      doublyLinkedList_destroy(l);
    });
    IT("should insert forward from head", {
      DoublyLinkedList *l = doublyLinkedList_new();
      doublyLinkedList_pushBack(l, 10);
      doublyLinkedList_pushBack(l, 30);
      doublyLinkedList_insertForward(l, l->head, 20);
      ASSERT(doublyLinkedList_length(l) == 3);
      ASSERT(l->head->val == 10)
      ASSERT(l->head->right->val == 20)
      ASSERT(l->head->right->right->val == 30)
      ASSERT(l->head->right->right->right == NULL)
      ASSERT(l->tail->val == 30)
      ASSERT(l->tail->left->val == 20)
      ASSERT(l->tail->left->left->val == 10)
      ASSERT(l->tail->left->left->left == NULL)
      doublyLinkedList_destroy(l);
    });
  });

  DESCRIBE("binarySearchTree", {
    IT("should insert in proper order", {
      BinarySearchTree *t = binarySearchTree_new();
      binarySearchTree_insert(t, 50, 500);
      binarySearchTree_insert(t, 25, 250);
      binarySearchTree_insert(t, 75, 750);
      binarySearchTree_insert(t, 30, 300);
      ASSERT(t->root->key == 50);
      ASSERT(t->root->left->key == 25);
      ASSERT(t->root->right->key == 75);
      ASSERT(t->root->left->right->key == 30);
      binarySearchTree_destroy(t);
    });
    IT("should find root node", {
      BinarySearchTree *t = binarySearchTree_new();
      binarySearchTree_insert(t, 50, 500);
      binarySearchTree_insert(t, 25, 250);
      binarySearchTree_insert(t, 75, 750);
      binarySearchTree_insert(t, 30, 300);
      ASSERT(binarySearchTree_find(t, 50)->key == 50);
      binarySearchTree_destroy(t);
    });
    IT("should find node", {
      BinarySearchTree *t = binarySearchTree_new();
      binarySearchTree_insert(t, 50, 500);
      binarySearchTree_insert(t, 25, 250);
      binarySearchTree_insert(t, 75, 750);
      binarySearchTree_insert(t, 30, 300);
      ASSERT(binarySearchTree_find(t, 25)->key == 25);
      binarySearchTree_destroy(t);
    });
    IT("should find leaf node", {
      BinarySearchTree *t = binarySearchTree_new();
      binarySearchTree_insert(t, 50, 500);
      binarySearchTree_insert(t, 25, 250);
      binarySearchTree_insert(t, 75, 750);
      binarySearchTree_insert(t, 30, 300);
      ASSERT(binarySearchTree_find(t, 30)->key == 30);
      binarySearchTree_destroy(t);
    });
    IT("should remove leaf node", {
      BinarySearchTree *t = binarySearchTree_new();
      binarySearchTree_insert(t, 50, 500);
      binarySearchTree_insert(t, 25, 250);
      binarySearchTree_insert(t, 75, 750);
      binarySearchTree_insert(t, 30, 300);
      binarySearchTree_delete(t, 30);
      ASSERT(t->root->key == 50);
      ASSERT(t->root->left->key == 25);
      ASSERT(t->root->right->key == 75);
      ASSERT(t->root->left->right == NULL);
      binarySearchTree_destroy(t);
    });
    IT("should remove root with one child (left)", {
      BinarySearchTree *t = binarySearchTree_new();
      binarySearchTree_insert(t, 50, 500);
      binarySearchTree_insert(t, 25, 250);
      binarySearchTree_delete(t, 50);
      ASSERT(t->root->key == 25);
      ASSERT(t->root->left == NULL);
      ASSERT(t->root->right == NULL);
      binarySearchTree_destroy(t);
    });
    IT("should remove root with one child (right)", {
      BinarySearchTree *t = binarySearchTree_new();
      binarySearchTree_insert(t, 50, 500);
      binarySearchTree_insert(t, 75, 250);
      binarySearchTree_delete(t, 50);
      ASSERT(t->root->key == 75);
      ASSERT(t->root->left == NULL);
      ASSERT(t->root->right == NULL);
      binarySearchTree_destroy(t);
    });
  });
})

