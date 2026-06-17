#include <stdio.h>
#include <stdlib.h>
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
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Quantidade invalida!\n");
        return 1;
    }

    
    Produto *produtos = (Produto *)malloc(n * sizeof(Produto));
    if (produtos == NULL) {
        printf("Erro ao alocar memoria!\n");
        return 1;
    }

    
    for (i = 0; i < n; i++) {
        printf("\n--- Produto %d ---\n", i + 1);
        printf("Nome: ");
        scanf(" %[^\n]s", produtos[i].nome); 
        printf("Preco: R$ ");
        scanf("%f", &produtos[i].preco);
        printf("Quantidade: ");
        scanf("%d", &produtos[i].quantidade);
    }

    
    printf("\n\n================ TABELA DE ESTOQUE ================\n");
    printf("%-20s | %-10s | %-10s | %-15s\n", "Nome", "Preco", "Qtd", "Val. Estoque");
    printf("------------------------------------------------------------\n");

    for (i = 0; i < n; i++) {
        float valor_estoque = produtos[i].preco * produtos[i].quantidade;
        valor_total_geral += valor_estoque;

        printf("%-20s | R$ %7.2f | %-10d | R$ %13.2f\n", 
               produtos[i].nome, produtos[i].preco, produtos[i].quantidade, valor_estoque);

        
        if (valor_estoque > (produtos[indice_maior_estoque].preco * produtos[indice_maior_estoque].quantidade)) {
            indice_maior_estoque = i;
        }

        
        if (produtos[i].preco < produtos[indice_menor_preco].preco) {
            indice_menor_preco = i;
        }
    }

    
    printf("============================================================\n\n");
    printf("Produto com maior valor total em estoque:\n");
    printf("- Nome: %s\n", produtos[indice_maior_estoque].nome);
    printf("- Valor em Estoque: R$ %.2f\n\n", 
           produtos[indice_maior_estoque].preco * produtos[indice_maior_estoque].quantidade);

    printf("Produto com menor preco unitario:\n");
    printf("- Nome: %s\n", produtos[indice_menor_preco].nome);
    printf("- Preco Unitario: R$ %.2f\n\n", produtos[indice_menor_preco].preco);

    printf("Valor total geral de todo o estoque: R$ %.2f\n", valor_total_geral);

    // Liberacao da memoria
    free(produtos);

    return 0;
}
