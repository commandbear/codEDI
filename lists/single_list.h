#include<stdlib.h>
#include<stdio.h>
#include<time.h> //para o exercício 1
#define NUM_ELEMENTS 10
#define SEARCH_ELEMENTS 3

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
Tlist *remove_elem (Tlist *l, int elem){
    Tlist *previous = NULL, *p = l;

    while ((p != NULL) && (p->info != elem)){ //andando na lista até ela acabar ou encontrar o elemento
        previous = p;
        p = p->next;
    }
    if(!p){ //p aponta para null, ou seja, o fim da lista foi alcançado - e não encontrei o elemento na lista
        printf("Elemento %d nao encontrado\n", elem);
        return l; //retorna a própria lista original sem remover nenhum elemento
    }
    if(!previous){//significa que o elemento a ser removido foi encontrado na primeira posição da lista
        l = l->next; //cabeça da lista passa a apontar para o segundo elemento
    } else {
        previous->next = p->next; //o anterior passa a apontar para o elemento seguinte ao elemento p que será removido
    }
    printf("Elemento %d removido da lista\n", p->info);
    free(p);
    return l;
} 

//Para o Exercício 1
void random_draw(){
    Tlist *list = create(), *found = create();
    time_t t;
    int i, r;

    //Inicializar a geração dos números pseudo-aleatórios
    srand((unsigned) time(&t));

    for(i=1; i<=NUM_ELEMENTS; i++){
        list = ordered_insert(list, rand() % 20); //busca randomica entre 0 e 20
    }

    printf("Lista criada \"aleatoriamente\" com os seguintes elementos:\n");
    print_list(list);

    i = 1;
    do{
        r = rand() % 20; 
        found = search(list, r);
        if(found){
            printf("Elemento %d encontrado na busca.\n", found->info);
            found = remove_elem(found, found->info);
            i++;
        } else {
            printf("Elemento %d nao encontrado na busca.\n", r);
        }
    } while(i <= SEARCH_ELEMENTS);
    printf("+++++++++++Busca Encerrada+++++++++++\n");

    clear(found);
    clear(list);
    return 0;
}
