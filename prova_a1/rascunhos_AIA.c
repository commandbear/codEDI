#include <stdio.h>
#include "prova_a1.h"
#include <stdlib.h>
//#include <string.h>
#define N 3
//#define P 6

//Questão 1 - Rascunho
/*
void testeIteracao(Student *student){
    for(int i = 0; i < N; i++){
        setbuf(stdin, NULL);
        printf("Nome: ");
        scanf("%[A-Z a-z]", student[i].name);
        printf("Nota 1: ");
        scanf("%f", &student[i].grade1);
        printf("Nota 2: ");
        scanf("%f", &student[i].grade2);
    }
}
*/

//Questão 2 - Rascunho
/*
void populate_teams(Team *t){
    int aux = 0, i;

    for(i = 0; i < N; i++){
        printf("---------------------------------------\n");
        setbuf(stdin, NULL);
        printf("Time    : ");
        scanf("%[A-Z a-z]", t[i].name);
        printf("Vitorias: ");
        scanf("%d", &t[i].victories);
        printf("Empates : ");
        scanf("%d", &t[i].draws);
        printf("Derrotas: ");
        scanf("%d", &t[i].defeats);
        printf("Saldo   : ");
        scanf("%d", &t[i].goal_diff);
        if(t[i].victories + t[i].draws + t[i].defeats != P){
            aux = i - 1;
            i = aux;
            printf("Repeat the operation\n");
        }
    }
}
void tournment(Team *t){
    int totPoints[N], champion = 0, aux = 0, current = 0;
    printf("\n\n[-- Tabela de Clubes --]\n");
    for (int i = 0; i < N; i++){
        printf("=======================================\n");
        printf("Time    : %s\n", t[i].name);
        printf("Vitorias: %d\n", t[i].victories);
        printf("Empates : %d\n", t[i].draws);
        printf("Derrotas: %d\n", t[i].defeats);
        printf("Saldo   : %d\n", t[i].goal_diff);
    }
        
    for (int i = 0; i < N; i++){ //i == [1]
        totPoints[i] = t[i].victories * 3 + t[i].draws;
        if(totPoints[i] > current || (totPoints[i] == current && t[i].goal_diff > t[champion].goal_diff)){
            current = totPoints[i];
            champion = i;
            aux = i;
        } else if(totPoints[i] == current && t[i].goal_diff == t[champion].goal_diff && aux < i){
            champion = aux;
        }
    }
    printf("The CHAMPION IS -> %s: Points = %d\n", t[champion].name, totPoints[champion]);
}
*/

//Questão 3 - Rascunho
/*
void max_min(int *v, int N, int *max, int *min){
    int i;
    *min = *max = v[0];
    for(i=0; i<N; i++){
        if(v[i] >= *max){
            *max = v[i];
        } else if(v[i] <= *min) {
            *min = v[i];
        }
    }
}
*/
int main(){
    //Questão 1 - Rascunho
    /*
    Student student[N];
    int nota_alta, nota_baixa;
    testeIteracao(student);
    char status[15];

    printf("NOME\t|\tNota 1\t|\tNota 2\t|\tStatus\n");
    printf("----------------------------------------------------------\n");
    for (int i = 0; i < N; i++){
        printf("%s\t|\t%.1f\t|\t%.1f\t|\t",student[i].name, student[i].grade1, student[i].grade2);
        if(student[i].grade1 + student[i].grade2 / 2 >= 6){
            printf("Aprovado\n");
        } else {
            printf("Reprovado\n");
        }
        printf("----------------------------------------------------------\n");
    }
    */
    /*
    nota_alta = 0;
    for (int i = 1; i < N; i++){
        if(student[i].grade1 > student[nota_alta].grade1){
            nota_alta = i;
        }
    }
    
    printf("Primeira Nota mais alta: %f", student[nota_alta].grade1);
    */
   //Questão 2 - Rascunho
   /*
   Team teams[N];
   populate_teams(teams);
   tournment(teams);
   */
   //Questão 3 - Rascunho
   /*
   int vector[8];
   int maximus, minimus, length;
   for(length = 0; length<8; length++){
       printf("Digite um numeral: ");
       scanf("%d", &vector[length]);
   }

   max_min(vector, length, &maximus, &minimus);

   printf("Tamanho do vetor: %d\nMaior valor: %d\nMenor valor: %d\n\n", length, maximus, minimus);
*/
    //Teste de Alinhamento de Saída
    

   return 0;
}