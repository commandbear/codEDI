#include<stdio.h>
#include"queue.h"

Tqueue *concatena_filas(Tqueue *pairs, Tqueue *odd, Tqueue *all){
    //Tqueue *auxPair = pairs, *auxOdd = odd;
    Tqueue *auxPair = createQ(), *auxOdd = createQ();
    int auxP1, auxI1, auxP2, auxI2, maior;

    while (!emptyQ(auxPair) && !emptyQ(auxOdd)){
        auxP1 = removerQueueNode(pairs);
        //auxP2 = removerQueueNode(auxPair);
        auxI1 = removerQueueNode(odd);
        //auxI2 = removerQueueNode(auxOdd);
        printf("\nPar: %d    Impar: %d\n\n", auxP, auxI);
        if(auxP < auxI){
            insertQ(all, auxP);
            insertQ(auxOdd, auxI);
            printf("Pegou Par\n");
            printQ(all);
        }
        if(auxP > auxI){
            insertQ(all, auxI);
            insertQ(auxPair, auxP);
            printf("Pegou Impar\n");
            printQ(all);
        }
        //auxP = auxI = NULL;
    }
    //clearQ(auxPair);
    //clearQ(auxOdd);
    return all;
}

int main(){
    Tqueue *par = createQ(), *impar = createQ(), *completa = createQ();
    int elemento;
    char escolha;

    do{
        printf("Digite um numero inteiro qualquer: ");
        scanf("%i", &elemento);
        if(elemento % 2 == 0){
            insertQ(par, elemento);
        } else {
            insertQ(impar, elemento);
        }        
        setbuf(stdin, NULL);
        printf("Deseja encerrar a programa? [y/n]: ");
        scanf("%c", &escolha);
    } while (escolha != 'y');

    printf("Fila Par\n");
    printQ(par);
    printf("\n\n");
    printf("Fila Impar\n");
    printQ(impar);
    printf("\n\n");
    printf("Fila Ordenada\n");
    printQ(concatena_filas(par, impar, completa));

    //clearQ(par);
    //clearQ(impar);
    //clearQ(completa);
    return 0;
}