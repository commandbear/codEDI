#include<stdio.h>
#include<stdlib.h>

typedef struct stackNode{
    int info;
    struct stackNode *next;
}TstackNode;

typedef struct stack{
    TstackNode *top;
}Tstack;

Tstack *stackCreator(){
    Tstack *s = (Tstack *) malloc(sizeof(Tstack));
    s->top = NULL;
    return s;
}

int emptyStack(Tstack *s){
    return s->top == NULL;
}

void stackCleaner(Tstack *s){
    TstackNode *r = s->top, *t;
    while(r){
        t=r;
        r=r->next;
        free(t);
    }
    free(s);
}

int pop(Tstack *s){
    if(emptyStack(s)){
        exit(1);
    }
    TstackNode *t = s->top;
    s->top = s->top->next;
    int result = t->info;
    free(t);
    return result;
}

void push(Tstack *s, int element){
    TstackNode *newNode = (TstackNode *) malloc(sizeof(TstackNode));
    newNode->info = element;
    newNode->next = s->top;
    s->top = newNode;
}

void stackPrinter(Tstack *s){
    Tstack *t = stackCreator();
    int elem, counter = 1;

    if(emptyStack(s)){
        printf("Pilha vazia\n");
        //exit(1);
    }

    while(!emptyStack(s)){
        push(t, pop(s));
    }
    printf("-------\n Pilha\n-------\n");
    while(!emptyStack(t)){
        elem = pop(t);
        //printf("Elemento %d da pilha: %d\n", counter, elem);
        printf("[%d]\n", elem);
        push(s, elem);
        counter++;
    }
    stackCleaner(t);
}

void copyStack(Tstack *s1, Tstack *s2){
    Tstack *aux = stackCreator();
    int elem;    
    
    if(emptyStack(s1)){
        exit(1);
    }
    if(!emptyStack(s2)){
        exit(1);
    }

    while(!emptyStack(s1)){
        push(aux, pop(s1));
    }
    while(!emptyStack(aux)){
        elem = pop(aux);
        push(s1, elem);
        push(s2, elem);
    }
    stackCleaner(aux);
}