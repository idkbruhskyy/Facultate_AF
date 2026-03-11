#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void returnare(int *v, int n)
{
    int max1 = -9999;
    int max2 = -9999;
    int min = RAND_MAX;

    for (int i = 0; i < n; i++)
    {
        if (v[i] > max1)
        {
            max2 = max1;
            max1 = v[i];
        }
        else if (v[i] > max2)
            max2 = v[i];
    }
    printf("Al doilea maxim din vector este : %d \n\n", max2);
    for (int i = 0; i < n; i++)
        if (v[i] < min)
        {
            min = v[i];
        }
    printf("Minimul vectorului este : %d \n\n", min);
}

int eliminare(int *v, int n)
{

    int max1 = -9999, max2 = -9999;

    for (int i = 0; i < n; i++)
    {
        if (v[i] > max1)
        {
            max2 = max1;
            max1 = v[i];
        }
        else if (v[i] > max2)
            max2 = v[i];
    }
    int k = -1;
    for (int i = 0; i < n; i++)
        if (v[i] == max2)
        {
            k = i;
            break;
        }
    if (k != -1)
    {
        for (int i = k; i < n - 1; i++)
        {
            v[i] = v[i + 1];
        }
        n--;

        int *v_nou = (int *)realloc(v, n * sizeof(int));
        if (v_nou != NULL)
        {
            v = v_nou;
        }
    }
    return n;
}

int main()
{
    int n = 100;
    int c = 0;

    int *v = (int *)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
        c++;
        if (v[i] == 0)
        {
            break;
        }
    }
    int nr_elem = c - 1;
    returnare(v, nr_elem);

    nr_elem = eliminare(v, nr_elem);

    printf("Vectorul nou este : ");

    for (int i = 0; i < nr_elem; i++)
        printf("%d ", v[i]);
    printf("\n\n");

    free(v);

    return 0;
}
