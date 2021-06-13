#include<stdlib.h>
#include<stdio.h>

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
        previous = p; //previous aponta para onde p está apontando
        p = p->next;
    }

    newElem = (Tlist *) malloc (sizeof(Tlist)); //alocação de memória do novo elemento
    newElem->info = elem;

    if(previous == NULL){ //lista vazia e inserção do primeiro elemento
        newElem->next = l; //next do novo elemento aponta para a cabeça da lista que neste momento é NULL;
        l = newElem; //a cabeça da lista aponta para o novo elemento
    } else { //lista não vazia
        newElem->next = p; //ponteiro next do novo elemento (newElem) aponta para o mesmo lugar de p
        previous->next = newElem; //ponteiro next do previous aponta para o novo elemento
    }

    return l;
}

//imprimir o conteúdo de uma lista
void print_list (Tlist *l){
    Tlist *p = l;

    while (p != NULL){
        printf("[%d]->", p->info);
        p = p->next;
    }
    printf("NULL\n");
}

//liberar a memória ocupada por uma lista
void clear(Tlist *l){
    Tlist *p = l;

    while (p){ //é o mesmo que dizer "enquanto p existir/for verdade" ou p!= NULL
        Tlist *q = p;
        p = p->next;
        free(q);
    }
}

//Busca linear (não recursiva) por um elemento na lista
Tlist *search (Tlist *l, int elem){
    Tlist *p = l; //ponteiro auxiliar apontando para a cabeça da lista
    while(p){ //enquanto tivermos elemento na lista
        if(p->info != elem){
            p = p->next; //se o elemento atual for diferente daquele buscado, anda para o próximo
        } else {
            return p; //retorna o elemento da lista assim que ele é encontrado
        }
    }
    return p; //só será executado se o elemento não estiver na lista
}

//Remover um determinado elemento da lista
Tlist *remove (Tlist *l, int elem){
    
}