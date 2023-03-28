#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "countingSort.h"

int returnMaxPosition(Info *v, int n)
{
    int maior = 0;

    for (int i = 1; i < n; i++)
    {
        if (v[i].Key > v[maior].Key)
        {
            maior = i;
        }
    }
    return v[maior].Key;
}

void countingSort(Info *v, int n)
{
    int i, j, k, t, acum = 0;
    int *c;
    Info *s;

    k = returnMaxPosition(v, n);
    c = calloc(k + 1, sizeof(int));
    s = malloc(n * sizeof(Info));

    for (j = 0; j < n; j++)
    {
        c[v[j].Key]++;
    }

    for (i = 0; i <= k; i++)
    {
        t = c[i];
        c[i] = acum;
        acum += t;
    }
    for (i = 0; i < n; i++)
    {
        s[c[v[i].Key]] = v[i];
        c[v[i].Key]++;
    }
    memcpy(v, s, n * sizeof(Info));
    free(s);
    free(c);
}