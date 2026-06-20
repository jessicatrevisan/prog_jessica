#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    char nome[50];
    float preco;
    int quantidade;
} Produto;

int main() {
    int n;

    printf("Digite a quantidade de produtos: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Quantidade inválida.\n");
        return 1;
    }

    
    Produto *produtos = (Produto *)malloc(n * sizeof(Produto));
    if (produtos == NULL) {
        printf("Erro de memória.\n");
        return 1;
    }

    
    for (int i = 0; i < n; i++) {
        printf("\n--- Produto %d ---\n", i + 1);
        printf("Nome: ");
        scanf(" %[^\n]", produtos[i].nome); 
        printf("Preço: R$ ");
        scanf("%f", &produtos[i].preco);
        printf("Quantidade: ");
        scanf("%d", &produtos[i].quantidade);
    }

    
    float total_geral = 0.0;
    float maior_valor_estoque = -1.0;
    int indice_maior_estoque = 0;

    
    printf("\n%-20s %-10s %-5s %-10s\n", "Produto", "Preco", "Qtd", "Total");
    printf("-----------------------------------------\n");

    
    for (int i = 0; i < n; i++) {
        float total_produto = produtos[i].preco * produtos[i].quantidade;
        total_geral += total_produto;

    
        printf("%-20s R$%7.2f %5d R$%7.2f\n", 
               produtos[i].nome, 
               produtos[i].preco, 
               produtos[i].quantidade, 
               total_produto);

        
        if (total_produto > maior_valor_estoque) {
            maior_valor_estoque = total_produto;
            indice_maior_estoque = i;
        }
    }

    
    printf("-----------------------------------------\n");
    printf("Total geral: R$%.2f\n", total_geral);
    printf("Maior estoque: %s (R$%.2f)\n", 
           produtos[indice_maior_estoque].nome, 
           maior_valor_estoque);

    
    free(produtos);

    return 0;
}
