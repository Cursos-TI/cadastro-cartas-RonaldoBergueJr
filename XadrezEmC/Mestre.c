#include <stdio.h>

// DESAFIO: Movimentando as Peças do Xadrez - Nível Mestre
// Autor: Ronaldo Rafael Bergue Júnior
// Objetivo: Demonstrar o uso de recursividade, loops aninhados e controle de fluxo

// Função recursiva da TORRE
// Move-se em linha reta horizontalmente (Direita)

void moverTorre(int casaAtual, int totalCasas) {
    if (casaAtual > totalCasas) return; // Caso base da recursão
    printf("Direita (%d casa)\n", casaAtual);
    moverTorre(casaAtual + 1, totalCasas); // Chamada recursiva
}


// Função recursiva + loops aninhados do BISPO
// Move-se na diagonal (Cima + Direita)

void moverBispo(int vertical, int horizontal, int total) {
    if (vertical > total) return; // Caso base

    // Loop aninhado: externo vertical, interno horizontal
    for (int i = vertical; i <= total; i++) {
        for (int j = horizontal; j <= total; j++) {
            printf("Cima, Direita (%d,%d)\n", i, j);
            break; // Evita imprimir múltiplas vezes o mesmo nível
        }
        moverBispo(i + 1, horizontal + 1, total); // Recursão
        break;
    }
}

// Função recursiva da RAINHA
// Move-se em linha reta (Esquerda)

void moverRainha(int casaAtual, int totalCasas) {
    if (casaAtual > totalCasas) return; // Caso base
    printf("Esquerda (%d casa)\n", casaAtual);
    moverRainha(casaAtual + 1, totalCasas); // Chamada recursiva
}

// Função do CAVALO
// Movimento em “L” com loops aninhados e controle de fluxo

void moverCavalo() {
    printf("=== Movimento do CAVALO ===\n");
    // Duas casas para cima e uma para a direita
    for (int i = 1, j = 2; i <= 2 && j >= 1; i++, j--) {
        printf("Cima (%d casa)\n", i);

        // Loop interno para movimento horizontal
        for (int k = 1; k <= 1; k++) {
            if (i == 2) {
                printf("Direita (%d casa)\n", k);
                continue; // Apenas imprime uma vez o movimento lateral
            }
        }

        if (i == 2) break; // Controla para não repetir o mesmo “L”
    }
}


// Função principal

int main() {
    printf("=== Movimento da TORRE ===\n");
    moverTorre(1, 5);

    printf("\n=== Movimento do BISPO ===\n");
    moverBispo(1, 1, 5);

    printf("\n=== Movimento da RAINHA ===\n");
    moverRainha(1, 8);

    printf("\n");
    moverCavalo();

    printf("\nSimulação completa! Todas as peças se moveram com sucesso.\n");
    return 0;
}
