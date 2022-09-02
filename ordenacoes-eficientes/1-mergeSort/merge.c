#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

void merge(int *v, int p, int q, int r) {
  int n1 = q - p + 1;
  int n2 = r - q;

  int *e = malloc(sizeof(int) * (n1 + 1));
  int *d = malloc(sizeof(int) * (n2 + 1));

  int i, j, k;

  for (i = 0; i < n1; i++) {
    e[i] = v[p + i];
  }

  e[n1] = INT_MAX;

  for (j = 0; j < n2; j++) {
    d[j] = v[q + 1 + j];
  }

  d[n2] = INT_MAX;

  i = 0;
  j = 0;

  for (k = 0; k <= r; k++) {
    if (e[i] <= d[j]) {
      v[k] = e[i];
      i++;
    } else {
      v[k] = d[j];
      j++;
    }
  }

  free(e);
  free(d);
}