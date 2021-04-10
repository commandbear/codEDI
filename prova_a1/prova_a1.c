//Script com as soluções que compõem a Avaliação Individual Avaliativa (AIA) da Universidade Veiga de Almeida

#include <stdio.h>
#include "prova_a1.h"
#define TOTSTUDENTS 2
//Questão 1
void reports (Student *s){
    int i;
    for (i = 0; i < TOTSTUDENTS; i++ ){
        printf("Student ID: ");
        scanf("%ld", s[i].code);
        printf("Name: ");
        scanf("%[A-Z a-z]", s[i].name);
        printf("Grade 1: ");
        scanf("%f", s[i].grade1)
        printf("Grade 2: ");
        scanf("%f", s[i].grade2);
        printf("Grade 3: ");
        scanf("%f", s[i].grade3);
    }
}



int main(){
    Student students[TOTSTUDENTS];

    reports(students);

    for(int i = 0; i < TOTSTUDENTS; i++){
        printf("%d Student ID: %ld", i+1, students[i].code);
        printf("%d Name: %s", i+1, students[i].name);
        printf("Grade 1: %.1f", students[i].grade1);
        printf("Grade 2: %.1f", students[i].grade2);
        printf("Grade 3: %.1f", students[i].grade3);
    }

    

    return 0;
}
