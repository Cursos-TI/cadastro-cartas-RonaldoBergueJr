#include <stdio.h>

// ======================================================
// DESAFIO: Posicionando Navios no Tabuleiro - Nível Novato
// Autor: Ronaldo Rafael Bergue Júnior
// Objetivo: Representar um tabuleiro de Batalha Naval 10x10,
//           posicionando dois navios (um horizontal e um vertical)
//           utilizando vetores e matrizes em C.
// ======================================================


#define TAM 10         // Tamanho fixo do tabuleiro (10x10)
#define NAVIO 3        // Valor que representa as partes do navio
#define AGUA 0         // Valor que representa água
#define TAM_NAVIO 3    // Tamanho fixo de cada navio

int main() {
    int tabuleiro[TAM][TAM];  // Matriz que representa o tabuleiro
    int i, j;

    // ------------------------------------------------------
    // 1. Inicialização do tabuleiro
    // ------------------------------------------------------
    // Todas as posições do tabuleiro começam com 0 (água)
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // ------------------------------------------------------
    // 2. Definição dos navios
    // ------------------------------------------------------
    // Cada navio possui 3 partes representadas pelo número 3
    int navio_horizontal[TAM_NAVIO] = {NAVIO, NAVIO, NAVIO};
    int navio_vertical[TAM_NAVIO] = {NAVIO, NAVIO, NAVIO};

    // Coordenadas iniciais dos navios (podem ser alteradas)
    int linha_inicial_horizontal = 2;
    int coluna_inicial_horizontal = 1;

    int linha_inicial_vertical = 5;
    int coluna_inicial_vertical = 7;

    // ------------------------------------------------------
    // 3. Posicionamento dos navios
    // ------------------------------------------------------
    // Posiciona o navio horizontalmente (da esquerda para a direita)
    for (i = 0; i < TAM_NAVIO; i++) {
        if (coluna_inicial_horizontal + i < TAM) {
            tabuleiro[linha_inicial_horizontal][coluna_inicial_horizontal + i] = navio_horizontal[i];
        }
    }

    // Posiciona o navio verticalmente (de cima para baixo)
    for (i = 0; i < TAM_NAVIO; i++) {
        if (linha_inicial_vertical + i < TAM) {
            tabuleiro[linha_inicial_vertical + i][coluna_inicial_vertical] = navio_vertical[i];
        }
    }

    // ------------------------------------------------------
    // 4. Exibição do tabuleiro
    // ------------------------------------------------------
    printf("=== TABULEIRO DE BATALHA NAVAL ===\n\n");

    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    printf("\nLegenda:\n0 = Água\n3 = Navio\n");

    return 0;
}
