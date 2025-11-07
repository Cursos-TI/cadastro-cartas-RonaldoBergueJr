/*
----------------------------------------------------------
    BATALHA NAVAL – NÍVEL INTERMEDIÁRIO
    Autor: Ronaldo Rafael Bergue Júnior
    Descrição:
        Programa em C que cria um tabuleiro 10x10 do jogo
        Batalha Naval, posiciona quatro navios de tamanho 3:
        - Dois horizontais ou verticais
        - Dois na diagonal
        O programa valida os limites e impede sobreposição
        de navios, exibindo o tabuleiro final no console.
----------------------------------------------------------
*/

#include <stdio.h>

#define TAM 10       // Tamanho do tabuleiro (10x10)
#define NAVIO 3      // Valor que representa um navio
#define TAM_NAVIO 3  // Tamanho fixo de cada navio

// Função para exibir o tabuleiro formatado
void exibirTabuleiro(int tabuleiro[TAM][TAM]) {
    printf("\n=== TABULEIRO FINAL ===\n\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para verificar se é possível posicionar um navio
int podePosicionar(int tabuleiro[TAM][TAM], int linha, int coluna, int direcao, int diagonal) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        int lin = linha;
        int col = coluna;

        // Direções:
        if (diagonal == 0) { 
            // 0 = Vertical, 1 = Horizontal
            if (direcao == 0) lin += i;   // Vertical (descendo)
            else col += i;                // Horizontal (direita)
        } else {
            // 0 = Diagonal principal (\), 1 = Diagonal secundária (/)
            if (direcao == 0) { lin += i; col += i; }  // \
            else { lin += i; col -= i; }               // /
        }

        // Verifica se está dentro dos limites
        if (lin < 0 || lin >= TAM || col < 0 || col >= TAM)
            return 0;

        // Verifica sobreposição
        if (tabuleiro[lin][col] == NAVIO)
            return 0;
    }
    return 1; // Pode posicionar
}

// Função para posicionar um navio
void posicionarNavio(int tabuleiro[TAM][TAM], int linha, int coluna, int direcao, int diagonal) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        int lin = linha;
        int col = coluna;

        if (diagonal == 0) {
            if (direcao == 0) lin += i;
            else col += i;
        } else {
            if (direcao == 0) { lin += i; col += i; }
            else { lin += i; col -= i; }
        }

        tabuleiro[lin][col] = NAVIO;
    }
}

int main() {
    int tabuleiro[TAM][TAM] = {0}; // Inicializa o tabuleiro com água (0)

    printf("=== BATALHA NAVAL – NIVEL INTERMEDIARIO ===\n");

    // --- Posicionando os 4 navios (2 normais + 2 diagonais) ---
    // Navio 1: Horizontal (linha 0, coluna 0)
    if (podePosicionar(tabuleiro, 0, 0, 1, 0))
        posicionarNavio(tabuleiro, 0, 0, 1, 0);

    // Navio 2: Vertical (linha 2, coluna 5)
    if (podePosicionar(tabuleiro, 2, 5, 0, 0))
        posicionarNavio(tabuleiro, 2, 5, 0, 0);

    // Navio 3: Diagonal principal (\) a partir de (5,0)
    if (podePosicionar(tabuleiro, 5, 0, 0, 1))
        posicionarNavio(tabuleiro, 5, 0, 0, 1);

    // Navio 4: Diagonal secundária (/) a partir de (4,9)
    if (podePosicionar(tabuleiro, 4, 9, 1, 1))
        posicionarNavio(tabuleiro, 4, 9, 1, 1);

    // Exibe o tabuleiro final
    exibirTabuleiro(tabuleiro);

    return 0;
}
