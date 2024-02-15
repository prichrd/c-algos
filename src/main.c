#include<stdio.h>
#include<stdlib.h>

#define VAL_T int
#include "containers/stack/stack.h"
#undef VAL_T

int main(int argc, char *argv[]) {
  Stack* stack = stack_new();
  stack_push(stack, 10);
  stack_push(stack, 20);
  stack_push(stack, 30);
  printf("stack of length %d\n", stack_length(stack));
  printf("stack pop: %d\n", stack_pop(stack));
  printf("stack pop: %d\n", stack_pop(stack));
  /* printf("stack pop: %d\n", stack_pop(stack)); */
  stack_destroy(stack);
}
