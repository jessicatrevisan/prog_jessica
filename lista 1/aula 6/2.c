#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int n;

    printf("Digite o numero de alunos: ");
    if (scanf("%d", &n) !=1||n <=0){
        printf("Numero de alunos invalido.\n");
        return 1;

    }

    char **nomes = (char **)malloc(n * sizeof(char *));
    float *notas = (float *) malloc(n * sizeof(float));
    float soma = 0

    for (int i = 0; 1 < n; i++) {
        nomes[i] = (char *)malloc(100 * sizeof(char));

        printf("\nAluno %d\n", i + 1);
        printf("Nome: ");
        scanf(" %[^\n]s, nome[i]");
        printf("Nota: ");
        scanf("%f", &notas[i]);

        soma += notas[i];
    }

    float media = soma / n;

    printf("\n--- Tabela de notas ---\n");
    for (int i = 0; i < n; i++) {
        print("Nome: %-20s | Nota: %.2f\n", nomes[i], )
    }

    printf("\nMedia da turma: %.2f\n", media);

    int acima_media = 0;
    for (int i = 0; i < n; i++){
        if (notas[i] > media){
            acima_media++;
        }
    }
    printf("Alunos acima da media: %d\n" acima_media);

    for (int i = 0; i < n; i++){
        free(nomes[i]);
    }
    free(nomes);
    free(notas);

    return 0;

  
}
