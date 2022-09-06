#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

void merge(int *v, int p, int q, int r)
{
  int n1 = q - p + 1;
  int n2 = r - q;

  int *left = malloc(sizeof(int) * (n1 + 1));
  int *right = malloc(sizeof(int) * (n2 + 1));

  int i, j, k;

  for (i = 0; i < n1; i++)
  {
    left[i] = v[p + i];
  }

  left[n1] = INT_MAX;

  for (j = 0; j < n2; j++)
  {
    right[j] = v[q + 1 + j];
  }

  right[n2] = INT_MAX;

  i = 0;
  j = 0;

  for (k = p; k <= r; k++)
  {
    if (left[i] <= right[j])
    {
      v[k] = left[i];
      i++;
    }
    else
    {
      v[k] = right[j];
      j++;
    }
  }

  free(left);
  free(right);
}

void mergeSort(int *v2, int left, int right)
{
  if (left < right)
  {
    int m = (left + right) / 2;
    mergeSort(v2, left, m);
    mergeSort(v2, m + 1, right);
    merge(v2, left, m, right);
  }

}