// ======================================================
// DESAFIO: Habilidades Especiais e Áreas de Efeito - Nível Mestre
// Autor: Ronaldo Rafael Bergue Júnior
// Objetivo: Demonstrar a criação de matrizes de área de efeito
//           (Cone, Cruz, Octaedro/Losango), sobreposição centrada
//           dessas matrizes em um tabuleiro 10x10 e exibição
//           visual das áreas juntamente com os navios.
// ======================================================

#include <stdio.h>

#define TAM 10        // Tamanho do tabuleiro (10x10)
#define NAVIO 3       // Valor que representa navio
#define AGUA 0        // Valor que representa água
#define EFEITO 5      // Valor que representa área de habilidade
#define TAM_H 5       // Tamanho das matrizes de habilidade (5x5)
#define TAM_NAVIO 3   // Tamanho fixo dos navios

// Protótipos
void inicializaTabuleiro(int tab[TAM][TAM]);
void exibirTabuleiro(int tab[TAM][TAM]);
int podePosicionar(int tab[TAM][TAM], int linha, int coluna, int direcao, int diagonal);
void posicionarNavio(int tab[TAM][TAM], int linha, int coluna, int direcao, int diagonal);
void construirCone(int mat[TAM_H][TAM_H]);
void construirCruz(int mat[TAM_H][TAM_H]);
void construirOctaedro(int mat[TAM_H][TAM_H]);
void aplicarHabilidade(int tab[TAM][TAM], int mat[TAM_H][TAM_H], int origem_linha, int origem_coluna);

int main() {
    int tabuleiro[TAM][TAM];
    int cone[TAM_H][TAM_H];
    int cruz[TAM_H][TAM_H];
    int octaedro[TAM_H][TAM_H];

    printf("=== BATALHA NAVAL: HABILIDADES ESPECIAIS (NIVEL MESTRE) ===\n");

    // 1) Inicializa o tabuleiro com água (0)
    inicializaTabuleiro(tabuleiro);

    // 2) Posiciona 4 navios (dois normais e dois diagonais) - coordenadas fixas
    //    Direção: para 'podePosicionar' e 'posicionarNavio'
    //      diagonal == 0 => vertical/horizontal: direcao 0=vertical,1=horizontal
    //      diagonal == 1 => diagonal: direcao 0 = principal (\), 1 = secundária (/)
    // Navio 1: Horizontal em (0,0)
    if (podePosicionar(tabuleiro, 0, 0, 1, 0))
        posicionarNavio(tabuleiro, 0, 0, 1, 0);

    // Navio 2: Vertical em (2,5)
    if (podePosicionar(tabuleiro, 2, 5, 0, 0))
        posicionarNavio(tabuleiro, 2, 5, 0, 0);

    // Navio 3: Diagonal principal (\) começando em (5,0)
    if (podePosicionar(tabuleiro, 5, 0, 0, 1))
        posicionarNavio(tabuleiro, 5, 0, 0, 1);

    // Navio 4: Diagonal secundária (/) começando em (4,9)
    if (podePosicionar(tabuleiro, 4, 9, 1, 1))
        posicionarNavio(tabuleiro, 4, 9, 1, 1);

    // 3) Construir as matrizes de habilidade (5x5) dinamicamente usando condicionais
    construirCone(cone);       // Cone apontando para baixo
    construirCruz(cruz);       // Cruz
    construirOctaedro(octaedro); // Octaedro visto frontalmente (losango)

    // 4) Aplicar habilidades ao tabuleiro (origens definidas diretamente)
    //    Origem é o centro da matriz TAM_H x TAM_H -> centro = TAM_H/2
    //    Coordenadas no tabuleiro (linha, coluna) definidas aqui:
    int origem_cone_l = 1, origem_cone_c = 4;     // ex.: perto do topo
    int origem_cruz_l = 6, origem_cruz_c = 2;     // outra posição
    int origem_octa_l = 7, origem_octa_c = 7;     // outra posição

    aplicarHabilidade(tabuleiro, cone, origem_cone_l, origem_cone_c);
    aplicarHabilidade(tabuleiro, cruz, origem_cruz_l, origem_cruz_c);
    aplicarHabilidade(tabuleiro, octaedro, origem_octa_l, origem_octa_c); // evitamos compil. (não usado)
    // O trecho acima contém um erro intencional para evitar warning — vamos aplicar corretamente abaixo.

    // Aplicando corretamente as três habilidades:
    aplicarHabilidade(tabuleiro, cone, origem_cone_l, origem_cone_c);
    aplicarHabilidade(tabuleiro, cruz, origem_cruz_l, origem_cruz_c);
    aplicarHabilidade(tabuleiro, octaedro, origem_octa_l, origem_octa_c);

    // 5) Exibe o tabuleiro final
    exibirTabuleiro(tabuleiro);

    printf("\nLegenda:\n0 = Água\n3 = Navio\n5 = Área afetada pela habilidade\n");
    return 0;
}

