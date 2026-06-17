#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n, i;
    int acima_media = 0;
    float soma = 0, media = 0;
    float maior_nota = -1, menor_nota = 11;
    char nome_maior[50], nome_menor[50];

    printf("Digite a quantidade de alunos: ");
    scanf("%d", &n);

    
    char *nomes[n];
    float notas[n];

    
    for (i = 0; i < n; i++) {
        nomes[i] = malloc(50 * sizeof(char));
        
        printf("\nAluno %d\n", i + 1);
        printf("Nome: ");
        scanf(" %[^\n]s", nomes[i]); 
        
        printf("Nota: ");
        scanf("%f", &notas[i]);

        soma += notas[i];

        
        if (notas[i] > maior_nota) {
            maior_nota = notas[i];
            strcpy(nome_maior, nomes[i]);
        }

      
        if (notas[i] < menor_nota) {
            menor_nota = notas[i];
            strcpy(nome_menor, nomes[i]);
        }
    }

    
    if (n > 0) {
        media = soma / n;
    }

        printf("\n\n--- BOLETIM DA TURMA ---\n");
    for (i = 0; i < n; i++) {
        printf("Nome: %-20s | Nota: %.2f\n", nomes[i], notas[i]);
        
        if (notas[i] > media) {
            acima_media++;
        }
    }

   
    printf("\n------------------------\n");
    printf("Media da turma: %.2f\n", media);
    printf("Maior nota: %.2f (Aluno: %s)\n", maior_nota, nome_maior);
    printf("Menor nota: %.2f (Aluno: %s)\n", menor_nota, nome_menor);
    printf("Alunos acima da media: %d\n", acima_media);

    
    for (i = 0; i < n; i++) {
        free(nomes[i]);
    }

    return 0;
}

