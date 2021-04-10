/*
Crie uma estrutura que possua:
1- um codigo de duas letras que represente um pais
2- o total de casos de COVID-19 naquele pais
3- o total de óbitos em decorrencia de COVID-19 aqui no pais

o programa deve calcular o país com a menor e maior relação de óbitos por caso
de COVID-19 e exibir os respectivos valores e países correspondentes. Considere
pelo menos 5 países
*/

#include <stdio.h>
#define COUNTRY_TOTAL 2

typedef struct{
    char acron[2];
    long cases;
    long deaths;
} Country; 

void population_countries(Country *c){ // é um ponteiro do tipo Country -> a var c será meu array de estrutura dos países que vão passar por parâmetro
    int i;
    for (i = 0; i < COUNTRY_TOTAL; i++){
        printf("Sigla do Pais: ");
        scanf("%s", c[i].acron); // o & NÃO é necessário por ser uma String 
        printf("Total de Casos: ");
        scanf("%ld", &c[i].cases); // o & é necessário por ser um tipo primário de variável
        printf("Total de Mortes: ");
        scanf("%ld", &c[i].deaths); // o & é necessário por ser um tipo primário de variável
    }
}

int main(){
    Country countries [COUNTRY_TOTAL];

    int highest_ratio, lowest_ratio;

    population_countries(countries);

    highest_ratio = lowest_ratio = 0; //assume que o país de indice zero possui a menor e a maior relação de óbitos/casos

    //tanto para o maior quanto para o menor, foi necessário o uso de "cast" nos cálculos. Motivo: 45:40m - Aula 05
    for(int i = 1; i < COUNTRY_TOTAL; i++){
        if((double) countries[i].deaths/countries[i].cases > (double)countries[highest_ratio].deaths/countries[highest_ratio].cases){
            highest_ratio = i; //não pega o valor, apenas o indice que contém o valor. 
        }

        if((double)countries[i].deaths/countries[i].cases < (double)countries[lowest_ratio].deaths/countries[lowest_ratio].cases){
            lowest_ratio = i; //não pega o valor, apenas o indice que contém o valor. 
        }
    }

    for (int i = 0; i < COUNTRY_TOTAL; i++){
        printf("---------------------\n");
        printf("Country: %s\n", countries[i].acron);
        printf("Num Cases: %ld\n", countries[i].cases);
        printf("Total deaths: %ld\n", countries[i].deaths);
    }
    printf("\n+++++++++++++++++++++++++++++++++++++++++++++++\n");
    
    
    printf("Pais a com menor taxa de obitos/casos: %s\n", countries[lowest_ratio].acron);
    printf("Total de casos: %ld\n", countries[lowest_ratio].cases);
    printf("Total de mortes: %ld\n", countries[lowest_ratio].deaths);
    printf("Relacao obitos/casos: %.2lf\n", (double) countries[lowest_ratio].deaths/countries[lowest_ratio].cases);

    printf("\n+++++++++++++++++++++++++++++++++++++++++++++++\n");

    printf("Pais com a maior taxa de obitos/casos: %s\n", countries[highest_ratio].acron);
    printf("Total de casos: %ld\n", countries[highest_ratio].cases);
    printf("Total de mortes: %ld\n", countries[highest_ratio].deaths);
    printf("Relacao obitos/casos: %.2lf\n", (double) countries[highest_ratio].deaths/countries[highest_ratio].cases);

    return 0;
}