#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    int vitorias;
    int empates;
    int derrotas;
    int pontos;
} Time;

void lerTimes(Time times[], int n) {
    for (int i = 0; i < n; i++) {
        printf("\n=== Time %d ===\n", i + 1);
        printf("Nome: ");
        scanf(" %[^\n]", times[i].nome);
        printf("Vitorias: ");
        scanf("%d", &times[i].vitorias);
        printf("Empates: ");
        scanf("%d", &times[i].empates);
        printf("Derrotas: ");
        scanf("%d", &times[i].derrotas);
        times[i].pontos = 0;
    }
}

void calcularPontos(Time times[], int n) {
    for (int i = 0; i < n; i++) {
        times[i].pontos = (times[i].vitorias * 3) + (times[i].empates * 1);
    }
}

void imprimirClassificacao(Time times[], int n) {
    printf("\n=== Classificacao ===\n");
    for (int i = 0; i < n; i++) {
        printf("%d. %-15s | %2d pts | %dV %dE %dD\n",
               i + 1,
               times[i].nome,
               times[i].pontos,
               times[i].vitorias,
               times[i].empates,
               times[i].derrotas);
    }
}

int encontrarLider(Time times[], int n) {
    int lider = 0;
    for (int i = 1; i < n; i++) {
        if (times[i].pontos > times[lider].pontos) {
            lider = i;
        }
    }
    return lider;
}

int main() {
    int n;
    printf("Quantos times? ");
    scanf("%d", &n);

    Time times[n];

    lerTimes(times, n);
    calcularPontos(times, n);
    imprimirClassificacao(times, n);

    int idxLider = encontrarLider(times, n);
    printf("\nLider do torneio: %s com %d pontos!\n",
           times[idxLider].nome, times[idxLider].pontos);

    return 0;
}