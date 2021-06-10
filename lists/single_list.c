#include<stdio.h>
#include "single_list.h"

int main(){
    int value, i;
    Tlist *list;
    list = create();

    for(i=1; i<=4; i++){
        printf("Insira um elemento: ");
        scanf("%d", &value);
        list = ordered_insert(list, value);
    }

    print_list(list);

    clear(list);

    return 0;
}