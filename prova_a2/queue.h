#include<stdio.h>
#include<stdlib.h>

typedef struct queueNode{
    int info;
    struct queueNode *next;
}TqueueNode;

typedef struct queue{
    TqueueNode *start, *end;
} Tqueue;

Tqueue *queueCreator(){
    Tqueue *q = (Tqueue *) malloc(sizeof(Tqueue));

    q->start = q->end = NULL;

    return q;
}

int emptyQueue(Tqueue *q){
    return !q->end;
}

void insertInQueue(Tqueue *q, int element){
    TqueueNode *queueNode = (TqueueNode *)malloc(sizeof(TqueueNode));

    queueNode->info = element;
    queueNode->next = NULL;

    if(q->end){
        q->end->next = queueNode;
    }

    q->end = queueNode;

    if(!q->start){
        q->start = queueNode;
    }
}

int remove_queueNode(Tqueue *q){
    if(emptyQueue(q)){
        exit(1);
    }

    int value = q->start->info;

    TqueueNode *p = q->start;

    q->start = q->start->next;

    if(!q->start){
        q->end = NULL;
    }

    free(p);

    return value;
}

void queueCleaner(Tqueue *q){
    TqueueNode *p = q->start, *aux;
    while(p){
        aux = p;
        p=aux->next;
        free(aux);
    }
    free(q);
}

void queuePrinter(Tqueue *q){
    Tqueue *p;
    p = queueCreator();
    int value;

    if(emptyQueue(q)){
        printf("Fila vazia\n");
        //exit(1);
    }

    printf("Fila -> ");
    while(!emptyQueue(q)){
        value = remove_queueNode(q);
        printf("[%d] ", value);
        insertInQueue(p, value);
    }

    while (!emptyQueue(p)){
        value = remove_queueNode(p);
        insertInQueue(q, value);
    }
    printf("\n");

    queueCleaner(p);
}