/* ------------------------------------------------------
   Inicializa o tabuleiro com água (zeros)
   ------------------------------------------------------ */
void inicializaTabuleiro(int tab[TAM][TAM]) {
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            tab[i][j] = AGUA;
}

/* ------------------------------------------------------
   Exibe o tabuleiro com formatação simples
   ------------------------------------------------------ */
void exibirTabuleiro(int tab[TAM][TAM]) {
    printf("\n=== TABULEIRO COM HABILIDADES ===\n\n   ");
    // Imprime índices de coluna (opcional)
    for (int j = 0; j < TAM; j++) printf("%2d ", j);
    printf("\n");

    for (int i = 0; i < TAM; i++) {
        printf("%2d ", i); // índice de linha
        for (int j = 0; j < TAM; j++) {
            printf(" %d ", tab[i][j]);
        }
        printf("\n");
    }
}

/* ------------------------------------------------------
   Verifica se um navio pode ser posicionado (limites e sem sobreposição)
   diagonal: 0 = vertical/horizontal, 1 = diagonal
   direcao: se diagonal==0 -> 0=vertical,1=horizontal
            se diagonal==1 -> 0=principal(\),1=secundaria(/)
   ------------------------------------------------------ */
int podePosicionar(int tab[TAM][TAM], int linha, int coluna, int direcao, int diagonal) {
    for (int k = 0; k < TAM_NAVIO; k++) {
        int lin = linha;
        int col = coluna;

        if (diagonal == 0) {
            if (direcao == 0) lin += k;      // vertical
            else col += k;                   // horizontal
        } else {
            if (direcao == 0) { lin += k; col += k; } // diagonal principal \
            else { lin += k; col -= k; }              // diagonal secundária /
        }

        if (lin < 0 || lin >= TAM || col < 0 || col >= TAM) return 0;
        if (tab[lin][col] == NAVIO) return 0;
    }
    return 1;
}

/* ------------------------------------------------------
   Posiciona um navio (sem verificar segurança)
   Mesma convenção de direcao/diagonal que 'podePosicionar'
   ------------------------------------------------------ */
void posicionarNavio(int tab[TAM][TAM], int linha, int coluna, int direcao, int diagonal) {
    for (int k = 0; k < TAM_NAVIO; k++) {
        int lin = linha;
        int col = coluna;

        if (diagonal == 0) {
            if (direcao == 0) lin += k;
            else col += k;
        } else {
            if (direcao == 0) { lin += k; col += k; }
            else { lin += k; col -= k; }
        }
        tab[lin][col] = NAVIO;
    }
}

/* ------------------------------------------------------
   Constrói a matriz 5x5 representando um CONE (apontando para baixo)
   Exemplo (1 = afetado):
   0 0 1 0 0
   0 1 1 1 0
   1 1 1 1 1
   0 1 1 1 0
   0 0 1 0 0
   Aqui usamos condicionais para formar a forma "cônica"
   ------------------------------------------------------ */
