#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[50];
    float nota;
} Aluno;

int main() {
    int n, i;
    float soma = 0, media = 0;
    int aprovados = 0;

   
    printf("Digite a quantidade de alunos (N): ");
    scanf("%d", &n);

   
    if (n <= 0) {
        printf("Quantidade invalida!\n");
        return 0;
    }

    
    Aluno *turma = (Aluno *)malloc(n * sizeof(Aluno));

    
    for (i = 0; i < n; i++) {
        printf("\n--- Aluno %d ---\n", i + 1);
        
        printf("Nome: ");
        scanf(" %[^\n]s", turma[i].nome); 
        
        printf("Nota: ");
        scanf("%f", &turma[i].nota);

        
        soma += turma[i].nota;

        
        if (turma[i].nota > 7.0) {
            aprovados++;
        }
    }

    
    if (n > 0) {
        media = soma / n;
    }

   
    printf("\n==============================");
    printf("\n      TABELA DE ALUNOS        ");
    printf("\n==============================");
    printf("\n%-20s | %s", "Nome", "Nota");
    printf("\n------------------------------\n");
    
    for (i = 0; i < n; i++) {
        printf("%-20s | %.2f\n", turma[i].nome, turma[i].nota);
    }

    printf("==============================\n");

    
    printf("Media da turma: %.2f\n", media);
    printf("Quantidade de aprovados (nota > 7): %d\n", aprovados);

    // Libera a memória alocada
    free(turma);

    return 0;
}

