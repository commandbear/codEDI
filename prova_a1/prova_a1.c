//Script com as soluções que compõem a Avaliação Individual Avaliativa (AIA) da Universidade Veiga de Almeida
//Autor: Yuri Pedro Caetano de Queiroz
//Matrícula: 20151109342

#include <stdio.h>
#include "prova_a1.h"
#define TOTSTUDENTS 5
#define T 3
#define P 6

//Questão 1 - completa
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
    int highest_grade = 0;
    float avg[TOTSTUDENTS];
    int highest_avg, lowest_avg;
    
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

    printf("NOME\t|\tNota 1\t|\tNota 2\t|\tNota 3\t|\tMEDIA\t|\tStatus\n");
    printf("-----------------------------------------------------------------------------------------------------\n");
    for(i = 0; i < TOTSTUDENTS; i++){
        printf("%s\t|\t%.1f\t|\t%.1f\t|\t%.1f\t|\t%.1f\t|", s[i].name, s[i].grade1, s[i].grade2, s[i].grade3, avg[i]);
        if(avg[i] >= 6){
            printf("\tAprovado\n");
        } else {
            printf("\tReprovado\n");
        }
        printf("-----------------------------------------------------------------------------------------------------\n");
    }

    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("Aluno com a primeira nota maior: %s -> %.1f\n", s[highest_grade].name, s[highest_grade].grade1);
    printf("Aluno com a maior media: %s -> %.1f\n", s[highest_avg].name, avg[highest_avg]);
    printf("Aluno com a menor media: %s -> %.1f\n", s[lowest_avg].name, avg[lowest_avg]);
}

//Questão 2 - completa
void populate_teams(Team *t){
    int aux = 0, i;

    for(i = 0; i < T; i++){
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
            printf("Quantidade de jogos devem ser iguais a V+E+D\nREPITA !\n");
        }
    }
}
void tournment(Team *t){
    int totPoints[T], champion = 0, aux = 0, current = 0;
    printf("\n\n[-- Tabela de Clubes --]\n");
    for (int i = 0; i < T; i++){
        printf("=======================================\n");
        printf("Time    : %s\n", t[i].name);
        printf("Vitorias: %d\n", t[i].victories);
        printf("Empates : %d\n", t[i].draws);
        printf("Derrotas: %d\n", t[i].defeats);
        printf("Saldo   : %d\n", t[i].goal_diff);
    }
        
    for (int i = 0; i < T; i++){ 
        totPoints[i] = t[i].victories * 3 + t[i].draws;
        if(totPoints[i] > current || (totPoints[i] == current && t[i].goal_diff > t[champion].goal_diff)){
            current = totPoints[i];
            champion = i;
            aux = i;
        } else if(totPoints[i] == current && t[i].goal_diff == t[champion].goal_diff && aux < i){
            champion = aux;
        }
    }
    printf("O vencedor foi o -> %s com %d pontos\n\n", t[champion].name, totPoints[champion]);
}

//Questão 3
void max_min(int *v, int N, int *max, int *min){
    int i;
    *min = *max = v[0];
    for(i=0; i<N; i++){
        if(v[i] >= *max){
            *max = v[i];
        } else if(v[i] <= *min) {
            *min = v[i];
        }
    }
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
    int maximus, minimus, length;
    Student students[TOTSTUDENTS];
    Team teams[T];
    int vector[8] = {9, 19, 20, 80, 82, 83, 87, 92};
    int vec[8];

    do{
        setbuf(stdin, NULL);
        printf("Digite a questao desejada {1, 2, 3, 4, 5} -> Sair {0}: ");
        scanf("%d", &choice);
        switch (choice){
        case 1: //Executa a questão 1
            populateStudents(students);
            reports(students);
            setbuf(stdin, NULL);
            break;
        case 2: //Executa a questão 2
            populate_teams(teams);
            tournment(teams);
            setbuf(stdin, NULL);
            break;
        case 3: //Executa a questão 3
            for(length = 0; length<8; length++){
                printf("Digite um numeral: ");
                scanf("%d", &vec[length]);
            }            
            max_min(vec, length, &maximus, &minimus);
            printf("Tamanho do vetor: %d\nMaior valor: %d\nMenor valor: %d\n\n", length, maximus, minimus);
            break;
        case 4: //Executa a questão 4
            printf("Digite o elemento desejado: ");
            scanf("%d", &key);
            printf("Index do elemento digitado >> %d\n\n", bin_search(vector, 0, 8, key));
            break;
        case 5: //Executa a questão 5
            printf("Digite o primeiro valor inteiro: ");
            scanf("%d", &x);
            printf("Digite o segundo valor inteiro: ");
            scanf("%d", &n);
            printf("Resultado: %d x %d = %ld\n\n", x, n, multi(x, n));
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
