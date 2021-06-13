#include<stdio.h>
#include<stdlib.h>
#include"circular.h"
#define SIZE 1

int main(){
    Tcl *circular = create_circular(), *search;
    int elem, i;

    for (i = 1; i <= SIZE; i++){
        printf("Insira o elemento %d da lista circular: ", i);
        scanf("%d", &elem);
        circular = insert_circular(circular, elem);
    }

    /*
    search = search_circular(circular, 10);
    if(search){
        printf("Elemento encontrado\n");
    } else {
        printf("Elemento nao encontrado\n");
    }
    */

    print_circular(circular);

    circular = remove_circular(circular, 10);

    print_circular(circular);

    clear_circular(circular);
    
    return 0;
}