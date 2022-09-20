#include <stdio.h>
#include <stdlib.h>
#include "countingSort.h"

#define MAX 100

Info *randArray(int n, int seed, int max)
{
    srand(seed);
    Info *v = malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++)
    {
        v[i].Key = (rand() % max) + 1;
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
    int n = atoi(argv[1]);
    //seed atoi argv[2] if null then = 99
    int seed = (argc > 2) ? atoi(argv[2]) : 99;

    Info *v = randArray(n, seed, n*100);
    countingSort(v, n);
    printArray(v, n);
    free(v);
    return 0;
}