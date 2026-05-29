#include <stdio.h>

struct Placar {
    char time1[50];
    char time2[50];
    int gols1;
    int gols2;
};

int main() {
    struct Placar jogo;

 
    printf("Digite o nome do primeiro time: ");
    scanf(" %[^\n]", jogo.time1);
    printf("Quantidade de gols do %s: ", jogo.time1);
    scanf("%d", &jogo.gols1);

    printf("Digite o nome do segundo time: ");
    scanf(" %[^\n]", jogo.time2);
    printf("Quantidade de gols do %s: ", jogo.time2);
    scanf("%d", &jogo.gols2);

   
    printf("\n--- PLACAR FINAL ---\n");
    printf("%s %d x %d %s\n", jogo.time1, jogo.gols1, jogo.gols2, jogo.time2);

    
    if (jogo.gols1 > jogo.gols2) {
        printf("Vencedor: %s\n", jogo.time1);
    } else if (jogo.gols2 > jogo.gols1) {
        printf("Vencedor: %s\n", jogo.time2);
    } else {
        printf("Resultado: Empate!\n");
    }

    return 0;
}
