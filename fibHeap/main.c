#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "FibHeap.h"

int main(int argc, const char *argv[]) {
  struct fib_heap *H;
  struct node *node0;
  Init_Node(node0, 5);
  Insert(H, node0);
  struct node *node1;
  Init_Node(node1, 3);
  Insert(H, node1);
  Print_Heap(H);
}
//https://stackoverflow.com/questions/672734/how-to-prevent-multiple-definitions-in-c
