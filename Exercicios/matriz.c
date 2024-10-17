#include <stdio.h>

#define N 3
#define M 4

void troca(int *, int*);

int main(void)
{
    int medalhas[N][M];

    for (int i = 0; i < N; i++)
    {
        printf("Pais %d\n", i);
        printf("medalhas de ouro..: "); scanf("%d", &medalhas[i][0]);
        printf("medalhas de prata.: "); scanf("%d", &medalhas[i][1]);
        printf("medalhas de bronze: "); scanf("%d", &medalhas[i][2]);
        medalhas[i][3] = medalhas[i][0] + medalhas[i][1] + medalhas[i][2];
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = i+1; j < N; j++)
        {
            printf("%d %d\n", i, j);
            if (medalhas[i][0] < medalhas[j][0])
            {
                troca(&medalhas[i][0], &medalhas[j][0]);
                troca(&medalhas[i][1], &medalhas[j][1]);
                troca(&medalhas[i][2], &medalhas[j][2]);
                troca(&medalhas[i][3], &medalhas[j][3]);
            }
            else if (medalhas[i][0] == medalhas[j][0] || medalhas[i][1] < medalhas[j][1])
            {
                troca(&medalhas[i][0], &medalhas[j][0]);
                troca(&medalhas[i][1], &medalhas[j][1]);
                troca(&medalhas[i][2], &medalhas[j][2]);
                troca(&medalhas[i][3], &medalhas[j][3]);
            }
            else if (medalhas[i][0] == medalhas[j][0] || medalhas[i][1] == medalhas[j][1] || medalhas[i][2] < medalhas[j][2])
            {
                troca(&medalhas[i][0], &medalhas[j][0]);
                troca(&medalhas[i][1], &medalhas[j][1]);
                troca(&medalhas[i][2], &medalhas[j][2]);
                troca(&medalhas[i][3], &medalhas[j][3]);
            }
        }
    }
    printf("PAIS\tOURO\tPRATA\tBRONZE\tTOTAL\n");
    for (int i = 0; i < N; i++)
    {
        printf("%d\t", i);
        for (int j = 0; j < M; j++)
        {
            printf("%3d\t", medalhas[i][j]);
        }
        printf("\n");
    }
    return 0;
}

void troca(int *a, int *b)
{
    int aux;
    aux = *b;
    *b = *a;
    *a = aux;
}
