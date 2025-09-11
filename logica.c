#include <stdio.h>

// O codigo não le strings como BELO HORIZONTE, somente Sp por exemplo, pois não estou utilziando o fgets ainda para retirar o buffer do enter


int main() {

    //Declarando as variáveis de forma simples
    char codigo[5], codigo2[5], cidade[50], cidade2[50], estado[50], estado2[50];
    int pontos, pontos2;
    float area, area2, pib, pib2, densidade, densidade2, percapita, percapita2;
    unsigned long int populacao, populacao2;

    //Inserindo as informações da primeira carta
    printf("Digite o primeiro estado : \n");
    scanf("%s", estado);

    printf("Digite o primeiro código : \n");
    scanf("%s", codigo);

    printf("Digite o nome da primeira cidade : \n");
    scanf("%s", cidade);
    
    printf("Digite a população da primeira cidade : \n");
    scanf("%lu",  &populacao);

    printf("Digite a primeira area em km : \n");
    scanf("%f", &area);

    printf("Digite o primeiro pib dessa cidade : \n");
    scanf("%f", &pib);

    printf("Digite a quantidade de pontos turísticos da primeira cidade : \n");
    scanf("%i", &pontos);

    //Inserindo as informaçoes da segunda cidade

    printf("Digite o segundo estado : \n");
    scanf("%s", estado2);

    printf("Digite o segundo código : \n");
    scanf("%s", codigo2);

    printf("Digite o nome da segunda cidade : \n");
    scanf("%s", cidade2);

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

     //Adicionando Lógica (Módulo 3) Utilizando if e else

     printf("COMPARANDO AS CARTAS (ATRIBUTO : POPULAÇÃO):\n");
     printf("CARTA 1 - %s (%s) %lu\n", cidade, estado, populacao);
     printf("CARTA 2 - %s (%s): %lu\n", cidade2, estado2, populacao2);

     if (populacao > populacao2)
     {
        printf("Carta 1 Venceu %s !\n", cidade);
     }
     else if (populacao < populacao2) {
        printf("Carta 2 Venceu %s!\n", cidade2);
     } else { 
            printf("EMPATE!\n");
     }
    
    return 0;


}