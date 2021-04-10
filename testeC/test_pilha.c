// Inserção e Remoção de itens de uma pilha, sem o uso de uma função recursiva

#include <stdio.h>
#include <stdlib.h>
#define MAXTAM 100

typedef struct {
    int Item[MAXTAM]; //Item[100] = {0..99}
    int Topo; //posição do vetor que é o topo da pilha
} TPilha;

//Função de Inicialização da Pilha de Processos
void TPilha_start(TPilha *p){ //recebe o parâmetro como referência a partir de um ponteiro
    p -> Topo = -1; //especifica que o topo inicial da pilha
}

//Função que verifica se a pilha está vazio ou não
int TPilha_empty (TPilha *p){
    if(p -> Topo == -1){
        return 1; //retorna que a pilha está vazia
    } else {
        return 0; //retorna que a pilha não está vazia
    }
}

//Função que verifica se a pilha não está lotada
int TPilha_full(TPilha *p){
    if(p->Topo == MAXTAM-1){
        return 1;
    } else {
        return 0;
    }
}

//Função de inserção de itens na pilha
void TPilha_insert(TPilha *p, int x){ //x é o valor a ser inserido
    if(TPilha_full(p) == 1){
        printf("ERRO> Pilha Lotada\n");
    } else {
        p->Topo++;
        p->Item[p->Topo] = x;
    }
}

//Função de Remoção de itens da pilha
int TPilha_remove(TPilha *p){
    int aux;
    if(TPilha_empty(p) == 1){
        printf("ERRO> Pilha Vazia\n");
    } else{
        aux = p->Item[p->Topo];
        p->Topo--;
        return aux;
    }
}

int main (){
    TPilha *p = (TPilha*)malloc(sizeof(TPilha));
    TPilha_start(p);
    TPilha_insert(p, 10);
    TPilha_insert(p, 20);
    TPilha_insert(p, 30);

    int aux;

    aux = TPilha_remove(p);
    printf("\nSaiu: %d", aux);
    aux = TPilha_remove(p);
    printf("\nSaiu: %d", aux);
    aux = TPilha_remove(p);
    printf("\nSaiu: %d", aux);

    return 0;
}