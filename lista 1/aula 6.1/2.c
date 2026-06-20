#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    float preco;
    int quantidade;
} Produto;

int main() {
    int n, i;
    float valor_total_geral = 0;
    int indice_maior_estoque = 0;
    int indice_menor_preco = 0;

    printf("Digite a quantidade de produtos (N): ");
    scanf("%d", &n);


    if (n <= 0) {
        printf("Quantidade de produtos invalida!\n");
        return 0;
    }

    Produto produtos[n];


    for (i = 0; i < n; i++) {
        printf("\n--- Produto %d ---\n", i + 1);
        printf("Nome: ");
        scanf(" %[^\n]s", produtos[i].nome);
        printf("Preco: ");
        scanf("%f", &produtos[i].preco);
        printf("Quantidade: ");
        scanf("%d", &produtos[i].quantidade);
    }

    
    printf("\n\n=== TABELA DE ESTOQUE ===\n");
    printf("%-20s | %-10s | %-12s | %-15s\n", "Nome", "Preco", "Quantidade", "Valor em Estoque");
    printf("-----------------------------------------------------------------------------\n");

    for (i = 0; i < n; i++) {
        float valor_estoque = produtos[i].preco * produtos[i].quantidade;
        printf("%-20s | R$ %7.2f | %-12d | R$ %12.2f\n", 
               produtos[i].nome, produtos[i].preco, produtos[i].quantidade, valor_estoque);
        
    
        valor_total_geral += valor_estoque;


        if (i == 0 || (produtos[i].preco * produtos[i].quantidade) > (produtos[indice_maior_estoque].preco * produtos[indice_maior_estoque].quantidade)) {
            indice_maior_estoque = i;
        }

    
        if (i == 0 || produtos[i].preco < produtos[indice_menor_preco].preco) {
            indice_menor_preco = i;
        }
    }

    
    printf("\n=== RESUMO ===\n");
    printf("Produto com maior valor total em estoque: %s (R$ %.2f)\n", 
           produtos[indice_maior_estoque].nome, 
           (produtos[indice_maior_estoque].preco * produtos[indice_maior_estoque].quantidade));

    printf("Produto com menor preco unitario: %s (R$ %.2f)\n", 
           produtos[indice_menor_preco].nome, 
           produtos[indice_menor_preco].preco);

    printf("Valor total geral do estoque: R$ %.2f\n", valor_total_geral);

    return 0;
}
