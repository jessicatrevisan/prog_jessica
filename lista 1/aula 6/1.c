#include <stdio.h>
#include <string.h>

struct produto {
    char nome[50];
    float preco;
    int quantidade;

};

int main (){
    struct produto p;

    printf("Digite o nome do produto: ");
    fgets(p.nome, sizeof(p.nome), stdin);
    p.nome[strcspn(p.nome, "\n")] = `\0;

    printf("Digite o preco do produto: ");
    scanf("%f", &p.preco);

    printf("Digite a quantidade em estoque: ");
    scanf("%d", &p.quantidade);

    printf("\nNome : %s\n",p.nome);
    printf("preco : R$ %.2f\n", p.preco);
    printf("Quantidade : %d\n", p.quantidade);

    printf("----------------------------------\n");
    printf(" Valor total em estoque : R$ %.2f\n", p.preco * p.quantidade);

    return 0;
}