//Exemplo de passagem de parâmetros por valor
#include <stdio.h>

int func (int a){
    printf("PRINT FUNCTION: %d\n", a); //10
    a = 20;
    int b = 15;
    return a + b; // função retorna 35
}
int main(){
    int value = 10;
    printf("PRINT 1: %d\n", value); //10
    int result = func (value); // 35 - passa o valor contido na variavel value como valor (passagem por valor)
    printf("PRINT 2: %d", value); //10
    printf("Function's return: %d", result);
    return 0;
}