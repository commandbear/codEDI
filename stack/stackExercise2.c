/*Implemente uma função que receba três pilhas: s, s_pairs e s_odds. Separe
todos os valores guardados em s de tal forma que os valores pares são colocados
na pilha s_pair (na mesma ordem da pilha de entrada) e os valores ímpares na 
s_odds (na mesma ordem da pilha de entrada). Ao final da execução desta função,
s permanecerá com todos os seus elementos. O protótipo desta função é o seguinte:

void separate_stacks(Tstack *s, Tstack *s_pairs, Tstack *s_odds)
*/

#include<stdio.h>
#include<stdlib.h>
#include"exercise2.h"

int main(){
    int i, element;
    Tstack *stack = create(), *stack_pairs = create(), *stack_odds = create();


    for(i=1; i<=5;i++){
        printf("Digite o %do elemento da pilha: ", i);
        scanf("%d", &element);
        push(stack, element);
    }

    separate_stacks(stack, stack_pairs, stack_odds);

    printf("\n++++++++++++++++Standard stack++++++++++++++++\n");
    print_stack(stack);
    printf("\n++++++++++++++++Pairs stack++++++++++++++++\n");
    print_stack(stack_pairs);
    printf("\n++++++++++++++++Odds stack++++++++++++++++\n");
    print_stack(stack_odds);

    clear(stack);
    clear(stack_pairs);
    clear(stack_odds);
    return 0;
}