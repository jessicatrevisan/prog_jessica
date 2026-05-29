#include <stdio.h>
#include <string.h>

struct Pessoa {
    char nome[50];
    int idade;
    float altura;
};

int main() {
    struct Pessoa p;

   
    printf("Digite o nome: ");
    scanf(" %[^\n]s", p.nome);

    printf("Digite a idade: ");
    scanf("%d", &p.idade);

    printf("Digite a altura (ex: 1.75): ");
    scanf("%f", &p.altura);

  
    printf("\n=== FICHA DA PESSOA ===\n");
    printf("Nome   : %s\n", p.nome);
    printf("Idade  : %d anos\n", p.idade);
    printf("Altura : %.2f m\n", p.altura);

    return 0;
}

