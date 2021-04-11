#include <stdio.h>
#include "prova_a1.h"
#define N 3
#define P 6

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
    }
}
void tournment(Team *t){
    /*
    for (int i = 0; i < N; i++){
        printf("=======================================\n");
        printf("Time    : %s\n", t[i].name);
        printf("Vitorias: %d\n", t[i].victories);
        printf("Empates : %d\n", t[i].draws);
        printf("Derrotas: %d\n", t[i].defeats);
        printf("Saldo   : %d\n", t[i].goal_diff);
    }*/
    int totPoints[N], champion = 0, aux = 0, current = 0;
    
    for (int i = 0; i < N; i++){ //i == [1]
        totPoints[i] = t[i].victories * 3 + t[i].draws;
        if(totPoints[i] > current){ //current == 0 -> 12p
            current = totPoints[i]; //current = 12
            champion = i; //champion = [0]
            aux = champion; //aux = [0]
        } else if (totPoints[i] == current){//[1] == [0]
            if(t[i].goal_diff <= t[champion].goal_diff){//12 == 12
                champion = aux;
                printf("Primeiro -> Index CHAMPION: %d\nIndex AUX: %d\nIndex i: %d\n", champion, aux, i);
            } 
        }        
        printf("Segundo -> Index CHAMPION: %d\nIndex AUX: %d\nIndex i: %d\n", champion, aux, i);
    }
    
    printf("The CHAMPION IS -> %s: Points = %d\n", t[champion].name, totPoints[champion]);
    printf("The OTHER ARE -> %s: Points = %d\n%s: Points = %d", t[champion].name, totPoints[champion]);
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