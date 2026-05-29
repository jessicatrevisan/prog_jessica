#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Produto {
    char nome[50];
    float preco;
    int quantidade;
    float valor_estoque;
};

int main() {
    int n;

   
    printf("Digite a quantidade de produtos a cadastrar: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Quantidade invalida!\n");
        return 0;
    }

    struct Produto produtos[n];
    float valor_total_geral = 0;
    int indice_maior_valor = 0;

    
    for (int i = 0; i < n; i++) {
        printf("\n--- Produto %d ---\n", i + 1);
        
        printf("Nome: ");
        scanf(" %[^\n]s", produtos[i].nome); // Lê strings com espaços
        
        printf("Preco R$: ");
        scanf("%f", &produtos[i].preco);
        
        printf("Quantidade: ");
        scanf("%d", &produtos[i].quantidade);

        
        produtos[i].valor_estoque = produtos[i].preco * produtos[i].quantidade;

        
        valor_total_geral += produtos[i].valor_estoque;

       
        if (i == 0) {
            indice_maior_valor = 0;
        } else if (produtos[i].valor_estoque > produtos[indice_maior_valor].valor_estoque) {
            indice_maior_valor = i;
        }
    }

    
    printf("\n\n================ TABELA DE ESTOQUE ================\n");
    printf("%-20s | %-10s | %-10s | %-15s\n", "Produto", "Preco", "Qtd", "Valor Estoque");
    printf("------------------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%-20s | R$ %7.2f | %-10d | R$ %13.2f\n", 
            produtos[i].nome, 
            produtos[i].preco, 
            produtos[i].quantidade, 
            produtos[i].valor_estoque
        );
    }
    printf("============================================================\n");

    
    printf("\nValor total geral em estoque: R$ %.2f\n", valor_total_geral);
    printf("Produto com maior valor em estoque: %s (R$ %.2f)\n", 
        produtos[indice_maior_valor].nome, 
        produtos[indice_maior_valor].valor_estoque
    );

    return 0;
}

