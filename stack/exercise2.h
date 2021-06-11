#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int info;
    struct node *next;    
}Tnode;

typedef struct stack{
    Tnode *top;
}Tstack;

Tstack *create(){
    Tstack *s = (Tstack *) malloc (sizeof(Tstack));
    s->top = NULL;
    return s;
}

int empty(Tstack *s){
    return s->top == NULL;
}

void clear(Tstack *s){
    Tnode *r = s->top, *t;
    while(r){
        t = r;
        r = r->next;
        free(t);
    }
    free(s);
}

int pop(Tstack *s){
    if(empty(s)){
        exit(1);
    }
    Tnode *t = s->top;
    s->top = s->top->next;
    int result = t->info;
    free(t);
    return result;
}

void push(Tstack *s, int element){
    Tnode *newNode = (Tnode *) malloc (sizeof(Tnode));
    newNode->info = element;
    newNode->next = s->top;
    s->top = newNode;
}

void print_stack(Tstack *s){
    Tstack *t = create();
    int elem, counter = 1;

    while (!empty(s)){
        push(t, pop(s));
    }
    while (!empty(t)){
        elem = pop(t);
        printf("Elemento %d da pilha: %d\n", counter, elem);
        push(s, elem);
        counter++;
    }
    clear(t);
}

void separate_stacks(Tstack *s, Tstack *s_pairs, Tstack *s_odds){
    Tstack *aux = create();
    int elem;
    while (!empty(s)){
        push(aux, pop(s)); //ao fim deste while, a pilha s estará vazia, e a auxiliar estará com todos os elementos em ordem inversa
    }
    while (!empty(aux)){
        elem = pop(aux);
        push(s, elem);
        if(elem % 2 == 0){
            push(s_pairs, elem);
        } else {
            push(s_odds, elem);
        }
    } //ao fim do while, a pilha s estará como antes; a s_pairs com os elementos pares; a s_odds com os ímpares; e a pilha aux estará vazia
    clear(aux);
}