#include<stdio.h>
#include "single_list.h"
#define ELEMENTS 4

int main(){
    int value, i, elem, rem;
    Tlist *list, *s;
    list = create();

    for(i=1; i<=ELEMENTS; i++){
        printf("Insira um elemento: ");
        scanf("%d", &value);
        list = ordered_insert(list, value);
    }

    printf("Digite o elemento a ser encontrado: ");
    scanf("%d", &elem);
    s = search (list, elem);
    
    print_list(list);

    printf("\n\n");
    if(s){
        printf("Elemento %d encontrado\n", s->info);
    } else {
        printf("Elemento nao encontrado\n");
    }

    printf("Digite o elemento a ser removido: ");
    scanf("%d", &elem); //re-uso da variável 'elem' ou use o 'rem'
    list = remove_elem(list, elem);
    print_list(list);

    clear(list);
    //clear(s);

    printf("Cheguei\n");
    return 0;    
}