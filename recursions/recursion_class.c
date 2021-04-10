#include <stdio.h>

//Função Fatorial recursiva
double fat_rec (double n){ 
    if(n <= 1){ //caso base
        return 1;
    } else {
        return n * fat_rec(n - 1); //retorna o fatorial * fatorial de n - 1; Ex: 2! -> 2 * 1
    }
}

//Função Fatorial recursiva usando "Ternário"
double fat_recursive_ternary (double n){
    return (n <=1 ? 1 : n * fat_recursive_ternary(n-1));
}

//Função Fatorial Iterativa
double fat_it(double n){
    double result = 1;
    int counter;
    for(counter = n; counter > 1; counter--){ //para antes do 1 porque não ia fazer diferença multiplicar por 1
        result *= counter;
    }
    return result;
}

//Fibonacci Recursivo - retorna o elemento n da sequência de Fibonacci
double fibo_rec(double n){
    if(n <= 2){
        return 1;
    } else{
        return fibo_rec(n-1) + fibo_rec(n-2);
    }
}

int main(){
    double value;

    printf("Insert value to calc factorial and enesimal Fibonacci's number: ");
    scanf("%lf", &value);

    printf("Factorial with recursion without ternary: %.0lf\n", fat_rec(value));
    printf("Factorial with recursion and ternary: %.0lf\n", fat_recursive_ternary(value));
    printf("Factorial with iterativity: %.0lf\n", fat_it(value));
    printf("Fibonacci Recursive - %.0lfth element: %.0lf\n", value, fibo_rec(value));

    return 0;
}
