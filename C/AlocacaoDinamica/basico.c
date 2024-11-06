#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // malloc() -> Aloca Memoria
    // int *ptr = (int*) malloc(sizeof(int)*int)

    // calloc() -> Aloca memoria, porem com os valores iniciais iguais a zero
    // int *ptr = (int*) calloc(5, sizeof(int))

    // realloc() -> Altera o tamanho da memoria alocada a uma varavel
    // ptr = (int*)realloc(ptr, sizeof(int) * 10)

    // free() -> Libera a memoria usada
    // free(ptr)

    int *ptr, n, i;
    printf("Escolha o tamnho: ");
    scanf("%d", &n);

    ptr = (int*) malloc(sizeof(int) * n);

    for (i = 0; i < n; i++)
    {
        ptr[i] = i*2;
    }
    for (i = 0; i < n; i++)
    {
        printf("%d : %d\n", (i + 1), ptr[i]);
    }

    printf("Escolha um novo tamanho: ");
    scanf("%d", &n);


    ptr = (int*) realloc(ptr, sizeof(int) * n);

    for (i = 0; i < n; i++)
    {
        ptr[i] = i*2;
    }
    for (i = 0; i < n; i++)
    {
        printf("%d : %d\n", (i + 1), ptr[i]);
    }

    return 0;
}