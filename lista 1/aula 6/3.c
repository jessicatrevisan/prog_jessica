#include <stdio.h>

#define max_alunos 100

int main(){
    int n, i;
    char nomes[max_alunos][50];
    float notas[max_alunos];
    float soma = 0.0, media;
    int acima media = 0;
    int idx_maior = 0, idx_menor = 0;

    printf("Digite o numero de alunos: ");
    scanf("%d", &n);

    if (n > max_alunos || n <= 0){
        printf("numero de alunos invalido\n");
        return 1;
    }

    for (i = 0; i < n; i++){
        printf("\ndigite o nome do aluno %d: ", i + 1);
        scanf("%s", nomes[i]);

        printf("digite a nota de %s: ", nomes[i]);
        scanf("%f", &notas[i]);

        soma += notas[i];

    }

    media = soma / n;

    printf("\n--- boletim da turma ---\n");
    for(i = 0; i < n; i++) {
        printf("aluno: %-15s | nota: %.2f\n", nomes[i], notas[i]);

        if(notas[i] > media) {
            acima_media++;
          }
        }

    printf("\nmedia da turma: %.2f\n", media);
    printf("alunos acima da media: %d\n", acima_media);
    
    for(i = 1; i < n; i++){
        if(notas[i] > notas[idx_maior]){
            idx_maior = i;
        }
   
        if(notas[i] < notas[idx_menor]){
            idx_menor = i;
        }
   
    }

    printf("\n--- destaques ---\n");
    printf("maior nota: %s (nota: %.2f)\n", nomes[idx_maior], notas[idx_maior]);
    printf("menor nota: %s (nota: %.2f)\n", nomes[idx_menor], notas[idx_menor]);

    return 0;


}