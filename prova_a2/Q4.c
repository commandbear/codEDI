#include<stdio.h>
#include<stdlib.h>
#include"lists.h"

int main(){
    Tlist *sorteio;
    
    sorteio = mega_sena();

    printf("\n******MEGA-SENA SORTEADA******\n");
    print_list(sorteio);
    printf("*****************************\n");

    clear(sorteio);
    return 0;
}