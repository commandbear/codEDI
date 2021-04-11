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
    float avg = 0;
    
    //Permite ao usuário entrar com os dados de N alunos
    for(i = 0; i < TOTSTUDENTS; i++){
        printf("==========================\n");
        printf("Student ID: %ld\n", s[i].code); //está excluindo zeros a esquerda (corrigir)
        printf("Name: %s\n", s[i].name);
        printf("Grade 1: %.1f\n", s[i].grade1);
        printf("Grade 2: %.1f\n", s[i].grade2);
        printf("Grade 3: %.1f\n", s[i].grade3);
    }

    //Encontra o aluno com a maior nota na primeira prova
    for(i = 1; i < TOTSTUDENTS; i++){
        if(s[i].grade1 > s[highest_grade].grade1){
            highest_grade = i;
        } 
    }
    

    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("The highest first grade is: %s -> %.1f\n", s[highest_grade].name, s[highest_grade].grade1);
}

int main(){
    Student students[TOTSTUDENTS];

    populateStudents(students); //passa os parâmetros do vetor para a função
    reports(students);

    return 0;
}
