#include<stdio.h>
#include<stdlib.h>
#include"lists.h"
#include<windows.h> //para usar o Sleep(2000) => foi para testar se com multiplas repetições apareceriam números iguais.

//completa
Tlist *mega_sena(){
    Tlist *balls = create(), *numbers = create(), *found = create();
    time_t t;
    int i, r;

    srand((unsigned) time(&t));

    for(i=1; i<=TOT_ELEM; i++){
        numbers = ordered_insert(numbers, i);
    }
    //print_list(numbers); [1]->[60]
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
    //print_list(numbers); //-> lista sem os números sorteados 
    
    //clear(balls);
    clear(numbers);
    //clear(found);
    return balls;
}
int main(){
    Tlist *sorteio = create();
    
    //for(int i = 0; i<=2; i++){
        sorteio = mega_sena();
        printf("\n******MEGA-SENA SORTEADA******\n");
        print_list(sorteio);
        printf("*****************************\n");
        //Sleep(2000);
    //}

    clear(sorteio);
    return 0;
}