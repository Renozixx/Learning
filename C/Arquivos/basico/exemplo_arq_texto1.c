#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char nome[50];
    float salario;
} registro;

void gravarArquivoTexto(const char* nomeArquivo, 
                        registro* registros, 
						int quantidade) {
    int i;
    
	FILE* arquivo = fopen(nomeArquivo, "r");
    
    if(arquivo==NULL){
    	arquivo = fopen(nomeArquivo, "w");
    	printf("Comando de criacao de arquivo executado!\n");
	} 
    else {
    	fclose(arquivo);
    	arquivo = fopen(nomeArquivo, "a");
    	printf("Comando de abertura de arquivo executado!\n");
	}
    
	if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para grava��o!\n");
        return;
    }

    for (i = 0; i < quantidade; i++) {
        fprintf(arquivo, "%d %s %.2f\n",registros[i].id, registros[i].nome, 
		                                registros[i].salario);
    }

    fclose(arquivo);
    printf("Registros gravados com sucesso!\n");
}

void lerArquivoTexto(const char* nomeArquivo) {
    FILE* arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para leitura!\n");
        return;
    }

    registro reg;
    
    while (fscanf(arquivo, "%d %49s %f", &reg.id, reg.nome, &reg.salario) != EOF) {
        printf("ID: %d, Nome: %s, Salario: %.2f\n", reg.id, reg.nome, reg.salario);
    }

    fclose(arquivo);
}

int main() {
   
    registro reg[3] = {
        {1, "Joao", 2500.50},
        {2, "Maria", 3200.75},
        {3, "Carlos", 4100.00}
    };
    
    int qt = 3;

    const char* nomeArquivo = "registros.txt";

    gravarArquivoTexto(nomeArquivo, reg, qt);

    printf("\nRegistros no arquivo:\n");
    lerArquivoTexto(nomeArquivo);

    return 0;
}
