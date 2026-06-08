#include <stdio.h>

struct Produto {
    char nome[50];
    float preco;
    int quantidade;
};

int main() {
    struct Produto p;

    
    printf("Digite o nome do produto: ");
    scanf("%s", p.nome);
    printf("Digite o preço: ");
    scanf("%f", &p.preco);
    printf("Digite a quantidade em estoque: ");
    scanf("%d", &p.quantidade);

   
    float valorTotal = p.preco * p.quantidade;
    float valorComDesconto = valorTotal * 0.90; 

    
    printf("\n--- Resumo --- \n");
    printf("Produto: %s\n", p.nome);
    printf("Valor total em estoque: R$ %.2f\n", valorTotal);
    printf("Valor com 10%% de desconto: R$ %.2f\n", valorComDesconto);

    return 0;
}


