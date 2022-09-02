#include "merge.h"
#include <stdio.h>

void printArray(int *v, int n) {
  for (int i = 0; i < n; i++) {
    printf(" %d ", v[i]);
  }
  printf("\n");
}

int main(int argc, char **argv) {
  int v[] = {3, 5, 6, 0, 4, 7};

  printArray(v, 6);
  merge(v, 0, 2, 5);
  printArray(v, 6);

  return 0;
}