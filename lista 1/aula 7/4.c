#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

void imprimirMenu() {
    printf("\n=== CALCULADORA ===\n");
    printf("1. Calcular média de 3 notas\n");
    printf("2. Verificar se número é primo\n");
    printf("3. Calcular potência\n");
    printf("0. Sair\n");
    printf("Opção: ");
}

void calcularMedia() {
    double n1, n2, n3;
    printf("Digite a primeira nota: ");
    if (scanf("%lf", &n1) != 1) { printf("Entrada inválida!\n"); return; }
    printf("Digite a segunda nota: ");
    if (scanf("%lf", &n2) != 1) { printf("Entrada inválida!\n"); return; }
    printf("Digite a terceira nota: ");
    if (scanf("%lf", &n3) != 1) { printf("Entrada inválida!\n"); return; }

    double media = (n1 + n2 + n3) / 3.0;
    printf("Média = %.2f\n", media);
}


bool ehPrimo(int num) {
    if (num <= 1) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;
    for (int i = 3; i <= sqrt(num); i += 2) {
        if (num % i == 0) return false;
    }
    return true;
}


void verificarPrimo() {
    int num;
    printf("Digite um número inteiro: ");
    if (scanf("%d", &num) != 1) { printf("Entrada inválida!\n"); return; }

    if (ehPrimo(num))
        printf("%d é primo.\n", num);
    else
        printf("%d não é primo.\n", num);
}

void calcularPotencia() {
    double base, expoente;
    printf("Digite a base: ");
    if (scanf("%lf", &base) != 1) { printf("Entrada inválida!\n"); return; }
    printf("Digite o expoente: ");
    if (scanf("%lf", &expoente) != 1) { printf("Entrada inválida!\n"); return; }

    double resultado = pow(base, expoente);
    printf("%.2f ^ %.2f = %.2f\n", base, expoente, resultado);
}

int main() {
    int opcao = -1;

    while (1) {
        imprimirMenu();

        if (scanf("%d", &opcao) != 1) {
            printf("Entrada inválida! Digite um número.\n");
        
            int c; while ((c = getchar()) != '\n' && c != EOF);
            continue;
        }

        switch (opcao) {
            case 1:
                calcularMedia();
                break;
            case 2:
                verificarPrimo();
                break;
            case 3:
                calcularPotencia();
                break;
            case 0:
                printf("Saindo do programa. Até logo!\n");
                return 0;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    }

    return 0;
}