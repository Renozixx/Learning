#include <stdio.h>

typedef struct personagem 
{
    char* nome[50];
    int vida;
    int ataque;
    int mana;
} personagem;

void abirArquivo(char* nomeArquivo);
void escreverArquivo(char* nomeArquivo);
void lerArquivo(char* nomeArquivo);

int main()
{
    char* nomeArquivo = "exercicio.txt";
    int menu = 0;
    do {    
        printf("1.Abrir Arquivo\n2.Inserir Dados\n3.Exibir dados\n4.Sair\nOpcao: ");
        scanf("%d", &menu);
        switch (menu)
        {
        case 1:
            abirArquivo(nomeArquivo);
            break;
        case 2:
            escreverArquivo(nomeArquivo);
            break;
        case 3:
            lerArquivo(nomeArquivo);
            break;
        case 4:
            printf("Obrigado pela preferencia!");
            break;
        default:
            printf("Escolha uma opcao possivel");
            break;
        }
    } while (menu != 4);
}

void abirArquivo(char* nomeArquivo)
{
    FILE* fp = fopen(nomeArquivo, "r");
    if(fp == NULL)
    { 
        fp = fopen(nomeArquivo, "w");
        printf("Arquivo criado com sucesso!");
    }
    else{
        fp = fopen(nomeArquivo, "a");
        printf("Arquivo aberto com sucesso");
    }
    fclose(fp);
}

void escreverArquivo(char* nomeArquivo)
{
    FILE* fp = fopen(nomeArquivo, "a");
    personagem meupersonagem;
    if(fp == NULL){
        printf("Erro ao abrir arquivo para gravação");
        fclose(fp);
        return;
    }
    scanf("%s", &meupersonagem.nome);
    scanf("%d", &meupersonagem.vida);
    scanf("%d", &meupersonagem.ataque);
    scanf("%d", &meupersonagem.mana);
    fprintf(fp, "%s %d %d %d", meupersonagem.nome, meupersonagem.vida, meupersonagem.ataque, meupersonagem.mana);
    fclose(fp);
}

void lerArquivo(char* nomeArquivo)
{
    FILE* fp = fopen(nomeArquivo, "r");
    personagem per;
    if(fp == NULL)
    {
        fclose(fp);
        printf("Erro ao abrir arquivo para leitura");
        return;
    }
    while (fscanf(fp, "%49s %d %d %d", &per.nome, &per.vida, &per.ataque, &per.mana) != EOF)
    {
        printf("Personagem: %s \nVida: %d | Ataque: %d | Mana: %d\n", per.nome, per.vida, per.ataque, per.mana);
    }   
    fclose(fp);
}