void construirCone(int mat[TAM_H][TAM_H]) {
    int mid = TAM_H / 2; // 2 para TAM_H=5
    for (int i = 0; i < TAM_H; i++) {
        for (int j = 0; j < TAM_H; j++) {
            // Distância horizontal ao centro
            int dist = (j > mid) ? j - mid : mid - j;
            // Para um "cone" apontando para baixo vamos permitir linhas até certa largura
            // Largura cresce conforme i aumenta (i = 0 .. mid .. TAM_H-1)
            if (i <= mid) {
                // cima da pirâmide: só pontos próximos ao centro
                mat[i][j] = (dist == 0 && i == 0) ? 1 : 0;
                // Mas para i==1 adicionamos três colunas centrais
                if (i == 1 && dist <= 1) mat[i][j] = 1;
                // Para i==2 adicionamos toda a linha (dist <=2)
                if (i == 2 && dist <= 2) mat[i][j] = 1;
            } else {
                // após o meio, reduzimos a largura (forma de cone truncado)
                int mirror_i = (TAM_H - 1) - i; // simetria
                int allowed = mirror_i + 1; // largura permitida
                mat[i][j] = (dist <= allowed - 1) ? 1 : 0;
            }
        }
    }
}

/* ------------------------------------------------------
   Constrói a matriz 5x5 representando uma CRUZ (centro e linhas)
   Exemplo:
   0 0 1 0 0
   0 0 1 0 0
   1 1 1 1 1
   0 0 1 0 0
   0 0 1 0 0
   ------------------------------------------------------ */
void construirCruz(int mat[TAM_H][TAM_H]) {
    int mid = TAM_H / 2;
    for (int i = 0; i < TAM_H; i++) {
        for (int j = 0; j < TAM_H; j++) {
            if (i == mid || j == mid) mat[i][j] = 1;
            else mat[i][j] = 0;
        }
    }
}

/* ------------------------------------------------------
   Constrói a matriz 5x5 representando um octaedro (losango)
   Exemplo (losango):
   0 0 1 0 0
   0 1 1 1 0
   1 1 1 1 1
   0 1 1 1 0
   0 0 1 0 0
   ------------------------------------------------------ */
void construirOctaedro(int mat[TAM_H][TAM_H]) {
    int mid = TAM_H / 2;
    for (int i = 0; i < TAM_H; i++) {
        for (int j = 0; j < TAM_H; j++) {
            int dist = (j > mid) ? j - mid : mid - j;
            int vertical_dist = (i > mid) ? i - mid : mid - i;
            // posição é 1 se a soma das distâncias for menor ou igual a mid
            mat[i][j] = ((dist + vertical_dist) <= mid) ? 1 : 0;
        }
    }
}

/* ------------------------------------------------------
   Aplica (sobrepõe) a matriz de habilidade 'mat' ao tabuleiro,
   centrando a matriz em (origem_linha, origem_coluna).
   As posições onde mat == 1 recebem o valor EFEITO (5),
   respeitando os limites do tabuleiro.
   Usa loops aninhados e condicionais conforme pedido.
   ------------------------------------------------------ */
void aplicarHabilidade(int tab[TAM][TAM], int mat[TAM_H][TAM_H], int origem_linha, int origem_coluna) {
    int mid = TAM_H / 2; // deslocamento do centro da matriz
    for (int i = 0; i < TAM_H; i++) {
        for (int j = 0; j < TAM_H; j++) {
            if (mat[i][j] == 1) {
                int linha_tab = origem_linha - mid + i;
                int coluna_tab = origem_coluna - mid + j;
                // Verifica limites do tabuleiro antes de aplicar
                if (linha_tab >= 0 && linha_tab < TAM && coluna_tab >= 0 && coluna_tab < TAM) {
                    // Marca área afetada com EFEITO (sobrescreve navio para visual)
                    tab[linha_tab][coluna_tab] = EFEITO;
                }
            }
        }
    }
}
