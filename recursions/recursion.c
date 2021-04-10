#include <stdio.h>

double fat_recursive (double n){
    if(n <= 1){
        return 1;
    }
    else {
        return n * fat_recursive(n - 1);
    }
}

double fat_ternary (double n){
    return (n <=1 ? 1 : n * fat_ternary(n-1));
}

double fat_itaractive (double n){
    double res = 1;
    int counter = n;
    for(counter = n; counter > 1; counter--){
        res *= counter;
    }
    return res;
}

double fib_rec(double n){
    if(n<=2){
        return 1;
    } else {
        return fib_rec(n-1) + fib_rec(n-2);
    }
}

double fib_iteractive (double n){
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
    printf("Insert the value to calc the fibonacci:");
    scanf("%lf", &value);

    printf("Recursive Factorial without Ternary: %.0lf\n", fat_recursive(value));
    printf("Recursive Factorial with Ternary: %.0lf\n", fat_ternary(value));
    printf("Fibonacci Recursive: %.0lf\n", fib_rec(value));
    printf("Fibonacci Iteractive: %.0lf\n", fib_iteractive(value));
    return 0;
}
