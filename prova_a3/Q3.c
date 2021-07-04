#include<stdio.h>
#include"queue.h"

Tqueue *concatena_filas(Tqueue *pairs, Tqueue *odd, Tqueue *all){
    Tqueue *bkpPair = createQ();
    Tqueue *bkpOdd = createQ();
    Tqueue *auxPair = pairs, *auxOdd = odd;
    //int menor, maior, removido;
    int auxP1, auxI1;
    //int  auxP2, auxI2;

    /*
    while (!emptyQ(auxPair)){
        insertQ(auxiliar, removerQueueNode(auxPair));
    }
    while (!emptyQ(auxOdd)){
        insertQ(auxiliar, removerQueueNode(auxOdd));
    }
    */

    do{
        if(!emptyQ(auxPair)){
            auxP1 = removerQueueNode(auxPair);
        } else {
            while (!emptyQ(auxOdd)){
                insertQ(all, removerQueueNode(auxOdd));
            }
        }
        if(!emptyQ(auxOdd)){
            auxI1 = removerQueueNode(auxOdd);
        } else {
            while (!emptyQ(auxPair)){
                insertQ(all, removerQueueNode(auxPair));
            }
        }
    
        if(auxP1 < auxI1){
            insertQ(all, auxP1);
            insertQ(bkpOdd, auxI1);
            while (!emptyQ(auxOdd)){
                insertQ(bkpOdd, removerQueueNode(auxOdd));
            }
            while (!emptyQ(bkpOdd)){
                insertQ(auxOdd, removerQueueNode(bkpOdd));
            }           
        }
        if(auxP1 > auxI1){
            insertQ(all, auxI1);
            insertQ(bkpPair, auxP1);
            while (!emptyQ(auxPair)){
                insertQ(bkpPair, removerQueueNode(auxPair));
            }
            while (!emptyQ(bkpPair)){
                insertQ(auxPair, removerQueueNode(bkpPair));
            }
        }
    } while (!emptyQ(auxPair) && !emptyQ(auxOdd));    
    clearQ(auxPair);
    clearQ(auxOdd);
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

    
    clearQ(completa);
    return 0;
}