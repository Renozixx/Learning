#include <stdio.h>

int main(void) {
    // fp = fopen("arquivo", "modoDeLeitura");
    // modo -> "r": read | "a": Se nao exitir cria, caso exista ele altera | "w": write, sobrescreve o arquivo
    // fscanf(fp, "%formato", &oqvcquer) -> Ler 
    // fprintf(fp, "%formato", oqvcquer) -> Escrever
    // fclose(fp) -> Fecha o arquivo *NECESSARIO*
    int i, j, k;
    FILE *fp = fopen("./arquivosTeste/teste1.txt", "w");

    for(i = 0; i < 3; i++){
        scanf("%d", &k);
        fprintf(fp, "%d \n", k);
    }

    for(i = 0; i < 3; i++){
        fscanf(fp, "%d \n");
    }
    fclose(fp);
    return 0;
}