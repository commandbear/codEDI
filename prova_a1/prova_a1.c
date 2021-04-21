//Script com as soluções que compõem a Avaliação Individual Avaliativa (AIA) da Universidade Veiga de Almeida

#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include "prova_a1.h"
#define TOTSTUDENTS 3
#define N 3
#define P 6

//Questão 1 - incompleta
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

//Questão 2 - completa
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
            printf("Jogos devem ser iguais a V+E+D\nREPITA !\n");
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
    printf("O vencedor foi o -> %s com %d pontos\n", t[champion].name, totPoints[champion]);
}

//Questão 3
void max_min(int *v, int N, int *max, int *min){

}
//Questão 4 - completa
int bin_search(int *v, int begin, int end, int value){
    int mid;
    mid = (begin + end) / 2;
    if(begin > end){
        return -1;
    } else if (value == v[mid]){
        return mid;
    } else if (value < v[mid]){
        bin_search(v, begin, mid-1, value); //procura o elemento do primeiro indice até o meio - 1
    } else {
        bin_search(v, mid+1, end, value); //procura o elemento do meio + 1 até o último indice
    }
}

//Questão 5 - completa
long multi(int a, int b){
    if(a == 0 || b == 0){
        return 0;
    } else if (b>0){
        return multi(a, b-1) + a;
    } else {
        return multi(a, b+1) - a;
    }
}

int main(){
    int choice, x, n, key;
    Student students[TOTSTUDENTS];
    Team teams[N];
    int vector[5] = {1, 2, 3, 4, 5};
    
    do{
        setbuf(stdin, NULL);
        printf("Digite a questao desejada {1, 2, 3, 4, 5} -> {0} Sair: ");
        scanf("%d", &choice);
        switch (choice){
        case 1:
            populateStudents(students);
            reports(students);
            setbuf(stdin, NULL);
            break;
        case 2:
            populate_teams(teams);
            tournment(teams);
            setbuf(stdin, NULL);
            break;
        case 3:
            printf("Questao 3 em construcao\n"); break;
        case 4:
            printf("Digite o elemento desejado: ");
            scanf("%d", &key);
            printf("Index do elemento digitado >> %d\n\n", bin_search(vector, 0, 4, key));
            break;
        case 5:
            printf("Digite o primeiro valor inteiro: ");
            scanf("%d", &x);
            printf("Digite o segundo valor inteiro: ");
            scanf("%d", &n);
            printf("Resultado: %d x %d = %d\n\n", x, n, multi(x, n));
            break;
        case 0:
            printf("\nFim da Prova\n\n"); break;
        default:
            printf("Escolha Incorreta\n");
            setbuf(stdin, NULL);
        }
    } while (choice != 0);    

    return 0;
}
