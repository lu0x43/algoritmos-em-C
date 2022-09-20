#include <stdio.h>
#include <stdlib.h>

void quickSort( int *v, int left, int right )
{
  int i, j, x, y;
  i = left;
  j = right;
  x = v[(i + j) / 2];
  
  while (left <= right)
  {
    while (v[left] < x && i < right)
    {
      left++;
    }
    while (v[right] > x && right > i)
    {
      right--;
    }
    if (left <= right)
    {
      y = v[left];
      v[left] = v[right];
      v[right] = y;
      left++;
      right--;
    }
  }
  if (right > i)
  {
    quickSort(v, i, right);
  }
  if (left < j)
  {
    quickSort(v, left, j);
  }

  
}