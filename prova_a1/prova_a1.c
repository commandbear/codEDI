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
    int highest_grade = 0, lowest_grade = 0;

    
    for(i = 0; i < TOTSTUDENTS; i++){
        printf("==========================\n");
        printf("Student ID: %ld\n", s[i].code);
        printf("Name: %s\n", s[i].name);
        printf("Grade 1: %.1f\n", s[i].grade1);
        printf("Grade 2: %.1f\n", s[i].grade2);
        printf("Grade 3: %.1f\n", s[i].grade3);
    }
    printf("\n\nOUT OF FIRST LOOP -> CRNTY HG: %d\n\n", highest_grade);
    for(i = 1; i < TOTSTUDENTS; i++){
        if(s[i].grade1 > s[highest_grade].grade1){
            highest_grade = i;
        } 
    }
   
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("The highest first grade is %.1f\n", s[highest_grade].grade1);
}

int main(){
    Student students[TOTSTUDENTS];

    populateStudents(students); //passa os parâmetros do vetor para a função
    reports(students);

    return 0;
}
