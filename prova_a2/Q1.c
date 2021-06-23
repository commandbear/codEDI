#include<stdio.h>
#include<stdlib.h>
#include"stack.h"

int soma_par(Tstack *p){
    Tstack *aux = stackCreator();
    int elem, sum = 0;

    while(!emptyStack(p)){
        push(aux, pop(p));
    }

    while (!emptyStack(aux)){
        elem = pop(aux);
        if(elem % 2 == 0){
            sum += elem;
        }
        push(p, elem);
    }
    stackPrinter(p);

    return sum;
}

int main(){
    Tstack *pilha = stackCreator();
    int elem;
    char choose;

    do{
        printf("Digite um elemento para inserir na PILHA: ");
        scanf("%d", &elem);
        push(pilha, elem);
        setbuf(stdin, NULL);
        printf("Deseja continuar? [s/n]: ");
        scanf("%c", &choose);
    }while(choose != 'n');

    printf("A soma dos pares da pilha eh: %d\n", soma_par(pilha));

    stackCleaner(pilha);
    return 0;
}