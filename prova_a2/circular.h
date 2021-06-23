#include<stdlib.h>
#include<stdio.h>

typedef struct circular{
    int info;
    struct circular *next;    
} Tcl;

Tcl *create_circular(){
    return NULL;
}

Tcl *insert_circular(Tcl *l, int elem){
    Tcl *new_elem = (Tcl *) malloc (sizeof(Tcl));
    new_elem->info = elem;

    if(!l){
        new_elem->next = new_elem;
        return new_elem;
    }

    new_elem->next = l->next;
    l->next = new_elem;
    return l;
}

void *clear_circular(Tcl *l){
    if(l){
        Tcl *p = l->next;
        while (p != l){
            Tcl *q = p;
            p = p->next;
            free(q);
        }
        free(p);
    }
}

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

Tcl *search_circular(Tcl *l, int elem){
    if(!l){
        return NULL;
    }

    if(l->info == elem){
        return l;
    }
    
    Tcl *p = l->next;
    while (p != l && p->info != elem){
        p = p->next;
    }

    if(p == l){
        return NULL;
    }

    return p;
}

Tcl *remove_circular(Tcl *l, int elem){
    if(!l){
        printf("Lista vazia ou nao existe\n");
        return NULL;
    }

    if(l->info == elem && l->next == l){
        printf("Elemento %d removido era o unico existente na lista\n", l->info);
        free(l);
        return NULL;
    }

    Tcl *p = l->next;
    Tcl *previous = l;

    while(p != l && p->info != elem){
        previous = p;
        p = p->next;
    }

    if(p == l && p->info != elem){
        printf("O elemento a ser removido nao foi encontrado");
        return l;
    }
    if(p == l){
        l = l->next;
    }

    previous->next = p->next;
    printf("Elemento %d removido\n", p->info);
    free(p);    
    return l;
}