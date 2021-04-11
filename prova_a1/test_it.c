#include <stdio.h>
#include "prova_a1.h"
#define N 3

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

int main(){
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
    
    return 0;
}