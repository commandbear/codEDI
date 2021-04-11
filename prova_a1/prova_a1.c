//Script com as soluções que compõem a Avaliação Individual Avaliativa (AIA) da Universidade Veiga de Almeida

#include <stdio.h>
#include "prova_a1.h"
#define TOTSTUDENTS 2

//Questão 1
void populateStudents (Student *s){
    for (int i = 0; i < TOTSTUDENTS; i++ ){
        printf("-----------------------------\n");
        printf("Student ID: ");
        scanf("%ld", &s[i].code);
        setbuf(stdin, NULL); 
        printf("Name: ");
        scanf("%[A-Z a-z]", s[i].name); //REGEX
        printf("Grade 1: ");
        scanf("%f", &s[i].grade1);        
        printf("Grade 2: ");
        scanf("%f", &s[i].grade2);
        printf("Grade 3: ");
        scanf("%f", &s[i].grade3);
    }
}

void reports(Student *s){
    int i;
    float highest_grade = 0, lowest_grade = 0;

    for(i = 0; i < TOTSTUDENTS; i++){
        printf("==========================\n");
        printf("%d Student ID: %ld\n", i+1, s[i].code);
        printf("%d Name: %s\n", i+1, s[i].name);
        printf("Grade 1: %.1f\n", s[i].grade1);
        printf("Grade 2: %.1f\n", s[i].grade2);
        printf("Grade 3: %.1f\n", s[i].grade3);
    }

    for(i = 0; i < TOTSTUDENTS; i++){
        if(s[i].grade1 > s[i].grade2 && s[i].grade2 > s[i].grade3){
            highest_grade = s[i].grade1; //valor mais alto é atribuido à variável highest_grade (nota mais alta)
            lowest_grade = s[i].grade3
        } else if(s[i].grade2 > s[i].grade1 && s[i].grade1 > [i].grade3  ){
            highest_grade = s[i].grade2;
            lowest_grade = s[i].grade3;
        } else if(s[i].grade3 > s[i].grade2 && s[i].grade2 > s[i].grade1){
            highest_grade = s[i].grade3;
            lowest_grade = s[i].grade1;
        } else if(s[i].grade1 > s[i].grade3 && s[i].grade3 > s[i].grade2){
            highest_grade = s[i].grade1;
            lowest_grade = s[i].grade2;
        } else if(s[i].grade2 > s[i].grade3 && s[i].grade3 > s[i].grade1){
            highest_grade = s[i].grade2;
            lowest_grade = s[i].grade1;
        } else if(s[i].grade3 > s[i].grade1 && s[i].grade1 > s[i].grade2){
            highest_grade = s[i].grade3;
            lowest_grade = s[i].grade2;
        }
    }
}

int main(){
    Student students[TOTSTUDENTS];

    populateStudents(students); //passa os parâmetros do vetor para a função
    reports(students);

    return 0;
}
