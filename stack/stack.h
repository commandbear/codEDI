#include <stdlib.h>
#include <stdio.h>

//cada elemento da pilha
typedef struct node{
    int info;
    struct node *next;
    
}Tnode;

typedef struct stack{
    Tnode *top; //topo da pilha
}Tstack;

Tstack *create(){
    Tstack *s = (Tstack *) malloc (sizeof(Tstack)); //alocando na memoria essa estrutura Tstack
    s->top = NULL; //ponteiro que aponta para o topo aponta que para vazio, pq a pilha está vazia
    return s;
}

//verifica se a pilha está vazia (1- VERDADEIRO/ 0- FALSO)
int empty(Tstack *s){
    return s->top == NULL;
}

//limpar a memória da pilha em si
void clear(Tstack *s){
    Tnode *r = s->top, *t;
    while(r){
        t = r; //ponteiro auxiliar t aponta para o ponteiro r, que por sua vez aponta para o topo da pilha.
        r = r->next; //reaponto o topo para o seu elemento imediatamente abaixo
        free(t); //liberar a memória ocupada pelo elemento (node) t
    }
    free(s); //liberar a memória da estrutura da pilha
}

//remove um elemento da pilha
int pop(Tstack *s){
    if(empty(s)){
        exit(1);
    }
    //novo ponteiro que aponta para o topo da pilha
    Tnode *t = s->top;
    //reapontar o topo da pilha para o elemento imediatamente abaixo
    s->top = s->top->next;
    int result = t->info;
    free(t);
    return result;
}

//insere um elemento na pilha
void push(Tstack *s, int element){
    Tnode *newNode = (Tnode *) malloc (sizeof(Tnode));
    newNode->info = element;
    newNode->next = s->top;
    s->top = newNode;
}

/* 
Pilha vazia: s->top = [20, [10, [5, NULL]]]


info = 10; next | -> | info = 5; next | -> | NULL
 ^
 |
TOP
Primeiro PUSH
 Push (s, 5);
 Novo elemento criado com:
 newNode -> info = 5;
 newNode -> next = NULL;
 s->top = [5, NULL];

Segundo PUSH
 Push (s, 10);
 Novo elemento criado com:
 newNode -> info = 10;
 newNode -> next = [5, NULL];
 s->top = [10, [5, NULL]];
 
Terceiro PUSH
 Push (s, 20);
 Novo elemento criado com:
 newNode -> info = 20;
 newNode -> next = [10, [5, NULL]];
 s->top = [20, [10, [5, NULL]]];
*/

void print_stack(Tstack *s){
    Tstack *t = create();
    int elem, counter = 1;

    while(!empty(s)){
        push(t, pop(s));
    }
    //ao fim do while, temos uma cópia invertida da pilha s na pilha t

    while(!empty(t)){
        elem = pop(t);
        printf("Elemento %d da pilha: %d\n", counter, elem);
        push(s, elem);
        counter++;
    }
    //ao fim do while, temos a pilha s repopulada com os seus elementos impressos na ordem correta
    
    clear(t);
}

void copy_stack(Tstack *s1, Tstack *s2){
    if(empty(s1)){
        exit(1);
    }
    if(!empty(s2)){
        exit(1);
    }

    Tstack *aux = create();
    int elem;

    while(!empty(s1)){
        push(aux, pop(s1));
    }
    while(!empty(aux)){
        elem = pop(aux);
        push(s1, elem);
        push(s2, elem);
    }
    clear(aux);
}