#include <stdio.h>


int potencia(int base, int exp) {
    int resultado = 1;
    for (int i = 0; i < exp; i++) {
        resultado *= base;
    }
    return resultado;
}


int fatorial(int n) {
    int fat = 1;
    for (int i = 1; i <= n; i++) {
        fat *= i;
    }
    return fat;
}


int ehPrimo(int n) {
    if (n <= 1) return 0;
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            return 0; 
        }
    }
    return 1; 
}

int main() {
    int numero;

    
    printf("Digite um numero inteiro: ");
    scanf("%d", &numero);

    
    int aoQuadrado = potencia(numero, 2);
    printf("Potencia (ao quadrado): %d\n", aoQuadrado);

    
    if (numero >= 0) {
        printf("Fatorial: %d\n", fatorial(numero));
    } else {
        printf("Fatorial: Nao existe para numeros negativos.\n");
    }

    if (ehPrimo(numero)) {
        printf("Primo: Sim (1)\n");
    } else {
        printf("Primo: Nao (0)\n");
    }

    return 0;
}
