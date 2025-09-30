#include <stdio.h>

typedef struct registro {
    int id;
    char* nome;
    int idade;
} registro;

int main(void)
{
    int i, j;
    char* nomeArquivo = ".\\arquivosTeste\\registros.txt";
    registro funcionarios[3];
    for(int i = 0; i < 3; i++){
        scanf("%d", &funcionarios[i].id);
        scanf("%s", &funcionarios[i].nome);
        scanf("%d", &funcionarios[i].idade);
    }


    FILE* fp = fopen(nomeArquivo, "r");
    
    if (fp == NULL)
    { 
        fp = fopen(nomeArquivo, "w");
        printf("Comando de criacao de arquivo executado!\n");
    }
    else 
    {
        fclose(fp);
        fp = fopen(nomeArquivo, "a");    
        printf("Comando de Abertura de arquivo executada com sucesso");
    }

    if(fp == NULL)
    {
        printf("Erro ao abrir o arquivo");
        return 1;
    }

    for(i = 0; i < 3; i++)
    {
        fprintf(fp, "%d %s %d \n", funcionarios[i].id, funcionarios[i].nome, funcionarios[i].idade);
    }
    return 0;
}

void EscreverArquivo(const char* nomeArquivo, registro* Funcionarios[])
{

}

void LerArquivo(const char* nomeArquivo)
{
    FILE *fp = fopen(nomeArquivo, "r");
    if (fp == NULL)
    {
        printf("Não foi possivel abrir o arquivo!");
    }

}