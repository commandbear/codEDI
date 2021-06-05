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

    //remover um elemento na fila
    int remove_node(Tqueue *q){
        if(empty (q)){
            exit(1);
        }

        //ponteiro q->start aponta para o primeiro elemento da fila
        int value = q->start->info;

        //criar um novo ponteiro nó que aponta para o primeiro elemento da fila, que será removido
        Tnode *p = q->start;

        //andar com o ponteiro de inicio da fila para o próximo elemento
        q->start = q->start->next;

        //apontar o ponteiro de fim da fila para NULL, caso o elemento a ser removido seja o último restante
        if(!q->start){
            q->end = NULL;
        }

        //liberar a memória do elemento removido da fila
        free(p);

        return value;
    }

    //limpar uma fila e liberar a sua memória e dos seus elementos
    void clear(Tqueue *q){
        Tnode *p = q->start, *aux;
        //enquanto existirem elementos na fila
        while(p){
            aux = p;        //utilizar o auxiliar para não perder o apontamento
            p = aux->next;  //caminhar com o ponteiro p
            free(aux);      //liberar a memória e elemento em questão da fila
        }
        free(q); //liberar a memória da fila
    }

     
}