#include <stdio.h>
#include <string.h>

int main() {

    //Declarando as variáveis de forma simples
    char codigo[5], codigo2[5], cidade[50], cidade2[50], estado[50], estado2[50];
    int pontos, pontos2, opcao;
    float area, area2, pib, pib2, densidade, densidade2, percapita, percapita2;
    unsigned long int populacao, populacao2;

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

    switch (opcao)
    {
      case 1:
            printf("Comparando a População\n");
            printf("%s x %s!\n", cidade, cidade2);
            printf("População 1 : %lu x População 2 : %lu\n ", populacao, populacao2);
            if (populacao > populacao2)
            {
              printf("CARTA 1 VENCEU\n");
            }
            else if (populacao2 > populacao)
            {
               printf("CARTA 2 VENCEU\n");
            } else 
            {
               printf ("EMPATE !\n");
            }
         break;
      case 2:
            printf("Comparando as Áreas\n");         
            printf("%s x %s!\n", cidade, cidade2);
            printf("Área 1 : %.2f x Área 2: %.2f\n ", area, area2);
            if (area > area2)
            {
              printf("CARTA 1 VENCEU\n");
            }
            else if (area2 > area)
            {
               printf("CARTA 2 VENCEU\n");
            } else 
            {
               printf ("EMPATE !\n");
            }
         break;
      case 3:
            printf("Comparando os PIBS\n");            
            printf("%s x %s!\n", cidade, cidade2);
            printf("PIB 1 : %.2f x PIB 2 : %.2f\n", pib, pib2);
            if (pib > pib2)
            {
              printf("CARTA 1 VENCEU\n");
            }
            else if (pib2 > pib)
            {
               printf("CARTA 2 VENCEU\n");
            } else 
            {
               printf ("EMPATE !\n");
            }
         break;
      case 4:
            printf("Comparando os Pontos Turísticos\n");            
            printf("%s x %s!\n", cidade, cidade2);
            printf("Pontos 1 : %i x Pontos 2 : %i\n", pontos, pontos2);
            if ( pontos > pontos2 )
            {
              printf("CARTA 1 VENCEU\n");
            }
            else if ( pontos2 > pontos )
            {
               printf("CARTA 2 VENCEU\n");
            } else 
            {
               printf ("EMPATE !\n");
            }
         break;
      case 5:
            printf("Comparando a Densidade Demográfica\n");            
            printf("%s x %s!\n", cidade, cidade2);
            printf("Densidade 1 : %.2f x Densidade 2 : %.2f\n", densidade, densidade2);
            if (densidade < densidade2 )
            {
              printf("CARTA 1 VENCEU\n");
            }
            else if (densidade2 < densidade )
            {
               printf("CARTA 2 VENCEU\n");
            } else 
            {
               printf ("EMPATE !\n");
            }
         break;
         default:
         printf("Opção Selecionada é inválida !");
    }

    return 0;
}
