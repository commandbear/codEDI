#include<stdio.h>
#include<stdlib.h>

typedef struct queueNode{
    int info;
    struct queueNode *next;
}TqueueNode;

typedef struct queue{
    TqueueNode *start, *end;
} Tqueue;

Tqueue *createQ(){
    Tqueue *q = (Tqueue *) malloc(sizeof(Tqueue));

    q->start = q->end = NULL;

    return q;
}

int emptyQ(Tqueue *q){
    return !q->end;
}

void insertQ(Tqueue *q, int element){
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

int removerQueueNode(Tqueue *q){
    if(emptyQ(q)){
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

void clearQ(Tqueue *q){
    TqueueNode *p = q->start, *aux;
    while(p){
        aux = p;
        p=aux->next;
        free(aux);
    }
    free(q);
}

void printQ(Tqueue *q){
    Tqueue *p;
    p = createQ();
    int value;

    if(emptyQ(q)){
        printf("Fila vazia\n");
        //exit(1);
    }

    while(!emptyQ(q)){
        value = removerQueueNode(q);
        printf("%d -> ", value);
        insertQ(p, value);
    }

    while (!emptyQ(p)){
        value = removerQueueNode(p);
        insertQ(q, value);
    }
    printf("\n");

    clearQ(p);
}