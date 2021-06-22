#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int info;
    struct node *next;
}Tnode;

typedef struct queue{
    Tnode *start, *end;
} Tqueue;

Tqueue *createQueue(){
    Tqueue *q = (Tqueue *) malloc(sizeof(Tqueue));

    q->start = q->end = NULL;

    return q;
}

int emptyQueue(Tqueue *q){
    return !q->end;
}

void insertInQueue(Tqueue *q, int element){
    Tnode *node = (Tnode *)malloc(sizeof(Tnode));

    node->info = element;
    node->next = NULL;

    if(q->end){
        q->end->next = node;
    }

    q->end = node;

    if(!q->start){
        q->start = node;
    }
}

int remove_node(Tqueue *q){
    if(emptyQueue(q)){
        exit(1);
    }

    int value = q->start->info;

    Tnode *p = q->start;

    q->start = q->start->next;

    if(!q->start){
        q->end = NULL;
    }

    free(p);

    return value;
}

void queueCleaner(Tqueue *q){
    Tnode *p = q->start, *aux;
    while(p){
        aux = p;
        p=aux->next;
        free(aux);
    }
    free(q);
}

void printQueue(Tqueue *q){
    Tqueue *p;
    p = createQueue();
    int value;

    while(!emptyQueue(q)){
        value = remove_node(q);
        printf("%d", value);
        insertInQueue(p, value);
    }

    while (!emptyQueue(p)){
        value = remove_node(p);
        insertInQueue(q, value);
    }
    printf("\n");

    clear(p);
}