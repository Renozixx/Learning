#include <stdio.h>

#define N 8

int main(void)
{
    int matriz[N][N], i, j;
    printf("Verificador de simetria de matriz 8x8\n");
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            scanf("%d", &matriz[i][j]);
        }
    }
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (matriz[i][j] == matriz[j][i])
            {
                continue;
            }    
            else
            {
                printf("A matriz nao e simetrica");
                return 1;
            }
        }
    }
    printf("A matriz e simetrica");
    return 0;
}