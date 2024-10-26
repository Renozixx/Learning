// Exercicio 02 - Capitulo 10 
// ------------- RECOMENDA-SE QUE caso vc não entenda structs e similares, volte ao arquivo struct.txt e leia
#include <stdio.h>
#include <stdlib.h>

#define SalMin 550.00
#define N 18

// No exercicio Pede para executar a criação da folha de pagamento de funcionarios de uma empresa, e para executar
// Essa tarefa são necessarias as seguintes informações
// Nome, Numeros de Horas trabalhadas, Turno, Categoria e o valor das horas trabalhadas
typedef struct Funcionario {
    char *Nome[30];
    int NumDeHoras;
    char Turno;
    char cat;
    float valor;
    float SalarioInicial;
    float ValeAlimentacao;
    float SalarioFinal;
} Funcionario;

Funcionario CadastrarFuncionario();

int main(void)
{
    int i = 0, j = 0, menu = 0;
    // Criando um array com o numero maximo de funcionarios
    Funcionario Funcionarios[N];
    // Criando o Menu
    do 
    {
        printf("---- Menu de Opcoes ----\n");
        printf("1. Cadastrar Funcionario\n2. Mostrar folha de pagamento.\n3. Sair.\nEscolha sua opcao: ");
        scanf("%d", &menu);
        switch (menu)
        {
        case 1:
            Funcionarios[i] = CadastrarFuncionario();
            i++;
            break;
        case 2:
            printf("NOME\tNUMERO DE HORAS TRABALHADAS\tVALOR DA HORA\tSALARIO INICIAL\tVALE ALIMENTACAO\tSALARIO FINAL");
            for(j = 0; j < i; j++)
            {
                printf("\n%s\t\t%d\t\t%.2f\t\tR$ %.2f\t\tR$ %.2f\t\tR$ %.2f\n", Funcionarios[j].Nome, Funcionarios[j].NumDeHoras, Funcionarios[j].valor, Funcionarios[j].SalarioInicial, Funcionarios[j].ValeAlimentacao, Funcionarios[j].SalarioFinal);
            }
            break;
        case 3:
            printf("Ate Logo\n");
            break;
        default:
            printf("Opcao Invalida\n");
            break;
        }
    } while (menu != 3);
    return 0;
}

    // int NumDeHoras;

