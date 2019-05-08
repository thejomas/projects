#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <limits.h> //INT_MAX
#include <stdbool.h> //true/1

#include "fibHeap.h"

int Init_Node(struct node *node, int x) {
  node->key = x;
  node->degree = 0;
  node->parent = NULL;
  node->child = NULL;
  node->mark = false;
  node->left = node;
  node->right = node;
  return 0;
}

int Insert(struct fib_heap *H, struct node *node) {
  if (H->n == 0) {
    H->min = node;
  }
  else {
    node->left = H->min;
    node->right = (H->min)->right;
    (node->left)->right = node;
    (node->right)->left = node;
    if (node->key < (H->min)->key) {
      H->min = node;
    }
  }
  H->n += 1;
  return 0;
}

int Print_Heap (struct fib_heap *H) {
  if (H->n == 0) printf("Empty");
  struct node *curr = H->min;
  printf("Value of H.min: %d\n", (H->min)->key);
  do {
    printf("Value of node: %d\n", curr->key);
    curr = curr->right;
  } while(curr->key != (H->min)->key);
  return 0;
}
