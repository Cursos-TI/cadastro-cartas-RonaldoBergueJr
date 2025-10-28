#include <stdio.h>
#include <string.h>

// Estrutura para armazenar os dados das cartas
struct Carta {
    char estado[3];
    char codigo[4];
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade;
};

int main() {
    struct Carta carta1, carta2;
    int opcao;

    printf("=== Cadastro das Cartas do Super Trunfo ===\n\n");

    // Cadastro da Carta 1
    printf("=== Carta 1 ===\n");
    printf("Estado: ");
    scanf("%s", carta1.estado);
    printf("Codigo: ");
    scanf("%s", carta1.codigo);
    printf("Nome da cidade: ");
    scanf(" %[^\n]", carta1.nome);
    printf("Populacao: ");
    scanf("%d", &carta1.populacao);
    printf("Area (km²): ");
    scanf("%f", &carta1.area);
    printf("PIB (em bilhões): ");
    scanf("%f", &carta1.pib);
    printf("Número de pontos turísticos: ");
    scanf("%d", &carta1.pontos_turisticos);
    carta1.densidade = carta1.populacao / carta1.area;

    printf("\n");

    // Cadastro da Carta 2
    printf("=== Carta 2 ===\n");
    printf("Estado: ");
    scanf("%s", carta2.estado);
    printf("Codigo: ");
    scanf("%s", carta2.codigo);
    printf("Nome da cidade: ");
    scanf(" %[^\n]", carta2.nome);
    printf("Populacao: ");
    scanf("%d", &carta2.populacao);
    printf("Area (km²): ");
    scanf("%f", &carta2.area);
    printf("PIB (em bilhões): ");
    scanf("%f", &carta2.pib);
    printf("Número de pontos turísticos: ");
    scanf("%d", &carta2.pontos_turisticos);
    carta2.densidade = carta2.populacao / carta2.area;

    // Menu interativo
    printf("\n=== MENU DE COMPARAÇÃO ===\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("Escolha o atributo para comparar: ");
    scanf("%d", &opcao);

    printf("\n=== Resultado da Comparação ===\n");

    switch(opcao) {
        case 1:
            printf("Atributo: População\n");
            printf("%s: %d habitantes\n", carta1.nome, carta1.populacao);
            printf("%s: %d habitantes\n", carta2.nome, carta2.populacao);
            if (carta1.populacao > carta2.populacao) {
                printf("Resultado: %s venceu!\n", carta1.nome);
            } else if (carta1.populacao < carta2.populacao) {
                printf("Resultado: %s venceu!\n", carta2.nome);
            } else {
                printf("Empate!\n");
            }
            break;

        case 2:
            printf("Atributo: Área\n");
            printf("%s: %.2f km²\n", carta1.nome, carta1.area);
            printf("%s: %.2f km²\n", carta2.nome, carta2.area);
            if (carta1.area > carta2.area) {
                printf("Resultado: %s venceu!\n", carta1.nome);
            } else if (carta1.area < carta2.area) {
                printf("Resultado: %s venceu!\n", carta2.nome);
            } else {
                printf("Empate!\n");
            }
            break;

        case 3:
            printf("Atributo: PIB\n");
            printf("%s: %.2f bilhões\n", carta1.nome, carta1.pib);
            printf("%s: %.2f bilhões\n", carta2.nome, carta2.pib);
            if (carta1.pib > carta2.pib) {
                printf("Resultado: %s venceu!\n", carta1.nome);
            } else if (carta1.pib < carta2.pib) {
                printf("Resultado: %s venceu!\n", carta2.nome);
            } else {
                printf("Empate!\n");
            }
            break;

        case 4:
            printf("Atributo: Pontos Turísticos\n");
            printf("%s: %d pontos turísticos\n", carta1.nome, carta1.pontos_turisticos);
            printf("%s: %d pontos turísticos\n", carta2.nome, carta2.pontos_turisticos);
            if (carta1.pontos_turisticos > carta2.pontos_turisticos) {
                printf("Resultado: %s venceu!\n", carta1.nome);
            } else if (carta1.pontos_turisticos < carta2.pontos_turisticos) {
                printf("Resultado: %s venceu!\n", carta2.nome);
            } else {
                printf("Empate!\n");
            }
            break;

        case 5:
            printf("Atributo: Densidade Demográfica\n");
            printf("%s: %.2f hab/km²\n", carta1.nome, carta1.densidade);
            printf("%s: %.2f hab/km²\n", carta2.nome, carta2.densidade);
            if (carta1.densidade < carta2.densidade) { // menor vence
                printf("Resultado: %s venceu!\n", carta1.nome);
            } else if (carta1.densidade > carta2.densidade) {
                printf("Resultado: %s venceu!\n", carta2.nome);
            } else {
                printf("Empate!\n");
            }
            break;

        default:
            printf("Opção inválida! Escolha um número entre 1 e 5.\n");
            break;
    }

    printf("\n=== Fim do Programa ===\n");

    return 0;
}
