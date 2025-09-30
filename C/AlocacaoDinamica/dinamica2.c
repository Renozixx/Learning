#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct{
	int faltas;
	float media;
}t_boletim;

int main() {
	int *aluno;
	t_boletim **boletim;
    int m, n, i, j;
	
	printf("\n\n\n");
	setlocale(LC_ALL,"Portuguese");
    printf("Digite o número de alunos: ");
    scanf("%d", &m);
    
    printf("Digite o número de disciplinas: ");
    scanf("%d", &n);
    
	// Aloca memória para 'm' alunos
    aluno = (int*) malloc(m * sizeof(int));
    if (aluno == NULL) {
        printf("Erro: Memória insuficiente.\n");
        return 1;
    }
    
    // Aloca memória para 'm' alunos e 'n' disciplinas
    boletim = (t_boletim**) malloc(m * sizeof(t_boletim*));
    if (boletim == NULL) {
        printf("Erro: Memória insuficiente.\n");
        return 1;
    }
    
	for(i=0; i<m; i++){
    	boletim[i] = (t_boletim*) calloc(n,sizeof(t_boletim));	
	    if (boletim[i] == NULL) {
    	    printf("Erro: Memória insuficiente.\n");
        	return 1;
    	}
	}
	
	for(i=0; i<m; i++){
		aluno[i] = i + rand()%1000;
	}
	
	for(i=0; i<m; i++){
		for(j=0; j<n; j++){
			boletim[i][j].faltas = rand()%40;
			boletim[i][j].media  = rand()%11;	
		}
	}
    
    printf("\nBoletim dos alunos ***\n");
    printf("ALUNO\t");
    for(i=0; i<n; i++) printf("DISCIPLINA %d\t",i+1);
    printf("\n\t");
	for(i=0; i<n; i++) printf(" F    M\t\t");
    printf("\n");
    for(i=0; i<m; i++){
    	printf("%4d\t",aluno[i]);
		for(j=0; j<n; j++){
			printf("%2d  %4.1f\t",boletim[i][j].faltas,boletim[i][j].media);
		}
		printf("\n");
	}
	
    
	// Libera a memória alocada
    free(aluno);
    free(boletim);

    return 0;
}

