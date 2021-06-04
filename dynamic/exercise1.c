/*
Q1-Escreva uma função que permita ao usuário criar um vetor de 
inteiros dinamicamente alocado com o tamanho escolhido por ele

Q2-Escreva uma função que permita ao usuário alterar
dinamicamente o tamanho de um vetor passado como parâmetro
*/
#include<stdio.h>
#include<stdlib.h>

int *new_vector(int size){
    int *vector;

    vector = malloc(size * sizeof(int));

    return vector;
}

void populate_vector(int *v, int size){
    int i;
    for(i=0; i<size; i++){
        printf("Posição %d do vetor: ", i);
        scanf("%d", &v[i]);
    }
}

void fill_vector(int *v, int size, int new_size){
    int i;
    for(i=size; i<new_size; i++){
        printf("Posição %d do vetor: ", i);
        scanf("%d", &v[i]);
    }
}

void print_vector(int *v, int size){
    int i;
    for(i=0; i<size; i++){
        printf("Elemento %d do vetor: %d\n", i, v[i]);
    }
}

int *resize_vector(int *v, int size){
    v = realloc(v, size * sizeof(int));

    return v;
}

int main(){
    int *v, size, new_size;

    printf("Escolha o tamanho do vetor: ");
    scanf("%d", &size);

    v = new_vector(size);

    populate_vector(v, size);

    print_vector(v, size);

    printf("Escolha o novo tamanho do vetor: ");
    scanf("%d", &new_size);

    printf("--------------------------------------------------------\n");
    v = resize_vector(v, new_size);

    fill_vector(v, size, new_size);
    
    print_vector(v, new_size);
    
    free(v);

    return 0;
}