#include <stdio.h>

// Estrutura para armazenar os dados de cada carta
typedef struct {
    char estado[3];
    char codigo[4];
    char nome[30];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
} Carta;

int main() {
    Carta c1, c2;

    // ===== Cadastro da Carta 1 =====
    printf("===== Cadastro da Carta 1 =====\n");
    printf("Estado (ex: SP): ");
    scanf("%2s", c1.estado);
    printf("Código (ex: A01): ");
    scanf("%3s", c1.codigo);
    printf("Nome da Cidade: ");
    scanf(" %[^\n]", c1.nome);
    printf("População: ");
    scanf("%d", &c1.populacao);
    printf("Área (km²): ");
    scanf("%f", &c1.area);
    printf("PIB (em bilhões): ");
    scanf("%f", &c1.pib);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &c1.pontos_turisticos);

    // ===== Cadastro da Carta 2 =====
    printf("\n===== Cadastro da Carta 2 =====\n");
    printf("Estado (ex: RJ): ");
    scanf("%2s", c2.estado);
    printf("Código (ex: A02): ");
    scanf("%3s", c2.codigo);
    printf("Nome da Cidade: ");
    scanf(" %[^\n]", c2.nome);
    printf("População: ");
    scanf("%d", &c2.populacao);
    printf("Área (km²): ");
    scanf("%f", &c2.area);
    printf("PIB (em bilhões): ");
    scanf("%f", &c2.pib);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &c2.pontos_turisticos);

    // ===== Cálculos =====
    c1.densidade_populacional = c1.populacao / c1.area;
    c2.densidade_populacional = c2.populacao / c2.area;

    c1.pib_per_capita = (c1.pib * 1e9) / c1.populacao; // PIB em bilhões convertido para reais
    c2.pib_per_capita = (c2.pib * 1e9) / c2.populacao;

    // ===== Escolha do atributo para comparação =====
    // AQUI VOCÊ ESCOLHE QUAL ATRIBUTO SERÁ COMPARADO
    // Opções: populacao, area, pib, densidade_populacional, pib_per_capita
    // Exemplo: Comparando População

    printf("\n===== Comparação de Cartas (Atributo: População) =====\n");
    printf("Carta 1 - %s (%s): %d habitantes\n", c1.nome, c1.estado, c1.populacao);
    printf("Carta 2 - %s (%s): %d habitantes\n", c2.nome, c2.estado, c2.populacao);

    if (c1.populacao > c2.populacao) {
        printf("\nResultado: Carta 1 (%s) venceu!\n", c1.nome);
    } else if (c1.populacao < c2.populacao) {
        printf("\nResultado: Carta 2 (%s) venceu!\n", c2.nome);
    } else {
        printf("\nResultado: Empate!\n");
    }

    // ===== Exibe os cálculos =====
    printf("\n===== Informações adicionais =====\n");
    printf("Carta 1 - %s\n", c1.nome);
    printf("  Densidade Populacional: %.2f hab/km²\n", c1.densidade_populacional);
    printf("  PIB per Capita: %.2f\n", c1.pib_per_capita);

    printf("\nCarta 2 - %s\n", c2.nome);
    printf("  Densidade Populacional: %.2f hab/km²\n", c2.densidade_populacional);
    printf("  PIB per Capita: %.2f\n", c2.pib_per_capita);

    return 0;
}
