#include <stdio.h>
#include <string.h>

int main() {
    int n, i;
    int acima_media = 0;
    float soma = 0, media;
    
    printf("Digite a quantidade de alunos: ");
    scanf("%d", &n);

    char nomes[n][50];
    float notas[n];

    for (i = 0; i < n; i++) {
        printf("\n--- Aluno %d ---\n", i + 1);
        printf("Nome: ");
        scanf(" %[^\n]s", nomes[i]);
        printf("Nota: ");
        scanf("%f", &notas[i]);
        
        soma += notas[i];
    }

    
    media = soma / n;


    float maior = notas[0];
    float menor = notas[0];
    int idx_maior = 0;
    int idx_menor = 0;

    for (i = 0; i < n; i++) {
        if (notas[i] > maior) {
            maior = notas[i];
            idx_maior = i;
        }
        if (notas[i] < menor) {
            menor = notas[i];
            idx_menor = i;
        }
        if (notas[i] > media) {
            acima_media++;
        }
    }


    printf("\n\n====== TABELA DE NOTAS ======\n");
    for (i = 0; i < n; i++) {
        printf("Nome: %-15s | Nota: %.2f\n", nomes[i], notas[i]);
    }
    
    printf("\n=============================\n");
    printf("Media da turma: %.2f\n", media);
    printf("Maior nota: %.2f (Aluno: %s)\n", maior, nomes[idx_maior]);
    printf("Menor nota: %.2f (Aluno: %s)\n", menor, nomes[idx_menor]);
    printf("Alunos acima da media: %d\n", acima_media);

    return 0;
}
