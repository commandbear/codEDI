#include<stdio.h>
#include<stdlib.h>
#include"queue.h"
#include"stack.h"

//completa
Tstack *Fila2Pilha(Tqueue *f){
    Tstack *p = stackCreator(), *a = stackCreator();

    //queuePrinter(f);
    //printf("%d\n", i = remove_queueNode(f));
    
    while(!emptyQueue(f)){
        push(p, remove_queueNode(f));
    }    
    //stackPrinter(p);
    //pop(p);
    //stackPrinter(p);
    
    while(!emptyStack(p)){
        push(a, pop(p));
    }
    //stackPrinter(a);
    //pop(a);
    //stackPrinter(a);

    return a;    
}

int main(){
    Tqueue *fila = queueCreator();
    int elem;
    char choose;

    do{
        printf("Digite um elemento para inserir na FILA: ");
        scanf("%d", &elem);
        insertInQueue(fila, elem);
        setbuf(stdin, NULL);
        printf("Deseja continuar? [s/n]: ");
        scanf("%c", &choose);
    }while(choose != 'n');
    
    stackPrinter(Fila2Pilha(fila));

    queueCleaner(fila);

    return 0;
}