#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    int pontos;
} Jogador;

int main() {
    int n;

    printf("Digite a quantidade de jogadores: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Quantidade invalida!\n");
        return 0;
    }

    Jogador jogadores[n];

    for (int i = 0; i < n; i++) {
        printf("\n--- Jogador %d ---\n", i + 1);
        printf("Nome: ");
        scanf(" %[^\n]s", jogadores[i].nome); 
        printf("Pontos: ");
        scanf("%d", &jogadores[i].pontos);
    }

    int indiceMaior = 0;
    int indiceMenor = 0;

    for (int i = 1; i < n; i++) {
        if (jogadores[i].pontos > jogadores[indiceMaior].pontos) {
            indiceMaior = i;
        }
        if (jogadores[i].pontos < jogadores[indiceMenor].pontos) {
            indiceMenor = i;
        }
    }

    printf("\n=============================\n");
    printf("Jogador com mais pontos: %s (%d pontos)\n", jogadores[indiceMaior].nome, jogadores[indiceMaior].pontos);
    printf("Jogador com menos pontos: %s (%d pontos)\n", jogadores[indiceMenor].nome, jogadores[indiceMenor].pontos);

    return 0;
}


