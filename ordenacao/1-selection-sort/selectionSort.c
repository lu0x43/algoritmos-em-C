#include <stdio.h>

int returnMaxPosition(int *v, int ini, int fim) {
  // suponhe que a posicao inicial pode ser o maior numero do vetor (nao sabemos
  // se é ou nao)
  int maior = ini; // posicao do maior ja visto

  for (int i = ini + 1; i < fim; i++) {
    if (v[i] > v[maior]) {
      maior = i; // atualiza o maior ja visto
    }
  }
  return maior;
}

void tradeArrays(int *v, int a, int b) {
  int aux = v[a];
  v[a] = v[b];
  v[b] = aux;
}

void selectionSort(int *v, int qtPos) {

  for (int i = qtPos - 1; i > 0; i--) {
    int maior = returnMaxPosition(v, 0, i);
    tradeArrays(v, maior, i);
  }
}