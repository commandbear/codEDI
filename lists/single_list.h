#include<stdlib.h>

//estrutura básica de uma lista
typedef struct list{
    int info;
    struct list *next;    
} Tlist;

//criação de uma lista simples vazia
Tlist *create(){
    return NULL;
}

//inserção ordenada de elementos em uma lista.
Tlist *ordered_insert (Tlist *l, int elem){
    Tlist *p = l; //ponteiro auxiliar para navegar pela lista (NUNCA MANIPULAR O PONTEIRO RECEBIDO COMO PARÂMETRO)
    Tlist *newElem; //novo elemento da lista a ser inserido
    Tlist *previous = NULL; //aponta para o elemento anterior ao atual

    while (p != NULL && p->info <= elem){
        previous = p;
        p = p->next;
    }

    newElem = (Tlist *) malloc (sizeof(Tlist));
    newElem->info = elem;

    if(previous == NULL){
        newElem->next = l;
        l = newElem;
    } else {
        newElem->next = p;
    }
}