#include<stdio.h>
#include<stdlib.h>
#include"lists.h"
#include<windows.h>
/*
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
*/
int main(){
    Tlist *sorteio = create();
    
    sorteio = mega_sena();

    //for(int i = 1; i <= 30; i++){
        //sorteio = mega_sena();
        printf("\n******MEGA-SENA SORTEADA******\n");
        print_list(sorteio);
        printf("*****************************\n");
        //Sleep(2000);
    //}    

    clear(sorteio);
    return 0;
}