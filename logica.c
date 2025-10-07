
#include <stdio.h>
#include <string.h>

int main() {

    //Declarando as variáveis de forma simples
    char codigo[5], codigo2[5], cidade[50], cidade2[50], estado[50], estado2[50];
    int pontos, pontos2;
    float area, area2, pib, pib2, densidade, densidade2, percapita, percapita2;
    unsigned long int populacao, populacao2;

    //variáveis para as comparações
    
    int opcao, opcao2;

    float valor_atributo1_carta1, valor_atributo1_carta2;
    float valor_atributo2_carta1, valor_atributo2_carta2;

    char nome_atributo1[50],nome_atributo2[50];

    // Variáveis para armazenar os pontos e a soma
    int pontos_carta1 = 0, pontos_carta2 = 0;
    float soma_carta1 = 0, soma_carta2 = 0;




    //Inserindo as informações da primeira carta
    printf("Digite o primeiro estado : \n");
    fgets(estado, 50, stdin);
    estado[strcspn(estado, "\n")] = 0; // remove o '\n'

    printf("Digite o primeiro código : \n");
    fgets(codigo, 5, stdin);
    codigo[strcspn(codigo, "\n")] = 0;

    printf("Digite o nome da primeira cidade : \n");
    fgets(cidade, 50, stdin);
    cidade[strcspn(cidade, "\n")] = 0;
    
    printf("Digite a população da primeira cidade : \n");
    scanf("%lu",  &populacao);

    printf("Digite a primeira area em km : \n");
    scanf("%f", &area);

    printf("Digite o primeiro pib dessa cidade : \n");
    scanf("%f", &pib);

    printf("Digite a quantidade de pontos turísticos da primeira cidade : \n");
    scanf("%i", &pontos);

    getchar(); // limpa o '\n' deixado no buffer pelo último scanf

    //Inserindo as informaçoes da segunda cidade

    printf("Digite o segundo estado : \n");
    fgets(estado2, 50, stdin);
    estado2[strcspn(estado2, "\n")] = 0;

    printf("Digite o segundo código : \n");
    fgets(codigo2, 5, stdin);
    codigo2[strcspn(codigo2, "\n")] = 0;

    printf("Digite o nome da segunda cidade : \n");
    fgets(cidade2, 50, stdin);
    cidade2[strcspn(cidade2, "\n")] = 0;

    printf("Digite a população da segunda cidade : \n");
    scanf("%lu",  &populacao2);

    printf("Digite a segunda area em km : \n");
    scanf("%f", &area2);

    printf("Digite o segundo pib dessa cidade : \n");
    scanf("%f", &pib2);

    printf("Digite a quantidade de pontos turísticos da segunda cidade :  \n");
    scanf("%i", &pontos2);

    // FUNÇÕES

    densidade = populacao / area;
    densidade2 = populacao2 / area2;

    percapita = (pib * 1000000000) / populacao;
    percapita2 = (pib2 * 1000000000) / populacao2;

    //Imprimindo as informaçoes das cartas, com as informaçoes adquiridas do usuario 

    printf("\n ||------------ CARTA 1 ------------||\n ESTADO : %s\n CÓDIGO : %s\n NOME : %s\n POPULAÇÃO : %lu\n ÁREA : %.2f km²\n PIB : %.2f bilhões de reais\n PONTOS TURÍSTICOS : %i \n DENSIDADE POPULACIONAL : %.2f hab/km²\n PIB PER CAPITA : %.2f reais\n",
    estado, codigo, cidade, populacao, area, pib, pontos, densidade, percapita);
    printf("\n ||------------ CARTA 2 ------------||\n ESTADO : %s\n CÓDIGO : %s\n NOME : %s\n POPULAÇÃO : %lu\n ÁREA : %.2f km² \n PIB : %.2f bilhões de reais\n PONTOS TURÍSTICOS : %i \n DENSIDADE POPULACIONAL : %.2f hab/km²\n PIB PER CAPITA : %.2f reais\n",
     estado2, codigo2, cidade2, populacao2, area2, pib2, pontos2, densidade2, percapita2);

    // Adicionando Lógica e o Menu Interativo com uso do switch

    printf("\n ||------------------ Hora de Batalhar ------------------||!\n Escolha o atributo para compararmos :\n");
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. PIB\n");
    printf("4. Pontos Turísticos\n");
    printf("5. Densidade Demográfica\n");
    scanf("%d", &opcao);


    // Validação da primeira opção
    while (opcao < 1 || opcao >6)
    {
        printf("Opção Inválida ! Digite novamente\n");
        scanf("%d", &opcao);
    }
    
    // Menu dinamico segubndo atributo, excluindo o primeiro

    printf("Digite o Segundo Atributo ! Selecione Diferente do Primeiro\n");

    // só exibir opções que não foram escolhidas anteriormente 
    if (opcao != 1) printf("1. População\n");
    if (opcao != 1) printf("2. Área\n");
    if (opcao != 1) printf("3. PIB\n");
    if (opcao != 1) printf("4. Pontos Turísticos\n");
    if (opcao != 1) printf("5. Densidade Demográfica\n");

    printf("Digite a segunda opção ! Diferente de : %d\n", opcao);
    scanf("%d", opcao2);

    // valida a segunda opção, para que ela não leia se for igual a primeira
    while (opcao2 < 1 || opcao > 6 || opcao2 == opcao) {
        printf("Opção Inválida, Tente Novamente !\n");
        scanf("%d", opcao2);
    }

    // Comparação das duas cartas, baseando-se nos atributos escolhidos
    printf("||------Comparando as Duas cartas-----|| !\n");

    //Primeiro Atributo

    switch (opcao)
    {
    case 1: // População, vence a maior
        strcpy(nome_atributo1, "População");
        valor_atributo1_carta1 = populacao;
        valor_atributo1_carta2 = populacao2;

        // if para a lógica do vencedor
        if (valor_atributo1_carta1 > valor_atributo1_carta2)
        {
            pontos_carta1++;
        }
        else if (valor_atributo1_carta2 > valor_atributo1_carta1)
        {
            pontos_carta2++;
        }
        break;
    
    case 2: // Área, vence a maior
        strcpy(nome_atributo1, "Área"); // declaro o nome do atributo
        valor_atributo1_carta1 = area;
        valor_atributo1_carta2 = area2;

        if (valor_atributo1_carta1 > valor_atributo1_carta2)
        {
            pontos_carta1++;
        }
        else if (valor_atributo1_carta2 > valor_atributo1_carta1)
        {
            pontos_carta2++;
        }
        break;

    case 3 : // PIB , vence o maior
        strcpy(nome_atributo1, "PIB");
        valor_atributo1_carta1 = pib;
        valor_atributo1_carta2 = pib2;


        if (valor_atributo1_carta1 > valor_atributo1_carta2)
        {
            pontos_carta1++;
        }
        else if (valor_atributo1_carta2 > valor_atributo1_carta1)
        {
            pontos_carta2++;
        }
        break;

    case 4 : // Pontos Turísticos, vence o com mais pontos
        strcpy(nome_atributo1, "Pontos Turísticos");
        valor_atributo1_carta1 = pontos;
        valor_atributo1_carta2 = pontos2;


        if (valor_atributo1_carta1 > valor_atributo1_carta2)
        {
            pontos_carta1++;
        }
        else if (valor_atributo1_carta2 > valor_atributo1_carta1)
        {
            pontos_carta2++;
        }
        break;

    case 5 : // Densidade Demográfica, aqui a lógica muda, vence o menor
        strcpy(nome_atributo1, "Densidade Demográfica");
        valor_atributo1_carta1 = densidade;
        valor_atributo1_carta2 = densidade2;


        if (valor_atributo1_carta1 < valor_atributo1_carta2)
        {
            pontos_carta1++;
        }
        else if (valor_atributo1_carta2< valor_atributo1_carta1)
        {
            pontos_carta2++;
        }
        break;
    default: printf("Opção Inválida\n");
        break;
    }

    //Segundo Atributo

    switch (opcao2)
    {
    case 1: // População, vence a maior
        strcpy(nome_atributo2, "População");
        valor_atributo2_carta1 = populacao;
        valor_atributo2_carta2 = populacao2;

        // if para a lógica do vencedor
        if (valor_atributo2_carta1 > valor_atributo2_carta2)
        {
            pontos_carta1++;
        }
        else if (valor_atributo2_carta2 > valor_atributo2_carta1)
        {
            pontos_carta2++;
        }
        break;
    
    case 2: // Área, vence a maior
        strcpy(nome_atributo2, "Área"); // declaro o nome do atributo
        valor_atributo1_carta1 = area;
        valor_atributo2_carta2 = area2;

        if (valor_atributo1_carta2 > valor_atributo2_carta1)
        {
            pontos_carta1++;
        }
        else if (valor_atributo2_carta2 > valor_atributo2_carta1)
        {
            pontos_carta2++;
        }
        break;

    case 3 : // PIB , vence o maior
        strcpy(nome_atributo2, "PIB");
        valor_atributo1_carta1 = pib;
        valor_atributo2_carta2 = pib2;


        if (valor_atributo2_carta1 > valor_atributo2_carta2)
        {
            pontos_carta1++;
        }
        else if (valor_atributo2_carta2 > valor_atributo2_carta1)
        {
            pontos_carta2++;
        }
        break;

    case 4 : // Pontos Turísticos, vence o com mais pontos
        strcpy(nome_atributo2, "Pontos Turísticos");
        valor_atributo2_carta1 = pontos;
        valor_atributo2_carta2 = pontos2;


        if (valor_atributo2_carta1 > valor_atributo2_carta2)
        {
            pontos_carta1++;
        }
        else if (valor_atributo2_carta2 > valor_atributo2_carta1)
        {
            pontos_carta2++;
        }
        break;

    case 5 : // Densidade Demográfica, aqui a lógica muda, vence o menor
        strcpy(nome_atributo1, "Densidade Demográfica");
        valor_atributo2_carta1 = densidade;
        valor_atributo2_carta2 = densidade2;


        if (valor_atributo2_carta1 < valor_atributo2_carta2)
        {
            pontos_carta1++;
        }
        else if (valor_atributo2_carta2< valor_atributo2_carta1)
        {
            pontos_carta2++;
        }
        break;
    default: printf("Opção Inválida\n");
        break;
    }


    // Cálculo e soma dos dois atributos, utilizaremos os operadores ternários para tal tarefa
    soma_carta1 = (opcao == 5 ? 1/valor_atributo1_carta1 : valor_atributo1_carta1) + 
                  (opcao2 == 5 ? 1/valor_atributo2_carta1 : valor_atributo2_carta1);
    
    soma_carta2 = (opcao == 5 ? 1/valor_atributo1_carta2 : valor_atributo1_carta2) + 
                  (opcao2 == 5 ? 1/valor_atributo2_carta2 : valor_atributo2_carta2);

      // Exibição dos resultados da comparação
    printf("\n=== Resultado da Comparação ===\n");
    printf("\nAtributos escolhidos para comparação:\n");
    printf("1. %s\n", nome_atributo1);
    printf("2. %s\n", nome_atributo2);
    
    // Exibição dos valores do primeiro atributo
    printf("\nComparação do primeiro atributo (%s):\n", nome_atributo1);
    
    // Formatação específica para cada tipo de atributo
    if (opcao == 1) { // População
        printf("Carta 1 - %s: %d habitantes\n", cidade, (int)valor_atributo1_carta1);
        printf("Carta 2 - %s: %d habitantes\n", cidade2, (int)valor_atributo1_carta2);
    } else if (opcao == 2) { // Área
        printf("Carta 1 - %s: %.2f km²\n", cidade, valor_atributo1_carta1);
        printf("Carta 2 - %s: %.2f km²\n", cidade2, valor_atributo1_carta2);
    } else if (opcao == 3) { // PIB
        printf("Carta 1 - %s: %.2f bilhões de reais\n", cidade, valor_atributo1_carta1);
        printf("Carta 2 - %s: %.2f bilhões de reais\n", cidade2, valor_atributo1_carta2);
    } else if (opcao == 4) { // Pontos Turísticos
        printf("Carta 1 - %s: %d pontos\n", cidade, (int)valor_atributo1_carta1);
        printf("Carta 2 - %s: %d pontos\n", cidade2, (int)valor_atributo1_carta2);
    } else if (opcao == 5) { // Densidade Populacional
        printf("Carta 1 - %s: %.2f habitantes/km²\n", cidade, valor_atributo1_carta1);
        printf("Carta 2 - %s: %.2f habitantes/km²\n", cidade2, valor_atributo1_carta2);
    } else if (opcao == 6) { // PIB per capita
        printf("Carta 1 - %s: R$ %.2f\n", cidade, valor_atributo1_carta1);
        printf("Carta 2 - %s: R$ %.2f\n", cidade2, valor_atributo1_carta2);
    }
    
    // Exibição do resultado do primeiro atributo
    if (opcao == 5) { // Densidade Populacional (menor valor vence)
        if (valor_atributo1_carta1 < valor_atributo1_carta2) {
            printf("Vencedor no atributo %s: Carta 1 (%s)\n", nome_atributo1, cidade);
        } else if (valor_atributo1_carta2 < valor_atributo1_carta1) {
            printf("Vencedor no atributo %s: Carta 2 (%s)\n", nome_atributo1, cidade2);
        } else {
            printf("Empate no atributo %s!\n", nome_atributo1);
        }
    } else { // Outros atributos (maior valor vence)
        if (valor_atributo1_carta1 > valor_atributo1_carta2) {
            printf("Vencedor no atributo %s: Carta 1 (%s)\n", nome_atributo1, cidade);
        } else if (valor_atributo1_carta2 > valor_atributo1_carta1) {
            printf("Vencedor no atributo %s: Carta 2 (%s)\n", nome_atributo1, cidade2);
        } else {
            printf("Empate no atributo %s!\n", nome_atributo1);
        }
    }
    
    // Exibição dos valores do segundo atributo
    printf("\nComparação do segundo atributo (%s):\n", nome_atributo2);
    
    // Formatação específica para cada tipo de atributo
    if (opcao2 == 1) { // População
        printf("Carta 1 - %s: %d habitantes\n", cidade, (int)valor_atributo2_carta1);
        printf("Carta 2 - %s: %d habitantes\n", cidade2, (int)valor_atributo2_carta2);
    } else if (opcao2 == 2) { // Área
        printf("Carta 1 - %s: %.2f km²\n", cidade, valor_atributo2_carta1);
        printf("Carta 2 - %s: %.2f km²\n", cidade2, valor_atributo2_carta2);
    } else if (opcao2 == 3) { // PIB
        printf("Carta 1 - %s: %.2f bilhões de reais\n", cidade, valor_atributo2_carta1);
        printf("Carta 2 - %s: %.2f bilhões de reais\n", cidade2, valor_atributo2_carta2);
    } else if (opcao2 == 4) { // Pontos Turísticos
        printf("Carta 1 - %s: %d pontos\n", cidade, (int)valor_atributo2_carta1);
        printf("Carta 2 - %s: %d pontos\n", cidade2, (int)valor_atributo2_carta2);
    } else if (opcao2 == 5) { // Densidade Populacional
        printf("Carta 1 - %s: %.2f habitantes/km²\n", cidade, valor_atributo2_carta1);
        printf("Carta 2 - %s: %.2f habitantes/km²\n", cidade2, valor_atributo2_carta2);
    } else if (opcao2 == 6) { // PIB per capita
        printf("Carta 1 - %s: R$ %.2f\n", cidade, valor_atributo2_carta1);
        printf("Carta 2 - %s: R$ %.2f\n", cidade2, valor_atributo2_carta2);
    }
    
    // Exibição do resultado do segundo atributo
    if (opcao2 == 5) { // Densidade Populacional (menor valor vence)
        if (valor_atributo2_carta1 < valor_atributo2_carta2) {
            printf("Vencedor no atributo %s: Carta 1 (%s)\n", nome_atributo2, cidade);
        } else if (valor_atributo2_carta2 < valor_atributo2_carta1) {
            printf("Vencedor no atributo %s: Carta 2 (%s)\n", nome_atributo2, cidade2);
        } else {
            printf("Empate no atributo %s!\n", nome_atributo2);
        }
    } else { // Outros atributos (maior valor vence)
        if (valor_atributo2_carta1 > valor_atributo2_carta2) {
            printf("Vencedor no atributo %s: Carta 1 (%s)\n", nome_atributo2, cidade);
        } else if (valor_atributo2_carta2 > valor_atributo2_carta1) {
            printf("Vencedor no atributo %s: Carta 2 (%s)\n", nome_atributo2, cidade2);
        } else {
            printf("Empate no atributo %s!\n", nome_atributo2);
        }
    }
    
    // Exibição do resultado final baseado na soma dos atributos
    printf("\n=== Resultado Final ===\n");
    printf("Pontuação:\n");
    printf("Carta 1 - %s: %d pontos\n", cidade, pontos_carta1);
    printf("Carta 2 - %s: %d pontos\n", cidade2, pontos_carta2);
    
    // Determina o vencedor final com base na pontuação
    if (pontos_carta1 > pontos_carta2) {
        printf("\nVENCEDOR FINAL: Carta 1 (%s) com %d pontos!\n", cidade, pontos_carta1);
    } else if (pontos_carta2 > pontos_carta1) {
        printf("\nVENCEDOR FINAL: Carta 2 (%s) com %d pontos!\n", cidade2, pontos_carta2);
    } else {
        printf("\nEMPATE FINAL! Ambas as cartas têm %d pontos.\n", pontos_carta1);
    }



    return 0;
}
