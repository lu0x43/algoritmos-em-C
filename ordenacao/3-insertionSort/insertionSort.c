#include "insertionSort.h"
#include <stdio.h>

void insertion(int *v, int n) {
  int i = n - 1;
  int x = v[n];

  while ((i > 0) && (v[i] > x)) {
    v[i + 1] = v[i];
    i--;
  }
  v[i+1] =x ;
}

void insertionSort(int *v, int n) {
  for (int j = 1; j < n; j++) {
    insertion(v, j);
  }
}
