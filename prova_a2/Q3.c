#include<stdio.h>
#include<stdlib.h>
#include"lists.h"
#include"circular.h"

Tcl *gera_circular(Tlist *l){
    Tcl *lc = create_circular();
    Tlist *p = l, *q = create();
    int elem;

    while(p){
        q = p;
        elem = p->info;
        lc = insert_circular(lc, elem);
        p = p->next;
    }
    return lc;
}

int main(){
    Tlist *lista = create();
    int elem;
    char choose;

    do{
        printf("Digite um elemento para inserir na LISTA: ");
        scanf("%d", &elem);
        lista = ordered_insert(lista, elem);
        setbuf(stdin, NULL);
        printf("Deseja continuar? [s/n]: ");
        scanf("%c", &choose);
    }while(choose != 'n');

    print_list(lista);
    print_circular(gera_circular(lista));

    clear(lista);
    
    return 0;
}