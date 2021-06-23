#include<stdio.h>
#include<stdlib.h>
#include"lists.h"

int main(){
    Tlist *lista = create();
    int elem;
    char choose;

    do{
        printf("Digite um elemento para inserir na FILA: ");
        scanf("%d", &elem);
        ordered_insert(lista, elem);
        setbuf(stdin, NULL);
        printf("Deseja continuar? [s/n]: ");
        scanf("%c", &choose);
    }while(choose != 'n');

    print_list(lista);
    
    return 0;
}