#include <stdio.h>
#include <string.h>

// Estrutura para armazenar as informações das cartas
struct Carta {
    char estado[3];
    char codigo[4];
    char nome[50];
    unsigned long int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade;
};

// Função para calcular densidade populacional
float calcularDensidade(struct Carta c) {
    return c.populacao / c.area;
}

int main() {
    struct Carta carta1, carta2;
    int opcao1, opcao2;
    float valor1_c1 = 0, valor1_c2 = 0, valor2_c1 = 0, valor2_c2 = 0;
    float soma1 = 0, soma2 = 0;

    printf("=== Cadastro das Cartas do Super Trunfo ===\n\n");

    // Cadastro da Carta 1
    printf("=== Carta 1 ===\n");
    printf("Estado: ");
    scanf("%s", carta1.estado);
    printf("Código: ");
    scanf("%s", carta1.codigo);
    printf("Nome da cidade: ");
    scanf(" %[^\n]", carta1.nome);
    printf("População: ");
    scanf("%lu", &carta1.populacao);
    printf("Área (km²): ");
    scanf("%f", &carta1.area);
    printf("PIB (em bilhões): ");
    scanf("%f", &carta1.pib);
    printf("Número de pontos turísticos: ");
    scanf("%d", &carta1.pontos_turisticos);
    carta1.densidade = calcularDensidade(carta1);

    printf("\n");

    // Cadastro da Carta 2
    printf("=== Carta 2 ===\n");
    printf("Estado: ");
    scanf("%s", carta2.estado);
    printf("Código: ");
    scanf("%s", carta2.codigo);
    printf("Nome da cidade: ");
    scanf(" %[^\n]", carta2.nome);
    printf("População: ");
    scanf("%lu", &carta2.populacao);
    printf("Área (km²): ");
    scanf("%f", &carta2.area);
    printf("PIB (em bilhões): ");
    scanf("%f", &carta2.pib);
    printf("Número de pontos turísticos: ");
    scanf("%d", &carta2.pontos_turisticos);
    carta2.densidade = calcularDensidade(carta2);

    // Menu de seleção do primeiro atributo
    printf("\n=== MENU DE COMPARAÇÃO (1ª escolha) ===\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("Escolha o primeiro atributo: ");
    scanf("%d", &opcao1);

    // Menu dinâmico — remove a primeira opção escolhida
    printf("\n=== MENU DE COMPARAÇÃO (2ª escolha) ===\n");
    for (int i = 1; i <= 5; i++) {
        if (i == opcao1) continue; // não mostrar o mesmo atributo
        switch (i) {
            case 1: printf("1 - População\n"); break;
            case 2: printf("2 - Área\n"); break;
            case 3: printf("3 - PIB\n"); break;
            case 4: printf("4 - Pontos Turísticos\n"); break;
            case 5: printf("5 - Densidade Demográfica\n"); break;
        }
    }
    printf("Escolha o segundo atributo: ");
    scanf("%d", &opcao2);

    // Evitar escolha duplicada
    if (opcao1 == opcao2) {
        printf("\nErro: você não pode escolher o mesmo atributo duas vezes!\n");
        return 1;
    }

    // Comparação do primeiro atributo
    switch (opcao1) {
        case 1:
            valor1_c1 = carta1.populacao;
            valor1_c2 = carta2.populacao;
            break;
        case 2:
            valor1_c1 = carta1.area;
            valor1_c2 = carta2.area;
            break;
        case 3:
            valor1_c1 = carta1.pib;
            valor1_c2 = carta2.pib;
            break;
        case 4:
            valor1_c1 = carta1.pontos_turisticos;
            valor1_c2 = carta2.pontos_turisticos;
            break;
        case 5:
            valor1_c1 = carta1.densidade;
            valor1_c2 = carta2.densidade;
            break;
        default:
            printf("\nOpção inválida!\n");
            return 1;
    }

    // Comparação do segundo atributo
    switch (opcao2) {
        case 1:
            valor2_c1 = carta1.populacao;
            valor2_c2 = carta2.populacao;
            break;
        case 2:
            valor2_c1 = carta1.area;
            valor2_c2 = carta2.area;
            break;
        case 3:
            valor2_c1 = carta1.pib;
            valor2_c2 = carta2.pib;
            break;
        case 4:
            valor2_c1 = carta1.pontos_turisticos;
            valor2_c2 = carta2.pontos_turisticos;
            break;
        case 5:
            valor2_c1 = carta1.densidade;
            valor2_c2 = carta2.densidade;
            break;
        default:
            printf("\nOpção inválida!\n");
            return 1;
    }

    // Exibição dos atributos escolhidos e valores
    printf("\n=== RESULTADO DAS COMPARAÇÕES ===\n");
    printf("Carta 1: %s\n", carta1.nome);
    printf("Carta 2: %s\n\n", carta2.nome);

    // Atributo 1
    printf("Atributo 1: ");
    switch (opcao1) {
        case 1: printf("População\n"); break;
        case 2: printf("Área\n"); break;
        case 3: printf("PIB\n"); break;
        case 4: printf("Pontos Turísticos\n"); break;
        case 5: printf("Densidade Demográfica\n"); break;
    }
    printf("%s: %.2f | %s: %.2f\n\n", carta1.nome, valor1_c1, carta2.nome, valor1_c2);

    // Atributo 2
    printf("Atributo 2: ");
    switch (opcao2) {
        case 1: printf("População\n"); break;
        case 2: printf("Área\n"); break;
        case 3: printf("PIB\n"); break;
        case 4: printf("Pontos Turísticos\n"); break;
        case 5: printf("Densidade Demográfica\n"); break;
    }
    printf("%s: %.2f | %s: %.2f\n\n", carta1.nome, valor2_c1, carta2.nome, valor2_c2);

    // Aplicando regras — para densidade, o menor vence
    float resultado1 = (opcao1 == 5) ? (valor1_c1 < valor1_c2 ? 1 : 0) : (valor1_c1 > valor1_c2 ? 1 : 0);
    float resultado2 = (opcao2 == 5) ? (valor2_c1 < valor2_c2 ? 1 : 0) : (valor2_c1 > valor2_c2 ? 1 : 0);

    // Soma dos atributos
    soma1 = valor1_c1 + valor2_c1;
    soma2 = valor1_c2 + valor2_c2;

    printf("Soma dos atributos:\n");
    printf("%s: %.2f\n", carta1.nome, soma1);
    printf("%s: %.2f\n\n", carta2.nome, soma2);

    // Resultado final com operador ternário
    printf("=== RESULTADO FINAL ===\n");
    if (soma1 == soma2) {
        printf("Empate!\n");
    } else {
        printf("Vencedora: %s\n", (soma1 > soma2) ? carta1.nome : carta2.nome);
    }

    printf("\n=== Fim do Programa ===\n");

    return 0;
}
