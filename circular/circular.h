#include<stdio.h>
#include<stdlib.h>

//Estrutura básica de uma lista circular
typedef struct circular{
    int info;
    struct circular *next;    
} Tcl;

//Criar uma nova lista circular vazia
Tcl *create_circular(){
    return NULL;
}

//Inserir um novo elemento na lista circular no início da lista
Tcl *insert_circular(Tcl *l, int elem){
    Tcl *new_elem = (Tcl *) malloc (sizeof(Tcl));
    new_elem->info = elem;

    if(!l){ //se a lista estiver vazia
        new_elem->next = new_elem; //o next do primeiro elemento aponta para ele mesmo
        return new_elem;
    }

    new_elem->next = l->next;
    l->next = new_elem;
    return l;
}

//Limpar a lista circular da memória
void *clear_circular(Tcl *l){
    if(l){
        Tcl *p = l->next; //Lista auxiliar p recebe o último elemento inserido
        while (p != l){ //se eles forem iguais, é porque só tem 1 elemento na estrutura
            Tcl *q = p;
            p = p->next;
            free(q);
        }        
    }
}

//Imprimir a listas
void print_circular(Tcl *l){
    if(l){
        printf("[%d]->", l->info);
        Tcl *p = l->next;
        while (p != l){
            printf("[%d]->", p->info);
            p = p->next;
        }
    }
    printf("\n");
}

//Busca de um valor em uma lista circular
Tcl *search_circular(Tcl *l, int elem){
    if(!l){
        return NULL;
    }

    if(l->info == elem){ //elemento que estou procurando está no primeiro elemento
        return l;
    }
    
    Tcl *p = l->next;
    while (p != l && p->info != elem){
        p = p->next;
    }

    if(p == l){ //voltei para o inicio e não encontrei o elemento
        return NULL;
    }

    return p; //o elemento encontrado está no p    
}

//Remove um elemento da lista circular caso ele exista
Tcl *remove_circular(Tcl *l, int elem){
    if(!l){
        printf("Lista vazia ou nao existe\n");
        return NULL;
    }

    if(l->info == elem && l->next == l){ //encontrei o elemento que quero remover, e ele é único elemento da lista
        printf("Elemento %d removido era o unico existente na lista\n", l->info);
        free(l);
        return NULL;
    }

    Tcl *p = l->next;
    Tcl *previous = l;

    while(p != l && p->info != elem){ //andando com os dois ponteiros
        previous = p;
        p = p->next;
    }

    if(p == l && p->info != elem){ //Voltamos ao início da lista e não encontramos o elemento
        printf("O elemento a ser removido nao foi encontrado");
        return l;
    }
    if(p == l){ //O elemento a ser removido é o mesmo do início da lista (p == l)
        l = l->next; //o novo l precisa ser o próximo elemento da lista
    }

    previous->next = p->next; //é o próprio novo l. Remove um elemento qualquer que não seja o único elemento na lista
    printf("Elemento %d removido\n", p->info);
    free(p);    
    return l;
}



//int *empty_circular(Tcl *l){}
