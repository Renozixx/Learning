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

void InserirVenda(char *);
void VerHistorico(char *);

int main(void) {
    int menu;
    do
    {
        printf("Historico de Vendas : \n1 - Adicionar Venda\n2 - Ver Historico\n3 - Sair\nOpcao : ");
        scanf("%d", &menu);
        switch (menu)
        {
        case 1:
            
            break; 
        
        default:
            break;
        }
    } while (menu != 3);
    return 0;
}