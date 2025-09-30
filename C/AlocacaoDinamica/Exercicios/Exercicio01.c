/*
Faça um programa que preencha um vetor com oito números inteiros,
calcule e mostre dois vetores resultantes. O primeiro vetor 
resultante deve conter os números positivos e o segundo, 
os numeros negativos.
Cada vetor resultante vai ter, no máximo, oito posições, que não 
poderão ser completamente utilizadas.
*/
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *arr1, *arr2, *arr3, n, nPos = 0, nNeg = 0, i, num;

    printf("Digite o tamanho do array: ");
    scanf("%d", &n);

    arr1 = (int*) malloc(sizeof(int) * n);
    arr2 = (int*) malloc(sizeof(int) * 2);
    arr3 = (int*) malloc(sizeof(int) * 2);

    for(i = 0; i < n; i++)
    {
        printf("Digite um numero: ");
        scanf("%d", &num);
        if(num < 0)
        {
            printf("Numero negativo \n");
            nNeg++;
            if(nNeg > 2){
                arr3 = (int *) realloc(arr2, sizeof(int) * nNeg);
            }
            arr3[(nNeg - 1)] = num;
        }
        else 
        {
            printf("Numero positivo \n");
            nPos++;
            if(nPos > 2){
                arr2 = (int *) realloc(arr2, sizeof(int) * nPos);
            }
            arr2[(nPos - 1)] = num;
        }
    }
    printf("Os numeros positivos digitados foram os: \n");
    for(i = 0; i < nPos; i++)
    {
        printf("%d - %d\n", (i + 1), arr2[i]);
    }
    printf("Os numeros negativos digitados foram os: \n");
    for(i = 0; i < nNeg; i++)
    {
        printf("%d - %d\n", (i + 1), arr3[i]);
    }
}