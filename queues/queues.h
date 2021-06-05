//Biblioteca de funções
//Definições da Estrutura de Filas

#include<stdlib.h>

//Definição de um nó (elemento) da fila
typedef struct node{
    int info;
    struct node *next;    
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

//Verificar se a fila está vazia
int empty(Tqueue *q){
    return !q->end;
}

//Inserir um elemento na fila
void insert(Tqueue *q, int element){
    Tnode *node = (Tnode *) malloc (sizeof(Tnode));
    node->info = element;
    node->next = NULL;

    //Apontar o ponteiro do antigo último elemento para o novo último elemento
    if(q->end){
        q->end->next = node;
    }

    //andar com o fim da fila
    q->end = node;

    //apontar o ponteiro de início caso a fila esteja vazia, e adiciona o elemento na primeira posição
    if(!q->start){
        q->start = node;
    }
}