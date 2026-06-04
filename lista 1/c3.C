#include <stdio.h>
#include <stdlib.h>

#define max_nome 50

typedef struct{
    char nome[max_nome];
    float notas[3];
    float media;
    char conceito;
} aluno;

aluno calcular_media(aluno a){
    float soma = a.notas[0] + a.notas[1] + a.notas[2];
    a.media = soma / 3.0;
    return a;
}

char definir_conceito(float media) { 
    if(media >= 9.0) return 'a';
    if(media >= 7.0) return 'b';
    if(media >= 5.0) return 'c';
    return 'd';
}

void imprimir_aluno(aluno a){
    printf("%-20s | %.1f | %.1f |%.1f | %.2f | %c\n", a.nome, a.notas[0], a.notas[1], a.notas[2], a.media, a.conceito);
}

int main(){
    int n;
    printf("digite o numero de alunos:");
    if (scanf("%d",&n)!=1 || n<=0){
        printf("quantidade invalida de alunos\n");
        return 1;
    }

   aluno*alunos=(aluno *)malloc(n*sizeof(aluno));
   if(alunos == NULL){
   printf("erro de alocacao de memoria\n");
    return 1;
   }
   
    
    for (int i=0; i<n; i++){
        printf("\n--- dados do aluno %d---", i+1);
        printf("nome: ");
        scanf("%[^\n]s", alunos[i].nome);
    
        for(int j = 0; j<3; j++){
            printf("nota %d: ", j+1);
            scanf("%f", &alunos[i].notas[j]);
        }

        alunos[i] = calcular_media(alunos[i]);
        alunos[i].conceito = definir_conceito(alunos[i].media);
   }

    printf("\n===============boletim=============\n");
    printf("%-20s | N1 | N2 | N3 | media | conceito\n", "nome");
    printf("=====================================\n");

    free(alunos);
    return 0;
}