#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das cartas
// Objetivo: No nível novato você deve criar as cartas representando as cidades utilizando scanf para entrada de dados e printf para exibir as informações.

int main() {
  // Área para definição das variáveis para armazenar as propriedades das cidades
    char Estado[50];
    char Codigo[5];
    char Cidade[50];
    int  Populacao;
    float Area;
    float Pib;
    int Turisticos;
    float Pibcapita;
    float densidade;

    char Estado2[50];
    char Codigo2[5];
    char Cidade2[50];
    int  Populacao2;
    float Area2;
    float Pib2;
    int Turisticos2;
    float Pibcapita2;
    float densidade2; // Área para entrada de dados
  printf("Carta 01\n");

printf("Estado: ");
scanf("%s", Estado);
    
printf("Código: ");
scanf("%s", Codigo);
getchar();

printf("Cidade: ");
fgets(Cidade, 50, stdin);
Cidade[strcspn(Cidade, "\n")] = 0;

printf("População: ");
scanf("%d", &Populacao);

printf("Área: ");
scanf("%f", &Area);

printf("PIB: ");
scanf("%f", &Pib);

printf("Pontos Turísticos: ");
scanf("%d", &Turisticos);

Pibcapita = Pib / Populacao;
densidade = Populacao / Area;
    

  printf("Carta 02\n");

printf("Estado: ");
scanf("%s", Estado2);
    
printf("Código: ");
scanf("%s", Codigo2);
getchar();

printf("Cidade: ");
fgets(Cidade, 50, stdin);
Cidade[strcspn(Cidade2, "\n")] = 0;

printf("População: ");
scanf("%d", &Populacao2);

printf("Área: ");
scanf("%f", &Area2);

printf("PIB: ");
scanf("%f", &Pib2);

printf("Pontos Turísticos: ");
scanf("%d", &Turisticos2);

Pibcapita2 = Pib2 / Populacao2;
densidade2 = Populacao2 / Area2;



  // Área para exibição dos dados da cidade
printf("\n===== Carta 1 Cadastrada =====\n");
    printf("Estado: %s\n", Estado);
    printf("Código: %s\n", Codigo);
    printf("Cidade: %s\n", Cidade);
    printf("População: %d Milhões\n", Populacao);
    printf("Área: %.2f km²\n", Area);
    printf("PIB: %.2f bilhões\n", Pib);
    printf("Pontos Turísticos: %d\n", Turisticos);
    printf("PIB per capita: %f reais\n", Pibcapita);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade);



    printf("\n===== Carta 2 Cadastrada =====\n");
    printf("Estado: %s\n", Estado2);
    printf("Código: %s\n", Codigo2);
    printf("Cidade: %s\n", Cidade2);
    printf("População: %d Milhões\n", Populacao2);
    printf("Área: %.2f km²\n", Area2);
    printf("PIB: %.2f bilhões\n", Pib2);
    printf("Pontos Turísticos: %d\n", Turisticos2);
    printf("PIB per capita: %f reais\n", Pibcapita2);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade2);

    
    
return 0;
} 