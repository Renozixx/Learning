#include <stdio.h>

int main(void)
{
    int i = 0, j = 0, N, num = 1, N2 = 0, N3;
    scanf("%d", &N);
    int nums[N][N];
    N3 = N;
    while (num <= N*N)
    {
        // Caso 1
        for(j; j < N3; j++)
        {
            nums[i][j] = num;
            printf("Caso 1, %d\n", num);
            num++;
        }
        // Caso 2
        for(i++, j--; i < N3; i++)
        {
            nums[i][j] = num;
            printf("Caso 2, %d\n", num);
            num++;
        }
        N3--;
        // caso 3
        for(i--, j--; j >= N2; j--)
        {
            nums[i][j] = num;
            printf("Caso 3, %d\n", num);
            num++;
        }
        N2++;
        // caso 4
        for(i--, j++; i >= N2; i--)
        {
            nums[i][j] = num;
            printf("Caso 4, %d\n", num);
            num++;
        }
        i++;
        j++;
    }
    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
        {
            printf("%2d ", nums[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}