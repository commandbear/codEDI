#include<stdio.h>
#include<stdlib.h>
#include"lists.h"
#include<windows.h>

int main(){
    Tlist *sorteio;
    
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