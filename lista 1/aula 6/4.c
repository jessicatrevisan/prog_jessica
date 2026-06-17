#include <stdio.h>
#include <string.h>

int main() {
    int n = 3;
    
  
    struct Aluno {
        char nome[50];
        float nota;
    };
    
    struct Aluno turma[3] = {
        {"Ana", 8.5},
        {"Bruno", 7.0},
        {"Carla", 9.5}
    };

   
    printf("--- Boletim da Turma ---\n");
    for(int i = 0; i < n; i++) {
        printf("Nome: %s | Nota: %.2f\n", turma[i].nome, turma[i].nota);
    }

   
    char busca[50];
    printf("\nBuscar aluno: ");
    scanf("%49s", busca);

    int encontrado = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(turma[i].nome, busca) == 0) {
            printf("Encontrado: %s, nota %.2f\n", turma[i].nome, turma[i].nota);
            encontrado = 1;
        }
    }

    if (!encontrado) {
        printf("Aluno nao encontrado.\n");
    }

    return 0;
}

