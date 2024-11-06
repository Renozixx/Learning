// Manipulação de arquivos em C, não tem muito o que explicar, é bem intuitivo, ele faz a leitura e escrita de arquivos texto!
// Crie um programa que armazene um historico de vendas de uma mercado;
// Voce vai colocar dentro desse historico o "Nome_do_produto Unidades_Vendidas Dia_da_venda Unidades_que_restam";
// O menu seve seguir o modelo
// 1 - Inserir venda
// 2 - Ver Historico
// 3 - Sair

#include <stdio.h>

typedef struct vendas
{
    char *nomeProd[100];
    int uniVend;
    char *diaVenda[10];
    int uniRest;
} vendas;

void salvarArquivo(char *);
void lerArquivo(char *);

int main(void) {
    int qt, menu;
    const char *nomeArquivo = "vendas.dat";
    do
    {
        printf("------ MENU ------\n");
        printf("1. Salvar novas vendas\n2. Acessar o historico de vendas\n3. Sair\nOpcao : ");
        scanf("%d", &menu);
        switch (menu)
        {
        case 1:
            salvarArquivo(nomeArquivo);
            break;
        case 2:
            lerArquivo(nomeArquivo);
            break;
        default:
            break;
        }
    } while (menu != 3);
    return 0;
}

void salvarArquivo(char *nomeArquivo)
{
    int qt, i;
    FILE *fp = fopen(nomeArquivo, "ab");
    
    if (fp == NULL){
        printf("Erro ao abrir o arquivo \n");
        return;
    }
    
    printf("Informe quantas vendas voce deseja inserir : ");
    scanf("%d", &qt);
    vendas venda[qt];
    for(i = 0; i < qt; i++){
        printf("Nome do produto : ");
        scanf("%s", &venda[i].nomeProd);
        printf("Unidades vendidas : ");
        scanf("%d", &venda[i].uniVend);
        printf("(modelo: DD/MM/AAAA)\n");
        printf("Data da venda : ");
        scanf("%s", &venda[i].diaVenda);
        printf("Unidades Restantes : ");
        scanf("%d", &venda[i].uniRest);
    }
    fwrite(venda, sizeof(vendas), qt, fp);
    fclose(fp);    
}

// Essa funçã faz a leitura do arquivo binario
void lerArquivo(char *nomeArquivo){
    FILE *fp = fopen(nomeArquivo, "rb");

    if (fp == NULL){
        printf("Erro ao abrir o arquivo para leitura");
        return;
    }

    vendas venda;

    printf("Nome Produto\t\tUnidades Vendidas\tDia da venda\tUnidadaes Restantes\n");
    // estou lendo cada linhas do arquivo binario
    while (fread(&venda, sizeof(vendas), 1, fp))
    {
        printf("%15s\t\t\t %4d\t\t %10s\t\t %4d\n", venda.nomeProd, venda.uniVend, venda.diaVenda, venda.uniRest);
    }
    
}
