#include <stdio.h>

int main(void) {
    int N, apoio = 0, i, j, k = 0, num;
    scanf("%d", &N);
    int numeros[N];
    for (i = 0; i < N; i++)
    {
        scanf("%d", &numeros[i]);
    }
    for (i = 0; i < N; i++)
    {
        for (j = i+1; j < N; j++)
        {
            if (numeros[j] > numeros[i])
            {
                apoio++;
            }
        }
    }
    if (apoio == 0)
    {
        apoio++;
    }
    printf("%d\n", apoio);
    return 0;
}