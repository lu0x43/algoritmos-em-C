#include "merge.h"
#include <stdio.h>

void printArray(int *v, int n)
{
  for (int i = 0; i < n; i++)
  {
    printf("%d, ", v[i]);
  }
  printf("\n");
}

int main()
{
  int v[] = {3, 5, 6, 0, 4, 7};
  int v2[] = {2, 8, 6, 0, 1, 7};
  int left = 0, right = 5;
  int n = sizeof(v) / sizeof(int);
  int n2 = sizeof(v2) / sizeof(int);

  printf("Size of array: %d \n\nVetor:", n);
  printArray(v, n);

  printf("Merge:\n");
  merge(v, 0, 2, 5);
  printArray(v, n);

  printf("\nMerge Sort:\n");
  mergeSort(v2, left, right);
  printArray(v2, n2);

  return 0;
}