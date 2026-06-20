#include <stdio.h>


float somar(float a, float b) {
    return a + b;
}

float subtrair(float a, float b) {
    return a - b;
}

float multiplicar(float a, float b) {
    return a * b;
}

float dividir(float a, float b) {
    if (b == 0) {
        printf("Erro: Divisão por zero!\n");
        return 0.0f;
    }
    return a / b;
}

int main() {
    float num1, num2;

    
    printf("Digite o primeiro número: ");
    scanf("%f", &num1);
    
    printf("Digite o segundo número: ");
    scanf("%f", &num2);

    
    printf("\n--- Resultados ---\n");
    printf("Soma: %.2f\n", somar(num1, num2));
    printf("Subtração: %.2f\n", subtrair(num1, num2));
    printf("Multiplicação: %.2f\n", multiplicar(num1, num2));
    printf("Divisão: %.2f\n", dividir(num1, num2));

    return 0;
}
