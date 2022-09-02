#include "selectionSort.h"
#include <stdio.h>
#include <stdlib.h>

void printArray(int *v, int n) {
  for (int i = 0; i < n; i++) {
    printf(" %d ", v[i]);
  }
  printf("\n");
}

int main(int argc, char **argv) {
  //   int v[] = {3, 0, 2, 6, 5};
  int n;

  scanf("%d", &n);

  int *v = malloc(sizeof(int) * n);

  for (int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
  }

  printf("tamanho vetor : %d\n", n);

  // printArray(v,n);
  selectionSort(v, n);
  printArray(v, n);
  free(v);
  return 0;
}