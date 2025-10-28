#include <stdio.h>

typedef struct {
    char estado[3];
    char codigo[4];
    char nome[30];
    unsigned long int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
    float super_poder;
} Carta;

int main() {
    Carta c1, c2;

    printf("===== Cadastro da Carta 1 =====\n");
    printf("Estado (ex: SP): ");
    scanf("%2s", c1.estado);
    printf("Código (ex: A01): ");
    scanf("%3s", c1.codigo);
    printf("Nome da Cidade: ");
    scanf(" %[^\n]", c1.nome);
    printf("População: ");
    scanf("%lu", &c1.populacao);
    printf("Área (km²): ");
    scanf("%f", &c1.area);
    printf("PIB (em bilhões): ");
    scanf("%f", &c1.pib);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &c1.pontos_turisticos);

    printf("\n===== Cadastro da Carta 2 =====\n");
    printf("Estado (ex: RJ): ");
    scanf("%2s", c2.estado);
    printf("Código (ex: A02): ");
    scanf("%3s", c2.codigo);
    printf("Nome da Cidade: ");
    scanf(" %[^\n]", c2.nome);
    printf("População: ");
    scanf("%lu", &c2.populacao);
    printf("Área (km²): ");
    scanf("%f", &c2.area);
    printf("PIB (em bilhões): ");
    scanf("%f", &c2.pib);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &c2.pontos_turisticos);

    // ---- Cálculos ----
    c1.densidade_populacional = c1.populacao / c1.area;
    c2.densidade_populacional = c2.populacao / c2.area;

    c1.pib_per_capita = (c1.pib * 1e9) / c1.populacao;
    c2.pib_per_capita = (c2.pib * 1e9) / c2.populacao;

    // Super Poder = soma de atributos numéricos + (1 / densidade)
    c1.super_poder = (float)c1.populacao + c1.area + c1.pib + 
                     c1.pontos_turisticos + c1.pib_per_capita + (1.0f / c1.densidade_populacional);

    c2.super_poder = (float)c2.populacao + c2.area + c2.pib + 
                     c2.pontos_turisticos + c2.pib_per_capita + (1.0f / c2.densidade_populacional);

    // ---- Comparações ----
    int comp_pop = c1.populacao > c2.populacao;
    int comp_area = c1.area > c2.area;
    int comp_pib = c1.pib > c2.pib;
    int comp_pontos = c1.pontos_turisticos > c2.pontos_turisticos;
    int comp_densidade = c1.densidade_populacional < c2.densidade_populacional; // menor vence
    int comp_pib_per_capita = c1.pib_per_capita > c2.pib_per_capita;
    int comp_super_poder = c1.super_poder > c2.super_poder;

    // ---- Resultados ----
    printf("\n===== Comparação de Cartas =====\n");

    printf("População: Carta %d venceu (%d)\n", comp_pop ? 1 : 2, comp_pop);
    printf("Área: Carta %d venceu (%d)\n", comp_area ? 1 : 2, comp_area);
    printf("PIB: Carta %d venceu (%d)\n", comp_pib ? 1 : 2, comp_pib);
    printf("Pontos Turísticos: Carta %d venceu (%d)\n", comp_pontos ? 1 : 2, comp_pontos);
    printf("Densidade Populacional: Carta %d venceu (%d)\n", comp_densidade ? 1 : 2, comp_densidade);
    printf("PIB per Capita: Carta %d venceu (%d)\n", comp_pib_per_capita ? 1 : 2, comp_pib_per_capita);
    printf("Super Poder: Carta %d venceu (%d)\n", comp_super_poder ? 1 : 2, comp_super_poder);

    // ---- Exibição dos cálculos ----
    printf("\n===== Detalhes das Cartas =====\n");
    printf("Carta 1 - %s\n", c1.nome);
    printf("  Densidade Populacional: %.2f\n", c1.densidade_populacional);
    printf("  PIB per Capita: %.2f\n", c1.pib_per_capita);
    printf("  Super Poder: %.2f\n", c1.super_poder);

    printf("\nCarta 2 - %s\n", c2.nome);
    printf("  Densidade Populacional: %.2f\n", c2.densidade_populacional);
    printf("  PIB per Capita: %.2f\n", c2.pib_per_capita);
    printf("  Super Poder: %.2f\n", c2.super_poder);

    return 0;
}
