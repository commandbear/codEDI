#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(){
    Tstack *stack = create();
    int elem;
    
    printf("Insira o valor de info para o elemento da pilha: ");
    scanf("%d", &elem);

    push(stack, elem);

    empty(stack) ? printf("Pilha Vazia\n\n") : printf("Pilha Nao Vazia\n\n"); //ternário

    /*if(empty(stack)){
        printf("Pilha Vazia\n\n");
    } else {
        printf("Pilha Nao Vazia\n\n");
    }*/
    
    printf("Elemento %d removido da pilha\n\n", pop(stack));

    empty(stack) ? printf("Pilha Vazia\n\n") : printf("Pilha Nao Vazia\n\n"); //ternário

    /*if(empty(stack)){
        printf("Pilha Vazia\n\n");
    } else {
        printf("Pilha Nao Vazia\n\n");
    }*/

    clear(stack);

    return 0;
}