//Script com as soluções que compõem a Avaliação Individual Avaliativa (AIA) da Universidade Veiga de Almeida

#include <stdio.h>
#include "prova_a1.h"
#define TOTSTUDENTS 3

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
    float avg[TOTSTUDENTS];
    int highest_avg, lowest_avg;
    
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
    
    //Encotra a maior e menor média geral dos alunos
    highest_avg = lowest_avg = 0;
    for(i = 0; i < TOTSTUDENTS; i++){
        avg[i] = (s[i].grade1 + s[i].grade2 + s[i].grade3)/3;
        if(avg[i] > avg[highest_avg]){
            highest_avg = i;
        } else if (avg[i] < avg[lowest_avg]){
            lowest_avg = i;
        }        
    }

    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("The highest first grade is: %s -> %.1f\n", s[highest_grade].name, s[highest_grade].grade1);
    printf("The highest general average is: %s -> %.1f\n", s[highest_avg].name, avg[highest_avg]);
    printf("The lowest general average is: %s -> %.1f\n", s[lowest_avg].name, avg[lowest_avg]);
}

int main(){
    Student students[TOTSTUDENTS];

    populateStudents(students); //passa os parâmetros do vetor para a função
    reports(students);

    return 0;
}
