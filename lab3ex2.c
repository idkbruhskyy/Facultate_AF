#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    float a[50][50];
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);

    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            a[i][j] = rand();
            printf("%.3f ", a[i][j]);
        }
        printf("\n");
    }

    float k1 = -1, k2 = 1, x1 = 0, x2 = RAND_MAX;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            a[i][j] = (k2 - k1) * (a[i][j] - x1) / (x2 - x1) + k1;
            printf("%.3f ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}