#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    char nome[50];
    int pontos;
    int vitorias;
} Jogador;

int main() {
    int n;
    
    
    printf("Digite a quantidade de jogadores (N): ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Quantidade invalida!\n");
        return 1;
    }

    Jogador *jogadores = (Jogador *)malloc(n * sizeof(Jogador));
    if (jogadores == NULL) {
        printf("Erro de alocacao de memoria!\n");
        return 1;
    }

    int soma_vitorias = 0;
    int idx_max_pontos = 0;
    int idx_max_vitorias = 0;

    for (int i = 0; i < n; i++) {
        printf("\n--- Jogador %d ---\n", i + 1);
        printf("Nome: ");
        scanf(" %[^\n]s", jogadores[i].nome);
        printf("Pontos: ");
        scanf("%d", &jogadores[i].pontos);
        printf("Vitorias: ");
        scanf("%d", &jogadores[i].vitorias);

        soma_vitorias += jogadores[i].vitorias;

        
        if (i == 0 || jogadores[i].pontos > jogadores[idx_max_pontos].pontos) {
            idx_max_pontos = i;
        }

        
        if (i == 0 || jogadores[i].vitorias > jogadores[idx_max_vitorias].vitorias) {
            idx_max_vitorias = i;
        }
    }

    
    float media_vitorias = (float)soma_vitorias / n;

    
    printf("\n\n================ TABELA DE JOGADORES ================\n");
    printf("%-20s | %-10s | %-10s\n", "Nome", "Pontos", "Vitorias");
    printf("-----------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%-20s | %-10d | %-10d\n", jogadores[i].nome, jogadores[i].pontos, jogadores[i].vitorias);
    }
    printf("=====================================================\n");

    
    printf("\nJogador com mais pontos: %s (%d pontos)\n", 
           jogadores[idx_max_pontos].nome, jogadores[idx_max_pontos].pontos);

    
    printf("Jogador com mais vitorias: %s (%d vitorias)\n", 
           jogadores[idx_max_vitorias].nome, jogadores[idx_max_vitorias].vitorias);

    
    int cont_acima_media = 0;
    for (int i = 0; i < n; i++) {
        if (jogadores[i].vitorias > media_vitorias) {
            cont_acima_media++;
        }
    }

    printf("Media de vitorias do grupo: %.2f\n", media_vitorias);
    printf("Quantidade de jogadores acima da media de vitorias: %d\n", cont_acima_media);

    
    free(jogadores);
    
    return 0;
}
