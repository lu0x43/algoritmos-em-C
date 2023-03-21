#include "insertionSort.h"
#include <stdio.h>
#include <stdlib.h>

void printArray(int *v, int n)
{
  for (int i = 0; i < n; i++)
  {
    printf(" %d ", v[i]);
  }
  printf("\n");
}

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

int *orderlyArray(int n)
{
  int *v = malloc(sizeof(int) * n);
  for (int i = 0; i < n; i++)
  {
    v[i] = i;
  }
  return v;
}

int main(int argc, char **argv)
{
  int n = atoi(argv[1]);
  int *v = randArray(n, 99, n * 100);
  int *v2 = orderlyArray(n);
  // #ifdef DEBUG
    printf("vetor randomico\n");
    printArray(v, n);
    insertionSort(v, n);
    printf("\n");
    printArray(v, n);

    printf("\nvetor ordenado\n");
    printArray(v2, n);
    insertionSort(v2, n);
    printf("\n");
    printArray(v2, n);
  // #endif

  free(v);
  free(v2);

  return 0;
}