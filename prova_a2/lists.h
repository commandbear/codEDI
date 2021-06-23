#include<stdlib.h>
#include<stdio.h>
#define TOT_ELEM 60

typedef struct list{
    int info;
    struct list *next;    
} Tlist;

Tlist *create(){
    return NULL;
}

Tlist *ordered_insert (Tlist *l, int elem){
    Tlist *p = l;
    Tlist *newElem;
    Tlist *previous = NULL;

    while (p != NULL && p->info <= elem){
        previous = p;
        p = p->next;
    }

    newElem = (Tlist *) malloc (sizeof(Tlist));
    newElem->info = elem;

    if(previous == NULL){
        newElem->next = l;
        l = newElem;
    } else {
        newElem->next = p;
        previous->next = newElem;
    }

    return l;
}

void print_list (Tlist *l){
    Tlist *p = l;

    while (p != NULL){
        printf("[%d] ", p->info);
        p = p->next;
    }
    printf("\n");
}

void clear(Tlist *l){
    Tlist *p = l;

    while (p){
        Tlist *q = p;
        p = p->next;
        free(q);
    }
}

Tlist *search (Tlist *l, int elem){
    Tlist *p = l;
    while(p){
        if(p->info != elem){
            p = p->next;
        } else {
            return p;
        }
    }
    return p;
}

Tlist *remove_elem (Tlist *l, int elem){
    Tlist *previous = NULL, *p = l;

    while ((p != NULL) && (p->info != elem)){
        previous = p;
        p = p->next;
    }
    if(!p){
        return l;
    }
    if(!previous){
        l = l->next;
    } else {
        previous->next = p->next;
    }
    free(p);
    return l;
} 

Tlist *mega_sena(){
    Tlist *balls = create(), *numbers = create(), *found = create();
    time_t t;
    int i, r;

    srand((unsigned) time(&t));

    for(i=1; i<=TOT_ELEM; i++){
        numbers = ordered_insert(numbers, i);
    }

    i = 1; 
    do{
        r = (1 + rand() % TOT_ELEM);
        found = search(numbers, r);
        if(found){
            balls = ordered_insert(balls, found->info);
            i++;
        }
        numbers = remove_elem(numbers, r);
    } while (i <=6);
    
    //clear(balls);
    clear(numbers);
    clear(found);
    return balls;
}
