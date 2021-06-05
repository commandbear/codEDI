#include<stdio.h>
#include "queues.h"

int main(){
    Tqueue *q;
    q = create();

    if(empty(q)){
        printf("Fila vazia >>>>> %d\n", empty(q));
    }
    else{
        printf("Fila não vazia >>>>>> %d\n", empty(q));
    }

    return 0;
}