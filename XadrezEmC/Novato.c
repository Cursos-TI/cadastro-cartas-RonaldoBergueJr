#include <stdio.h>

int main() {
    // DESAFIO: Movimentando as Peças do Xadrez
    // Autor: Ronaldo Rafael Bergue Júnior
    // Peças simuladas: Torre, Bispo e Rainha
    // Objetivo: Demonstrar o uso das estruturas for, while e do-while
    
    // TORRE (usa FOR)
    // A Torre move-se em linha reta — aqui, 5 casas para a direita.
    printf("=== Movimento da TORRE ===\n");
    for (int i = 1; i <= 5; i++) {
        printf("Direita (%d casa)\n", i);
    }
    printf("\n");

    // BISPO (usa WHILE)
    // O Bispo move-se na diagonal — aqui, 5 casas para cima e à direita.
    printf("=== Movimento do BISPO ===\n");
    int casas_bispo = 1;
    while (casas_bispo <= 5) {
        printf("Cima, Direita (%d casa)\n", casas_bispo);
        casas_bispo++;
    }
    printf("\n");


    // RAINHA (usa DO-WHILE)
    // A Rainha move-se em todas as direções — aqui, 8 casas para a esquerda.
    printf("=== Movimento da RAINHA ===\n");
    int casas_rainha = 1;
    do {
        printf("Esquerda (%d casa)\n", casas_rainha);
        casas_rainha++;
    } while (casas_rainha <= 8);
    printf("\n");

    // Finalização
    printf("Simulação concluída com sucesso!\n");

    return 0;
}
