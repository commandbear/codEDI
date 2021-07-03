#include<stdio.h>
#include"queue.h"

Tqueue *concatena_filas(Tqueue *pairs, Tqueue *odd, Tqueue *all){
    Tqueue *auxiliar = all, *auxPair = pairs, *auxOdd = odd;

    while(!emptyQ(auxPair)){
        insertQ(auxiliar, removerQueueNode(auxPair));
    }
    while(!emptyQ(auxOdd)){
        insertQ(auxiliar, removerQueueNode(auxOdd));
    }

    clearQ(auxPair);
    clearQ(auxOdd);
    return auxiliar;
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