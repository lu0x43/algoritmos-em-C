#include <stdio.h>

void tradeArrays(int *v, int a, int b) {
  int aux = v[a];
  v[a] = v[b];
  v[b] = aux;
}

void bubbleSort(int *v, int n) {
  for (int j = n - 1; j >= 1; j--) {
    for (int i = 0; i < j; i++) {
      if (v[i] > v[i + 1]) {
        tradeArrays(v, i, i + 1);
      }
    }
  }
}
