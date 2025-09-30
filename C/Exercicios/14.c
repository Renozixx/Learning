#include <stdio.h>

typedef char * string;

#define N 5

int main(void)
{
    string cidades[N];
    int i, j, dist[N][N];
    float combust, gasto;
    printf("Digite o nome das cinco cidades\n");
    for (i = 0; i < N ; i++)
    {
        scanf("%s", &cidades[i]);
    }
    for (i = 0; i < N ; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (i == j)
            {
                dist[i][j] = 0;
                continue;
            }
            else 
            {
                printf("A distancia entre %s e %s e de : ", &cidades[i], &cidades[j]);
                scanf("%d", &dist[i][j]);
            }
        }
    }
    printf("Qual é a quantidade de quilometros por litro do seu carro : ");
    scanf("%f", &combust);
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (dist[i][j] < 250 && dist[i][j] != 0)
            {
                printf("A distancia entre %s e %s nao ultrapassa 250Km\n", &cidades[i], &cidades[j]);
            }
        }
    }
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (i == j)
            {
                continue;
            }
            gasto = dist[i][j]/(float)combust;
            printf("Origem -> %s | destino -> %s | Gasto : %.2f\n", &cidades[i], &cidades[j], gasto);
        }
    }    
}