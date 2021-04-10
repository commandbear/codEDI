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

}

double fib_rec(double n){
    if(n<=2){
        return 1;
    } else {
        return fib_rec(n-1) + fib_rec(n-2);
    }
}

int main(){

    double value;
    //printf("Insert the value to calc the fatorial:");
    printf("Insert the value to calc the fibonacci:");
    scanf("%lf", &value);

    //printf("Fatorial with Recursion without Ternaty: %lf\n", fat_recursive(value));
    //printf("Fatorial with Recursion withou Ternaty:");
    printf("Fibonacci Recursive: %lf\n", fib_rec(value));
    return 0;
}
