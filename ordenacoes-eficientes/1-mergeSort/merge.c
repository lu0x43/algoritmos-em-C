#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#define DEBUG 0

// A função une duas partes ordenadas de um vetor em uma única parte ordenada.
// p = posicao inicia do subvetor esquerdo, ou seja, o inicio do vetor
// q = metade do vetor (posicao final do subvetor esquerdo), ou seja, (posicao inicial do subvetor direito) - 1
// r = posicao final do subvetor direito, ou seja, o tamanho do vetor - 1
void merge(int *v, int p, int q, int r)
{
  // Calcula o tamanho dos subvetores esquerdo e direito.
  int n1 = q - p + 1;
  int n2 = r - q;

  // Aloca espaço para os subvetores esquerdo e direito.
  int *e = malloc(sizeof(int) * (n1 + 1));
  int *d = malloc(sizeof(int) * (n2 + 1));

  // Copia os valores dos subvetores esquerdo e direito para os vetores auxiliares.
  int i, j, k;
  // i = indice do subvetor esquerdo
  // j = indice do subvetor direito
  // k = indice do vetor original

  for (i = 0; i < n1; i++)
  {
    // e[i] = valor da posicao final do subvetor esquerdo
    e[i] = v[p + i]; // Cópia dos valores do subvetor esquerdo.
    // p = posicao inicial do subvetor esquerdo
    // i = tamanho(indice) do subvetor esquerdo
    // o indice(tamanho) do subvetor esquerdo é p + i
    // p + i = posicao final do subvetor esquerdo
    // v[p + i] = valor da posicao final do subvetor esquerdo
  }

  e[n1] = INT_MAX; // Adiciona um valor máximo para indicar o final do subvetor esquerdo.

  for (j = 0; j < n2; j++)
  {
    d[j] = v[q + 1 + j]; // Cópia dos valores do subvetor direito.
  }

  d[n2] = INT_MAX; // Adiciona um valor máximo para indicar o final do subvetor direito.

  i = 0;
  j = 0;

  // Intercala os valores dos subvetores esquerdo e direito em um único vetor ordenado.
  for (k = p; k <= r; k++)
  {
    if (e[i] <= d[j])
    {
      v[k] = e[i];
      i++;
    }
    else
    {
      v[k] = d[j];
      j++;
    }
  }

  // Libera o espaço alocado para os subvetores esquerdo e direito.
  free(e);
  free(d);
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

// void merge_sort( int *v, int left, int right){
//   mergeSort(v, left, right);
// }