#include <stdio.h>
#include <string.h>


typedef struct {
    char nome[50];
    float nota;
    } Aluno;


    void ordenarPorNota(Aluno turma[], int n) {
    int i, j, max_idx;
    Aluno temp;

    for (i = 0; i < n - 1; i++) {
    max_idx = i;
    for (j = i + 1; j < n; j++) {
    if (turma[j].nota > turma[max_idx].nota) {
    max_idx = j;
       }
    }                                                                                     
    if (max_idx != i) {
    temp = turma[i];
    turma[i] = turma[max_idx];
    turma[max_idx] = temp;
     }
      }
       }

    void exibirBoletim(Aluno turma[], int n) {
    printf("\n--- BOLETIM - RANKING ---\n");
    for (int i = 0; i < n; i++) {
    printf("%dº Lugar: %s - Nota: %.2f\n", i + 1, turma[i].nome, turma[i].nota);
    }
    }

    int main() {
                                                                                                                                                                            
    Aluno turma[5] = {
    {"Ana", 7.5},
    {"Bruno", 9.0},
    {"Carlos", 8.2},
    {"Diana", 9.5},
    {"Eduardo", 6.0}
      };
 
    int n =5;
    printf("Notas originais:\n");
    for(int i = 0; i < n; i++) {
    printf("%s: %.2f\n", turma[i].nome, turma[i].nota);
      }

                                                                                                                                                                                                                                                        
    ordenarPorNota(turma, n);

                                                                                                                                                                                                                                                                
    exibirBoletim(turma, n);

     return 0;
    }                                                                                                                                                                                                                                                                   

