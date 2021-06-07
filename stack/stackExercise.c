/*
Crie uma função que receba duas pilhas, sendo uma não vazia e outra vazia.
A função deve retornar a segunda pilha como uma cópia exata da primeira,
preservando a integridade delas, e contendo a seguinte assinatura:
    Tstack *copy_stack (Tstack *s1, Tstack *s2);
*/
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(){
    Tstack *stack = create(), *stack_copy;
    int elem;

    printf("Insira o valor de info para o elemento da pilha: ");
    scanf("%d", &elem);
    push(stack, elem);
    printf("Insira o valor de info para o elemento da pilha: ");
    scanf("%d", &elem);
    push(stack, elem);
    printf("Insira o valor de info para o elemento da pilha: ");
    scanf("%d", &elem);
    push(stack, elem);

    empty(stack) ? printf("Pilha Vazia\n\n") : printf("Pilha Nao Vazia\n\n"); //ternário

    printf("++++++++++++++++++ PILHA 1 ++++++++++++++++++\n");
    print_stack(stack);

    copy_stack(stack, stack_copy);

    printf("++++++++++++++++++ PILHA 2 ++++++++++++++++++\n");
    print_stack(stack_copy);

    clear(stack);
    clear(stack_copy);

    return 0;
}