#include <stdio.h>
#include <string.h>

// Definindo a estrutura Jogador
typedef struct {
    char nome[50];
    int pontos;
} Jogador;

int main() {
    int n;

    printf("Digite a quantidade de jogadores: ");
    scanf("%d", &n);

    // Validação para garantir que N seja válido
    if (n <= 0) {
        printf("Quantidade invalida!\n");
        return 0;
    }

    Jogador jogadores[n];

    // Lendo os dados de cada jogador
    for (int i = 0; i < n; i++) {
        printf("\n--- Jogador %d ---\n", i + 1);
        printf("Nome: ");
        scanf(" %[^\n]s", jogadores[i].nome); // Lê strings com espaços
        printf("Pontos: ");
        scanf("%d", &jogadores[i].pontos);
    }

    // Variáveis para armazenar o indice do maior e do menor
    int indiceMaior = 0;
    int indiceMenor = 0;

    // Lógica para encontrar o jogador com mais e menos pontos
    for (int i = 1; i < n; i++) {
        if (jogadores[i].pontos > jogadores[indiceMaior].pontos) {
            indiceMaior = i;
        }
        if (jogadores[i].pontos < jogadores[indiceMenor].pontos) {
            indiceMenor = i;
        }
    }

    // Exibindo os resultados
    printf("\n=============================\n");
    printf("Jogador com mais pontos: %s (%d pontos)\n", jogadores[indiceMaior].nome, jogadores[indiceMaior].pontos);
    printf("Jogador com menos pontos: %s (%d pontos)\n", jogadores[indiceMenor].nome, jogadores[indiceMenor].pontos);

    return 0;
}


