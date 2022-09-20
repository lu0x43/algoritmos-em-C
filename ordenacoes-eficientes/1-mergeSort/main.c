#include "merge.h"
#include <stdio.h>
#include <stdlib.h>

int *randArray(int n, int seed, int max)
{
  srand(seed);
  int *v = malloc(sizeof(int) * n);

  for (int i = 0; i < n; i++)
  {
    v[i] = (rand() % max) + 1;
  }
  return v;
}

void printArray(int *v, int n)
{
  for (int i = 0; i < n; i++)
  {
    printf("%d, ", v[i]);
  }
  printf("\n");
}

int main(int argc, char **argv)
{
  int v[] = {3, 5, 6, 0, 4, 7};
  int n = sizeof(v) / sizeof(int);

  int v2[] = {2, 8, 6, 0, 1, 7};
  int n2 = sizeof(v2) / sizeof(int);

  int numRand = atoi(argv[1]);
  int *vRand = randArray(numRand, 99, numRand * 100);

  int left = 0, right = numRand - 1;

  // printArray(v, n);

  // printf("Merge:\n");
  // merge(v, 0, 2, 5);
  // printArray(v, n);

  printArray(vRand, numRand);
  printf("\nMerge Sort:\n");

  mergeSort(vRand, left, right);
  printArray(vRand, numRand);

  // mergeSort(v2, left, right);
  // printArray(v2, n2);

  return 0;
}