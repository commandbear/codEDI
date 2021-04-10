/**/
#include<stdio.h>

//1 1 2 3 5 8 13 21 34 55...
double fib_rec(double n){
    if(n <=2){
        return 1;
    }
    else{
        return fib_rec(n-1) + fib_rec(n-2);
    }
}

/*Ternario: existe uma condição e se essa condição 
for verdadeira, eu retorno o elemento a esquerda do 
dois pontos; e se for falsa retorna o elemento a direita*/
double fib_ternary(double n){
    return (n <=2 ? 1 : fib_ternary(n-1) + fib_ternary(n-2));
}

//Explicação do Iterativo: 1h:11:10m - Aula 5
double fib_iterativo(double n){
    if (n<=2){
        return 1;
    }
    
    double penult = 1, last = 1, current = 2, counter, aux; //explicação current: 1h:05:32m - Aula 5
    
    for(counter = 3; counter < n; counter++){
        aux = last;
        current += last;    
        last += penult;
        penult = aux;
    }
    return current;
}

int main(){
    double value;
    printf("Insira o enesimo elemento de Fibonacci a ser calculado: ");
    scanf("%lf", &value);

    printf("FIBONACCI RECURSIVO - ENESIMO TERMO: %.0lf\n", fib_rec(value));
    printf("FIBONACCI RECURSIVO TERNARY - ENESIMO TERMO: %.0lf\n", fib_ternary(value));
    printf("FIBONACCI ITERATIVO - ENESIMO TERMO: %.0lf\n", fib_iterativo(value));

    return 0;
}