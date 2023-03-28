#include <stdio.h>
#include <stdlib.h>
#include "quick.h"

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
    int numRand = atoi(argv[1]);
    int *vRand = randArray(numRand, 99, numRand * 100);

    printf("Array desordenado: ");
    printArray(vRand, numRand);

    quickSort(vRand, 0, numRand - 1);
    printArray(vRand, numRand);

    return 0;
}