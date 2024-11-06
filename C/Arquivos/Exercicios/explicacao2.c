#include <stdio.h>

typedef struct personagem{
    char* nome[50];
    int vida;
    int classe;
    int mana;
    int ataque;
} personagem;

typedef struct inimigo{
    char* nome[50];
    int vida;
    int ataque;
} inimigo;

void MenuPersonagem();
void abrirArquivo(char *);
void inserirDados(char *);
void lerArquivo(char *);

int main(void)
{
    int menu;
    do
    {
        printf("Escolha uma das opcoes abaixo : \n1 - Criar Personagem\n2 - Criar Inimigo\n3 - Iniciar Batalha\nOpcao : ");
        scanf("%d", &menu);
        switch (menu)
        {
        case 1:
            MenuPersonagem();           
            break;
        
        default:
            break;
        }
    } while (menu != 4);
    
    return 0;
}

void MenuPersonagem()
{
    char * nomeArquivo = 'personagens.txt';
    
}