#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1. Definição da Struct
typedef struct {
    char nome[50];
    int pontos;
    int vitorias;
} Jogador;

int main() {
    int n, i;
    int total_vitorias = 0;
    float media_vitorias = 0.0;
    int acima_media = 0;

    int indice_mais_pontos = 0;
    int indice_mais_vitorias = 0;

    
    printf("Digite o numero de jogadores: ");
    scanf("%d", &n);

    
    Jogador *jogadores = (Jogador *)malloc(n * sizeof(Jogador));

    
    if (jogadores == NULL) {
        printf("Erro ao alocar memoria!\n");
        return 1;
    }

    
    for (i = 0; i < n; i++) {
        printf("\n--- Jogador %d ---\n", i + 1);
        
        printf("Nome: ");
        scanf(" %[^\n]s", jogadores[i].nome); 
        
        printf("Pontos: ");
        scanf("%d", &jogadores[i].pontos);
        
        printf("Vitorias: ");
        scanf("%d", &jogadores[i].vitorias);

        
        total_vitorias += jogadores[i].vitorias;
    }

    
    if (n > 0) {
        media_vitorias = (float)total_vitorias / n;
    }

    
    printf("\n\n=========================================");
    printf("\n           TABELA DE JOGADORES           ");
    printf("\n=========================================");
    printf("\n%-20s | %-8s | %-8s\n", "Nome", "Pontos", "Vitorias");
    printf("-----------------------------------------\n");

    for (i = 0; i < n; i++) {
        printf("%-20s | %-8d | %-8d\n", jogadores[i].nome, jogadores[i].pontos, jogadores[i].vitorias);

        
        if (jogadores[i].pontos > jogadores[indice_mais_pontos].pontos) {
            indice_mais_pontos = i;
        }

        
        if (jogadores[i].vitorias > jogadores[indice_mais_vitorias].vitorias) {
            indice_mais_vitorias = i;
        }

        
        if (jogadores[i].vitorias > media_vitorias) {
            acima_media++;
        }
    }

    printf("=========================================\n\n");

    
    printf("Jogador com mais pontos: %s (%d pontos)\n", 
           jogadores[indice_mais_pontos].nome, jogadores[indice_mais_pontos].pontos);

    printf("Jogador com mais vitorias: %s (%d vitorias)\n", 
           jogadores[indice_mais_vitorias].nome, jogadores[indice_mais_vitorias].vitorias);

    printf("Media de vitorias do grupo: %.2f\n", media_vitorias);
    printf("Jogadores com mais vitorias do que a media: %d\n", acima_media);

   
    free(jogadores);

    return 0;
}
