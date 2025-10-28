#include <stdio.h>

int main() {
    // DESAFIO: Movimentando as Peças do Xadrez
    // Autor: Ronaldo Rafael Bergue Júnior
    // Peças simuladas: Torre, Bispo, Rainha e Cavalo
    // Objetivo: Demonstrar o uso de estruturas de repetição simples e aninhadas
    
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

    // NÍVEL AVENTUREIRO: MOVIMENTO DO CAVALO
    // O Cavalo move-se em "L": duas casas para baixo e uma para a esquerda.
    // Aqui usamos loops aninhados: um "for" e um "while".
    printf("=== Movimento do CAVALO ===\n");

    int movimentos_baixo = 2;   // Duas casas para baixo
    int movimentos_esquerda = 1; // Uma casa para a esquerda

    // Loop externo: movimento para baixo (usando for)
    for (int i = 1; i <= movimentos_baixo; i++) {
        printf("Baixo (%d casa)\n", i);
    }

    // Linha em branco para separar visualmente
    printf("\n");

    // Loop interno: movimento para a esquerda (usando while)
    int j = 1;
    while (j <= movimentos_esquerda) {
        printf("Esquerda (%d casa)\n", j);
        j++;
    }

    // Finalização
    printf("\nSimulação completa! Todas as peças se moveram com sucesso.\n");

    return 0;
}
