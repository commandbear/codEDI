//Script com as soluções que compõem a Avaliação Individual Avaliativa (AIA) da Universidade Veiga de Almeida

#include <stdio.h>
#include <locale.h>
#include "prova_a1.h"
#define TOTSTUDENTS 3

//Questão 1
void populateStudents (Student *s){
    //Permite ao usuário entrar com os dados de N alunos
    for (int i = 0; i < TOTSTUDENTS; i++ ){
        printf("---------------------------------------\n");
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
    
    //Permite mostrar os dados de N alunos
    for(i = 0; i < TOTSTUDENTS; i++){
        printf("=======================================\n");
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

    //Lista de Aprovados e Reprovados
    printf("===================Aprovado==================\n");
    for(i = 0; i < TOTSTUDENTS; i++){        
        if(avg[i] >= 6){            
            for (int aux = 0; aux < TOTSTUDENTS; aux++){
                printf("---------------------------------------\n");
                printf("Student ID: %ld\n", s[i].code);
                printf("Name: %s\n", s[i].name);
                printf("Grade 1: %.1f\n", s[i].grade1);
                printf("Grade 2: %.1f\n", s[i].grade2);
                printf("Grade 3: %.1f\n", s[i].grade3);
            }
        }
        if(avg[i] < 6){
            printf("===================Reprovado==================\n");
            for (int aux = 0; aux < TOTSTUDENTS; aux++){
                printf("---------------------------------------\n");
                printf("Student ID: %ld\n", s[i].code);
                printf("Name: %s\n", s[i].name);
                printf("Grade 1: %.1f\n", s[i].grade1);
                printf("Grade 2: %.1f\n", s[i].grade2);
                printf("Grade 3: %.1f\n", s[i].grade3);
            }
        }
    }

    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("Aluno com a primeira nota maior: %s -> %.1f\n", s[highest_grade].name, s[highest_grade].grade1);
    printf("Aluno com a maior media: %s -> %.1f\n", s[highest_avg].name, avg[highest_avg]);
    printf("Aluno com a menor media: %s -> %.1f\n", s[lowest_avg].name, avg[lowest_avg]);
}

int main(){
    int choice;
    Student students[TOTSTUDENTS];
    setlocale(LC_ALL, "Portuguese"); //aceitar caracteres especiais e acentuação
    printf("Digite a questão desejada {1, 2, 3, 4, 5} -> {0} Sair:");
    scanf("%d", &choice);
    switch (choice){
    case 1:
        populateStudents(students); //passa os parâmetros do vetor para a função
        reports(students);
        break;
    case 2:
        printf("Questão 2 em construção\n"); break;
    case 3:
        printf("Questão 3 em construção\n"); break;
    case 4:
        printf("Questão 4 em construção\n"); break;
    case 5:
        printf("Questão 5 em construção\n"); break;
    case 0:
        printf("Saindo...\n\n"); break;
    default:
        printf("ON BUILDING\n"); break;
    }    

    return 0;
}
