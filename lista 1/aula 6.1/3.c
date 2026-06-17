#include <stdio.h>
#include <string.h>

#define MAX_ALUNOS 3


typedef struct {
    char nome[50];
    float nota;
} Aluno;

int main() {
    Aluno turma[MAX_ALUNOS];
    int i;
    int indiceMaior = 0;
    int indiceMenor = 0;

    
    for (i = 0; i < MAX_ALUNOS; i++) {
        printf("--- Aluno %d ---\n", i + 1);
        printf("Nome: ");
        scanf(" %49[^\n]", turma[i].nome); 
        printf("Nota: ");
        scanf("%f", &turma[i].nota);

        
        if (i == 0) {
            indiceMaior = 0;
            indiceMenor = 0;
        } else {
            
            if (turma[i].nota > turma[indiceMaior].nota) {
                indiceMaior = i;
            }
            
            if (turma[i].nota < turma[indiceMenor].nota) {
                indiceMenor = i;
            }
        }
    }

    
    printf("\n\n====== RESULTADOS ======\n");
    printf("Aluno com maior nota: %s (Nota: %.2f)\n", turma[indiceMaior].nome, turma[indiceMaior].nota);
    printf("Aluno com menor nota: %s (Nota: %.2f)\n", turma[indiceMenor].nome, turma[indiceMenor].nota);

    return 0;
}

