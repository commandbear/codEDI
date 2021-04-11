#include <stdio.h>
#include "prova_a1.h"
#define N 3

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
void populate_teams(Team *t){
    for(int i = 0; i < N; i++){
        printf("---------------------------------------\n");
        setbuf(stdin, NULL);
        printf("Time: ");
        scanf("%[A-Z a-z]", t[i].name);
        printf("Vitorias: ");
        scanf("%d", &t[i].victories);
        printf("Empates: ");
        scanf("%d", &t[i].draws);
        printf("Derrotas: ");
        scanf("%d", &t[i].defeats);
        printf("Saldo: ");
        scanf("%d", &t[i].goal_diff);
    }
}
void tournment(Team *t){
    for (int i = 0; i < N; i++){
        printf("=======================================\n");
        printf("Time    : %s\n", t[i].name);
        printf("Vitorias: %d\n", t[i].victories);
        printf("Empates : %d\n", t[i].draws);
        printf("Derrotas: %d\n", t[i].defeats);
        printf("Saldo   : %d\n", t[i].goal_diff);
    } 
}
int main(){
    //Questão 1 - Rascunho
    /*
    Student student[N];
    int nota_alta, nota_baixa;
    testeIteracao(student);

    for (int i = 0; i < N; i++){
        printf("\n++++++++++++++++++++++++++++++++++\n");
        printf("Nome: %s\n", student[i].name);
        printf("Nota 1: %.1f\n", student[i].grade1);        
        printf("Nota 2: %.1f\n", student[i].grade2);
    }

    nota_alta = 0;
    for (int i = 1; i < N; i++){
        if(student[i].grade1 > student[nota_alta].grade1){
            nota_alta = i;
        }
    }
    printf("Primeira Nota mais alta: %f", student[nota_alta].grade1);
    */
    
   //Questão 2 - Rascunho
   Team teams[N];
   populate_teams(teams);
   tournment(teams);
    
    return 0;
}