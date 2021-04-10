/*
    Escreva uma função recursiva que calcula e retorna a soma de todos
    os valores inteiros armazenados em um vetor de "n" posições
*/
//Explicação: 1h:22:45m - Aula 5
#include <stdio.h>
#define N 5

int recursive_sum (int *vet, int size){ //1h:25:36
    if(size < 1){
        return 0;
    }
    else if(size == 1){
        return vet[0];
    } else {
        return vet[size - 1] + recursive_sum(vet, size-1);
    }
}

//1h:30:50m
/* 
    Vetor de Tamanho 2: [3, 7] -> vai cair no else
    O else retorna: vet[1] + recursion_sum(vet, 2-1) -> vetor na posição 1 (7) + chamada recursiva de vetor na posição "tamanho menos um" (2-1=1)
    A chamada recursiva devolve ele no else if-> retorna o vetor na posição zero (3)
    vet[1] + 3
    Retorna para main: 7 + 3 <=> 10
*/

//É POSSÍVEL TRANSFORMAR A FUNÇÃO ACIMA EM UMA FUNÇÃO RECURSIVA COM TERNÁRIO? Sim !
int recursive_sum_ternary(int *vet, int size){
    return (size < 1 ? 0 : (size == 1 ? vet[0] : vet[size - 1] + recursive_sum_ternary(vet, size-1)));
}

int main (){
    int vet[N] = {3, 7, 14, 1, 4};
    printf("Soma recursiva do vetor = %d\n", recursive_sum(vet, N));
    printf("Soma recursiva do vetor c/ ternary= %d\n", recursive_sum_ternary(vet, N));
    return 0;
}