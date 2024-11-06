#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char nome[50];
    float salario;
} registro;

void gravarArquivoBin(const char* nomeArquivo, 
                        registro* registros, 
						int quantidade) {
    int i;
    
	FILE* arquivo = fopen(nomeArquivo, "rb");
    
    if(arquivo==NULL){
    	arquivo = fopen(nomeArquivo, "wb");
    	printf("Comando de criacao de arquivo executado!\n");
	} 
    else {
    	fclose(arquivo);
    	arquivo = fopen(nomeArquivo, "ab");
    	printf("Comando de abertura de arquivo executado!\n");
	}
    
	if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para grava��o!\n");
        return;
    }
    
    fwrite(registros, sizeof(registro), quantidade, arquivo);

    fclose(arquivo);
    printf("Registros gravados com sucesso!\n");
}

void lerArquivoBin(const char* nomeArquivo) {
    FILE* arquivo = fopen(nomeArquivo, "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para leitura!\n");
        return;
    }

    registro reg;
    
    while (fread(&reg, sizeof(registro), 1, arquivo)) {
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

    const char* nomeArquivo = "registros.dat";

    gravarArquivoBin(nomeArquivo, reg, qt);

    printf("\nRegistros no arquivo:\n");
    lerArquivoBin(nomeArquivo);

    return 0;
}