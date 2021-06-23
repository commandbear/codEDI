#include<stdio.h>
#include<stdlib.h>
#include"lists.h"
#include"circular.h"

Tcl *gera_circular(Tlist *l){
    Tcl *lc = create_circular();

    
}

int main(){
    Tlist *lista = create();
    int elem;
    char choose;

    do{
        printf("Digite um elemento para inserir na FILA: ");
        scanf("%d", &elem);
        lista = ordered_insert(lista, elem);
        setbuf(stdin, NULL);
        printf("Deseja continuar? [s/n]: ");
        scanf("%c", &choose);
    }while(choose != 'n');

    print_list(lista);
    
    do{
        printf("Digite um elemento para remover da FILA: ");
        scanf("%d", &elem);
        remove_elem(lista, elem);
        setbuf(stdin, NULL);
        printf("Deseja continuar? [s/n]: ");
        scanf("%c", &choose);
    }while(choose != 'n');
    print_list(lista);

    clear(lista);
    
    return 0;
}