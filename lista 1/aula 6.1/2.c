#include <stdio.h>


struct Aluno {
    char nome[50];
    float nota;
};

int main() {
    int n, acima_media = 0;
    float soma = 0.0, media;

    
    printf("Digite o numero de alunos: ");
    scanf("%d", &n);

   
    if (n <= 0) {
        printf("O numero de alunos deve ser maior que zero.\n");
        return 1;
    }

    struct Aluno alunos[n]; 

    
    for (int i = 0; i < n; i++) {
        printf("\nDados do %dº aluno:\n", i + 1);
        printf("Nome: ");
        scanf("%s", alunos[i].nome);
        printf("Nota: ");
        scanf("%f", &alunos[i].nota);
        
        soma += alunos[i].nota; // Acumula as notas
    }

   
    media = soma / n;

    
    printf("\n\n=== TABELA DE ALUNOS ===\n");
    printf("%-20s | %s\n", "Nome", "Nota");
    printf("--------------------------------\n");
    
    for (int i = 0; i < n; i++) {
        printf("%-20s | %.2f\n", alunos[i].nome, alunos[i].nota);
        
        if (alunos[i].nota > media) {
            acima_media++;
        }
    }

    
    printf("--------------------------------\n");
    printf("Media da turma: %.2f\n", media);
    printf("Alunos acima da media: %d\n", acima_media);

    return 0;
}

