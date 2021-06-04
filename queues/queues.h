//Biblioteca de funções
//Definições da Estrutura de Filas

#include<stdlib.h>

//Definição de um nó (elemento) da fila
typedef struct node{
    int info;
    struct node *prox;    
} Tnode; //T de "tipo"

//Definição da estrutura da fila
typedef struct queue{
    Tnode *start, *end;
} Tqueue; 

//Criação de uma fila vazia
Tqueue *create(){
    Tqueue *q = (Tqueue *) malloc (sizeof(Tqueue));

    q->start = q->end = NULL; //ambos os ponteiros de inicio e fim recebem NULL 
    //q = malloc (100 * sizeof(Tqueue));

    return q;
}
