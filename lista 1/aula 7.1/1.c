#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    float preco;
    int quantidade;
    float totalEstoque;
} Produto;

void lerProdutos(Produto est[], int n) {
    for (int i = 0; i < n; i++) {
        printf("\nProduto %d:\n", i + 1);
        printf("Nome: ");
        scanf(" %[^\n]", est[i].nome);
        printf("Preço: ");
        scanf("%f", &est[i].preco);
        printf("Quantidade: ");
        scanf("%d", &est[i].quantidade);
    }
}

void calcularEstoque(Produto est[], int n) {
    for (int i = 0; i < n; i++) {
        est[i].totalEstoque = est[i].preco * est[i].quantidade;
    }
}

void imprimirEstoque(Produto est[], int n) {
    float totalGeral = 0;
    printf("\n%-20s %-10s %-10s %-15s\n", "Produto", "Preço", "Qtd", "Total Estoque");
    printf("-------------------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%-20s %-10.2f %-10d %-15.2f\n",
               est[i].nome, est[i].preco, est[i].quantidade, est[i].totalEstoque);
        totalGeral += est[i].totalEstoque;
    }
    printf("-------------------------------------------------------------\n");
    printf("TOTAL GERAL: %.2f\n", totalGeral);
}

int encontrarMaiorEstoque(Produto est[], int n) {
    int indice = 0;
    for (int i = 1; i < n; i++) {
        if (est[i].totalEstoque > est[indice].totalEstoque) {
            indice = i;
        }
    }
    return indice;
}

int encontrarMenorPreco(Produto est[], int n) {
    int indice = 0;
    for (int i = 1; i < n; i++) {
        if (est[i].preco < est[indice].preco) {
            indice = i;
        }
    }
    return indice;
}

int main() {
    int n;
    printf("Quantos produtos deseja cadastrar? ");
    scanf("%d", &n);

    Produto estoque[n];

    lerProdutos(estoque, n);
    calcularEstoque(estoque, n);
    imprimirEstoque(estoque, n);

    int maior = encontrarMaiorEstoque(estoque, n);
    int menor = encontrarMenorPreco(estoque, n);

    printf("\nProduto com MAIOR valor em estoque: %s (%.2f)\n",
           estoque[maior].nome, estoque[maior].totalEstoque);
    printf("Produto com MENOR preço: %s (%.2f)\n",
           estoque[menor].nome, estoque[menor].preco);

    return 0;
}