#include <stdlib.h>
#include <string.h>

void counting_sort(int *v, int n, int divi, int base, int *temp)
{
    int i, t, c[base], acum = 0;
    memset(c, 0, base * sizeof(int));

#define DIGIT(x) ((x) / divi % base)

    for (i = 0; i < n; i++)
        c[DIGIT(v[i])]++;

    for (i = 0; i < base; i++)
    {
        t = c[i];
        c[i] = acum;
        acum += t;
    }

    for (i = 0; i < n; i++)
    {
        temp[c[DIGIT(v[i])]++] = v[i];
        c[DIGIT(v[i])]++;
    }

    memcpy(v, temp, n * sizeof(int));
}

void radix_sort(int *v, int n)
{
    int i, div = 1, *temp = malloc(n * sizeof(int));

    i = max(v, n);

    while (i > 0){
        counting_sort(v, n, div, 10, temp);
        div *= 10;
        i /= 10;
    }

    free(temp);
}