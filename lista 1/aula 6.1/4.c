#include <stdio.h>
#include <string.h> 

int main() {
    
    struct Aluno {
        char nome[50];
        float nota;
    };
    
    int n = 3; 
    struct Aluno turma[3] = {
        {"Ana", 8.5},
        {"Bruno", 9.0},
        {"Carla", 7.5}
    };

    
    printf("--- BOLETIM DA TURMA ---\n");
    for(int i = 0; i < n; i++) {
        printf("Nome: %s | Nota: %.1f\n", turma[i].nome, turma[i].nota);
    }
    printf("------------------------\n");

    
    char busca[50];
    
    printf("\nBuscar aluno: ");
    scanf(" %49[^\n]s", busca); 
    
    int encontrado = 0;
    
    for(int i = 0; i < n; i++) {
        if(strcmp(turma[i].nome, busca) == 0) {
            printf("Encontrado: %s, nota %.1f\n", turma[i].nome, turma[i].nota);
            encontrado = 1;
            break; 
        }
    }
    
    if(!encontrado) {
        printf("Aluno nao encontrado.\n");
    }

    return 0;
}