// Essa função serve para cadastrar um novo Funcionario na tabela de usuarios;
Funcionario CadastrarFuncionario()
{
    Funcionario FuncionarioParc;
    printf("Nome: ");
    scanf("%s", &FuncionarioParc.Nome);
    printf("Numero de horas Trabalhadas: ");
    scanf("%d", &FuncionarioParc.NumDeHoras);
    // do
    // {
    printf("Turno: ");
    scanf(" %c", &FuncionarioParc.Turno);
    //     printf("%d", FuncionarioParc.Turno);
    // } while (FuncionarioParc.Turno != 78 || FuncionarioParc.Turno != 86 || FuncionarioParc.Turno != 77);
    // do
    // {
    printf("Categoria: ");
    scanf(" %c", &FuncionarioParc.cat);
    // } while (FuncionarioParc.cat != 71 || FuncionarioParc.cat != 79);
    if (FuncionarioParc.cat == 71)
    {
        if (FuncionarioParc.Turno == 78)
        {
            FuncionarioParc.valor = (0.18*SalMin);
            FuncionarioParc.SalarioInicial = FuncionarioParc.valor*(float)FuncionarioParc.NumDeHoras;
            if(FuncionarioParc.SalarioInicial <= 550){
                FuncionarioParc.ValeAlimentacao = FuncionarioParc.SalarioInicial*0.2;
                FuncionarioParc.SalarioFinal = FuncionarioParc.SalarioInicial + FuncionarioParc.ValeAlimentacao;
            }
            else if (FuncionarioParc.SalarioInicial >= 800)
            {
                FuncionarioParc.ValeAlimentacao = FuncionarioParc.SalarioInicial*0.05;
                FuncionarioParc.SalarioFinal = FuncionarioParc.SalarioInicial + FuncionarioParc.ValeAlimentacao;
            }
            else
            {
                FuncionarioParc.ValeAlimentacao = FuncionarioParc.SalarioInicial*0.15;
                FuncionarioParc.SalarioFinal = FuncionarioParc.SalarioInicial + FuncionarioParc.ValeAlimentacao;
            }
        }
        else
        {
            FuncionarioParc.valor = (0.15*SalMin);
            FuncionarioParc.SalarioInicial = FuncionarioParc.valor*(float)FuncionarioParc.NumDeHoras;
            if(FuncionarioParc.SalarioInicial <= 550){
                FuncionarioParc.ValeAlimentacao = FuncionarioParc.SalarioInicial*0.2;
                FuncionarioParc.SalarioFinal = FuncionarioParc.SalarioInicial + FuncionarioParc.ValeAlimentacao;
            }
            else if (FuncionarioParc.SalarioInicial >= 800)
            {
                FuncionarioParc.ValeAlimentacao = FuncionarioParc.SalarioInicial*0.05;
                FuncionarioParc.SalarioFinal = FuncionarioParc.SalarioInicial + FuncionarioParc.ValeAlimentacao;
            }
            else
            {
                FuncionarioParc.ValeAlimentacao = FuncionarioParc.SalarioInicial*0.15;
                FuncionarioParc.SalarioFinal = FuncionarioParc.SalarioInicial + FuncionarioParc.ValeAlimentacao;
            }
        }
    }
    else
    {
        if (FuncionarioParc.Turno == 78)
        {
            FuncionarioParc.valor = (0.13*SalMin);
            FuncionarioParc.SalarioInicial = FuncionarioParc.valor*(float)FuncionarioParc.NumDeHoras;
            if(FuncionarioParc.SalarioInicial <= 550){
                FuncionarioParc.ValeAlimentacao = FuncionarioParc.SalarioInicial*0.2;
                FuncionarioParc.SalarioFinal = FuncionarioParc.SalarioInicial + FuncionarioParc.ValeAlimentacao;
            }
            else if (FuncionarioParc.SalarioInicial >= 800)
            {
                FuncionarioParc.ValeAlimentacao = FuncionarioParc.SalarioInicial*0.05;
                FuncionarioParc.SalarioFinal = FuncionarioParc.SalarioInicial + FuncionarioParc.ValeAlimentacao;
            }
            else
            {
                FuncionarioParc.ValeAlimentacao = FuncionarioParc.SalarioInicial*0.15;
                FuncionarioParc.SalarioFinal = FuncionarioParc.SalarioInicial + FuncionarioParc.ValeAlimentacao;
            }
        }
        else
        {
            FuncionarioParc.valor = (0.1*SalMin);
            FuncionarioParc.SalarioInicial = FuncionarioParc.valor*(float)FuncionarioParc.NumDeHoras;
            if(FuncionarioParc.SalarioInicial <= 550){
                FuncionarioParc.ValeAlimentacao = FuncionarioParc.SalarioInicial*0.2;
                FuncionarioParc.SalarioFinal = FuncionarioParc.SalarioInicial + FuncionarioParc.ValeAlimentacao;
            }
            else if (FuncionarioParc.SalarioInicial >= 800)
            {
                FuncionarioParc.ValeAlimentacao = FuncionarioParc.SalarioInicial*0.05;
                FuncionarioParc.SalarioFinal = FuncionarioParc.SalarioInicial + FuncionarioParc.ValeAlimentacao;
            }
            else
            {
                FuncionarioParc.ValeAlimentacao = FuncionarioParc.SalarioInicial*0.15;
                FuncionarioParc.SalarioFinal = FuncionarioParc.SalarioInicial + FuncionarioParc.ValeAlimentacao;
            }
        }
    }
    return FuncionarioParc;
}