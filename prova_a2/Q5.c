#include<stdio.h>
#include<stdlib.h>
#include"lists.h"
#include"stack.h"

void imprime_invertido(Tlist *l){
    Tstack *s = stackCreator();
    Tlist *p = l, *q = create();

    while(p){
        q = p;
        push(s, p->info);
        p = p->next;
    }

    while(!emptyStack(s)){
        printf("%d\n", pop(s));
    }
    
    //clear(q);
    //clear(aux);
    //stackCleaner(s);
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
    imprime_invertido(lista);

    clear(lista);
    return 0;
}