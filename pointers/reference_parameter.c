//Exemplo de passagem de parâmetros por referencia (Ponteiro)
#include <stdio.h>

int func (int *a){
    printf("PRINT FUNCTION: %d\n", *a); //10
    *a = 20;
    int b = 15;
    return *a + b; // função retorna 35
}
int main(){
    int value = 10;
    printf("PRINT 1: %d\n", value); //10
    int result = func (&value); // 35 - passa o endereço de memoria da variavel value como parametro (passagem por parâmetro)
    printf("PRINT 2: %d\n", value); //20
    printf("Function's return: %d", result); //35
    return 0;
}